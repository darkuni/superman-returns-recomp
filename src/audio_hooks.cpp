// Hooks on EA's audio mixer (Superman Returns 454107ED).
//
// The mixer object (global at 0x8299FDC8, built by sub_8264C958) owns a command
// buffer: base +0x20, capacity in bytes +0x24, write offset +0x28, high-water
// +0x2C. Game threads push commands ({handler, object, args...}); the DSP update
// (sub_8264C540) runs them under the mixer lock and resets the offset to 0.
// The producers never check the capacity.
//
// Tests 2-4 all died from commands written where they shouldn't be: at guest
// 0x0000000C (buffer pointer NULL), and over the voice list (a voice's XMA
// context read back as NULL, then as 0x8264CE28 - the reverb command handler).
// Flight changes the reverb every frame, which is when audio died.
//
// These hooks forward to the recompiled code unchanged unless a push would land
// outside a live mixer's buffer; that push is dropped and logged once per kind.
// They also log the mixer's lifecycle and how full the buffer gets, so a log
// shows whether the cause is overflow (DSP updates too far apart) or the engine
// being torn down while game code still holds on to it.

#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <thread>

#include <rex/hook.h>

#include "ea_track.h"
#include <rex/logging.h>

extern "C" REX_FUNC(__imp__sub_8264CE48);  // reverb parameter push (16 bytes)
extern "C" REX_FUNC(__imp__sub_82661FC0);  // effect parameter push (24 bytes)
extern "C" REX_FUNC(__imp__sub_8264C540);  // DSP update: drains the command buffer
extern "C" REX_FUNC(__imp__sub_8264C958);  // mixer init
extern "C" REX_FUNC(__imp__sub_8264C6D0);  // mixer shutdown
extern "C" REX_FUNC(__imp__sub_82335E28);  // whole sound system teardown

namespace {
constexpr uint32_t kMixerGlobal = 0x8299FDC8;

uint32_t rd32(const uint8_t* base, uint32_t addr) {
  uint32_t v;
  __builtin_memcpy(&v, base + addr, 4);
  return __builtin_bswap32(v);
}

uint32_t lr_of(const PPCContext& ctx) { return static_cast<uint32_t>(ctx.lr); }

struct Once {
  std::atomic<bool> fired{false};
  bool first() { return !fired.exchange(true); }
};

// True when a push of `size` bytes from the object in r3 lands inside the live mixer's buffer.
bool push_ok(PPCContext& ctx, uint8_t* base, uint32_t size, const char* what) {
  static Once dead, mismatch, nobuf, full;
  const uint32_t obj = ctx.r3.u32;
  const uint32_t mixer = obj ? rd32(base, obj + 4) : 0;
  const uint32_t live = rd32(base, kMixerGlobal);
  if (!mixer || !live) {
    if (dead.first())
      REXAPU_WARN("[mixer] {} push with no live mixer (object {:08X} mixer {:08X} live {:08X}) "
                  "from {:08X} - dropped (logged once)",
                  what, obj, mixer, live, lr_of(ctx));
    return false;
  }
  if (mixer != live) {
    if (mismatch.first())
      REXAPU_WARN("[mixer] {} push to stale mixer {:08X} (live {:08X}) from {:08X} - dropped "
                  "(logged once)",
                  what, mixer, live, lr_of(ctx));
    return false;
  }
  const uint32_t buf = rd32(base, mixer + 0x20);
  const uint32_t cap = rd32(base, mixer + 0x24);
  const uint32_t off = rd32(base, mixer + 0x28);
  if (!buf) {
    if (nobuf.first())
      REXAPU_WARN("[mixer] {} push but the command buffer is NULL (mixer {:08X}) from {:08X} - "
                  "dropped (logged once)",
                  what, mixer, lr_of(ctx));
    return false;
  }
  if (off + size > cap) {
    if (full.first())
      REXAPU_WARN("[mixer] command buffer FULL: {} push at offset {} of {} bytes (mixer {:08X}) "
                  "from {:08X} - dropped, would have overwritten the memory after it (logged once)",
                  what, off, cap, mixer, lr_of(ctx));
    return false;
  }
  return true;
}

using Clock = std::chrono::steady_clock;
int64_t now_us() {
  return std::chrono::duration_cast<std::chrono::microseconds>(Clock::now().time_since_epoch())
      .count();
}
std::atomic<int64_t> g_last_update_us{0};
std::atomic<int64_t> g_update_enter_us{0};  // non-zero while a DSP update is running
std::atomic<uint32_t> g_update_lr{0};
std::atomic<uint32_t> g_mixer{0};
std::atomic<uint32_t> g_high_water{0};
std::atomic<int> g_gap_logs{0};
std::atomic<bool> g_watchdog_started{false};
uint8_t* g_base = nullptr;
}  // namespace

// Set by the XMADisableContext guard (src/xma_guard.cpp) while a call is in progress.
std::atomic<int64_t> g_xma_disable_enter_us{0};
std::atomic<uint32_t> g_xma_disable_ctx{0};
std::atomic<uint32_t> g_xma_disable_lr{0};
std::atomic<uint32_t> g_xma_disable_wait{0};

// Last DSP update time, read by the keep-alive in src/audio_diag.cpp.
std::atomic<int64_t> g_dsp_last_update_us{0};
void ea_audio_stall_report(uint8_t* base);  // src/audio_diag.cpp

// Counted by src/audio_pacing.cpp: render callbacks, frames the game submitted, silence fills.
extern std::atomic<uint64_t> g_pacing_callbacks;
extern std::atomic<uint64_t> g_submits;
extern std::atomic<uint64_t> g_filled;

namespace {
// Reports, once per episode, a DSP update stuck inside (blocked - the mixer lock?), DSP
// updates no longer arriving (render callback not called), or an XMADisableContext that
// does not return. That is what separates a deadlock from a stalled audio driver.
void watchdog() {
  bool stuck = false, starved = false, disabling = false, repeat_done = false,
       drained_logged = false;
  int64_t episode_start = 0;
  for (;;) {
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    const int64_t now = now_us();
    const uint32_t mixer = g_mixer.load();
    const uint32_t off = (mixer && g_base) ? rd32(g_base, mixer + 0x28) : 0;
    const uint32_t cap = (mixer && g_base) ? rd32(g_base, mixer + 0x24) : 0;

    const int64_t enter = g_update_enter_us.load();
    if (enter && now - enter > 1000000) {
      if (!stuck) {
        stuck = true;
        REXAPU_WARN("[mixer] watchdog: a DSP update (called from {:08X}) has been running for {} ms "
                    "- blocked inside (mixer lock?). Command buffer {} of {} bytes",
                    g_update_lr.load(), (now - enter) / 1000, off, cap);
      }
    } else if (stuck) {
      stuck = false;
      REXAPU_WARN("[mixer] watchdog: DSP update returned");
    }

    const int64_t last = g_last_update_us.load();
    if (!enter && last && now - last > 1000000) {
      if (!starved) {
        starved = true;
        episode_start = last;
        REXAPU_WARN("[mixer] watchdog: no DSP update for {} ms. Command buffer {} of {} bytes. "
                    "So far: {} render callbacks, {} game frames, {} silence fills",
                    (now - last) / 1000, off, cap, g_pacing_callbacks.load(), g_submits.load(),
                    g_filled.load());
        if (g_base) ea_audio_stall_report(g_base);
      }
    } else if (starved && last > episode_start) {
      starved = false;
      repeat_done = false;
      REXAPU_WARN("[mixer] watchdog: DSP updates resumed after {} ms ({} render callbacks, {} game "
                  "frames, {} silence fills so far)",
                  (last - episode_start) / 1000, g_pacing_callbacks.load(), g_submits.load(),
                  g_filled.load());
    }
    if (starved && !repeat_done && now - episode_start > 5000000) {
      repeat_done = true;
      REXAPU_WARN("[mixer] watchdog: still no DSP update after {} ms - second report:",
                  (now - episode_start) / 1000);
      if (g_base) ea_audio_stall_report(g_base);
    }
    // Audio is already dead while DSP updates are stalled; the queued commands will never
    // run. Empty the buffer before it overflows into the memory after it (that overflow is
    // what crashed tests 2-7 - one 8-byte push sits inside a function and can't be guarded).
    if (starved && mixer && g_base && cap && off > cap / 10 * 9) {
      const uint32_t zero = 0;
      std::memcpy(g_base + mixer + 0x28, &zero, 4);
      if (!drained_logged) {
        drained_logged = true;
        REXAPU_WARN("[mixer] watchdog: command buffer {}% full with DSP updates stalled - emptied it "
                    "so it can't overflow (logged once)",
                    uint64_t(off) * 100 / cap);
      }
    }

    const int64_t dis = g_xma_disable_enter_us.load();
    if (dis && now - dis > 500000) {
      if (!disabling) {
        disabling = true;
        REXAPU_WARN("[mixer] watchdog: XMADisableContext({:08X}, wait={}) from {:08X} has not "
                    "returned after {} ms",
                    g_xma_disable_ctx.load(), g_xma_disable_wait.load(), g_xma_disable_lr.load(),
                    (now - dis) / 1000);
      }
    } else if (disabling) {
      disabling = false;
      REXAPU_WARN("[mixer] watchdog: that XMADisableContext returned");
    }
  }
}
}  // namespace

extern "C" REX_FUNC(sub_8264CE48) {
  if (!push_ok(ctx, base, 16, "reverb")) return;
  __imp__sub_8264CE48(ctx, base);
}

extern "C" REX_FUNC(sub_82661FC0) {
  if (!push_ok(ctx, base, 24, "effect")) return;
  __imp__sub_82661FC0(ctx, base);
}

extern "C" REX_FUNC(sub_8264C540) {
  const uint32_t mixer = ctx.r3.u32;
  if (mixer) {
    g_base = base;
    g_mixer = mixer;
    const uint32_t cap = rd32(base, mixer + 0x24);
    const uint32_t off = rd32(base, mixer + 0x28);
    // Log each time the buffer reaches a new high of 25 % / 50 % / 75 % / 90 % of capacity.
    if (cap) {
      const uint32_t pct = static_cast<uint32_t>(uint64_t(off) * 100 / cap);
      uint32_t prev = g_high_water.load();
      for (uint32_t mark : {25u, 50u, 75u, 90u}) {
        if (pct >= mark && prev < mark && g_high_water.compare_exchange_strong(prev, mark)) {
          REXAPU_WARN("[mixer] command buffer reached {}% ({} of {} bytes) before a DSP update", mark,
                      off, cap);
        }
      }
    }
    const int64_t now = now_us();
    const int64_t last = g_last_update_us.exchange(now);
    if (last && now - last > 100000 && g_gap_logs.fetch_add(1) < 10) {
      REXAPU_WARN("[mixer] {} ms since the previous DSP update (buffer at {} of {} bytes) "
                  "(first 10 logged)",
                  (now - last) / 1000, off, cap);
    }
  }
  g_update_lr = lr_of(ctx);
  g_update_enter_us = now_us();
  EaScope scope(0x8264C540);
  __imp__sub_8264C540(ctx, base);
  g_update_enter_us = 0;
  g_last_update_us = now_us();
  g_dsp_last_update_us = g_last_update_us.load();
}

extern "C" REX_FUNC(sub_8264C958) {
  const uint32_t lr = lr_of(ctx);
  __imp__sub_8264C958(ctx, base);
  const uint32_t mixer = rd32(base, kMixerGlobal);
  REXAPU_INFO("[mixer] init from {:08X}: mixer {:08X}, command buffer {:08X}, {} bytes", lr, mixer,
              mixer ? rd32(base, mixer + 0x20) : 0, mixer ? rd32(base, mixer + 0x24) : 0);
  g_high_water = 0;
  g_base = base;
  g_mixer = mixer;
  g_last_update_us = now_us();  // watchdog measures from init until the first DSP update
  g_dsp_last_update_us = g_last_update_us.load();
  if (mixer && !g_watchdog_started.exchange(true)) std::thread(watchdog).detach();
}

extern "C" REX_FUNC(sub_8264C6D0) {
  const uint32_t mixer = ctx.r3.u32;
  REXAPU_WARN("[mixer] SHUTDOWN of mixer {:08X} from {:08X} (high-water {} of {} bytes)", mixer,
              lr_of(ctx), mixer ? rd32(base, mixer + 0x2C) : 0, mixer ? rd32(base, mixer + 0x24) : 0);
  __imp__sub_8264C6D0(ctx, base);
}

extern "C" REX_FUNC(sub_82335E28) {
  REXAPU_WARN("[mixer] sound system teardown (sub_82335E28) from {:08X}", lr_of(ctx));
  __imp__sub_82335E28(ctx, base);
}
