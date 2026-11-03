// EA audio thread <-> XAudio2 voice: diagnostics and keep-alive (Superman Returns 454107ED).
//
// Test 6 showed the render callback (821209F0 - the XAudio2 library's engine
// tick) never stopped and never skipped a frame, yet DSP updates stopped when
// the flight cinematic started. EA's audio thread (sub_82650B78) is what runs
// the DSP update: each pass it waits (KeWaitForSingleObject, no timeout) on the
// event at obj+0x30A0, which only the XAudio2 voice callbacks set -
// sub_826509E8 (processing pass) and sub_82650A08 (buffer end). XAudio2 kept
// ticking but stopped calling that voice back, so the thread slept forever, the
// mixer's command buffer filled, and the overflow corrupted the voices.
//
// Keep-alive: if the engine is running and no DSP update has happened for
// 30 ms, free the loop's current buffer slot and set its event from the XAudio2
// tick (src/audio_pacing.cpp). The thread runs a pass - the DSP update drains
// the mixer's command buffer - and waits again. Setting the event alone is not
// enough: a pass is skipped while the slot is still marked in use.
//
// Diagnostics, reported by the watchdog when a stall starts: counts of the two
// voice callbacks, the XAudio2 wrapper calls (0x82116xxx) EA made in the 3 s
// before, and any XMA context with an error flag (src/xma_guard.cpp).

#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstring>

#include <rex/hook.h>
#include <rex/logging.h>

extern "C" REX_FUNC(__imp__sub_82650B78);  // EA audio thread loop
extern "C" REX_FUNC(__imp__sub_826509E8);  // voice callback: processing pass -> SetEvent
extern "C" REX_FUNC(__imp__sub_82650A08);  // voice callback: buffer end -> slot free + SetEvent
extern "C" REX_FUNC(__imp__sub_82116998);  // KeSetEvent(event, 0, 0)
extern "C" REX_FUNC(__imp__sub_82118068);  // XAudio2: after-pass work
extern "C" REX_FUNC(__imp__sub_82118750);  // XAudio2: timer routine, sets the abort event

namespace {
constexpr uint32_t kRunningFlag = 0x8299FDD4;  // byte: EA audio thread keeps looping while set

uint32_t rd32(const uint8_t* base, uint32_t addr) {
  uint32_t v;
  std::memcpy(&v, base + addr, 4);
  return __builtin_bswap32(v);
}
int64_t now_us() {
  return std::chrono::duration_cast<std::chrono::microseconds>(
             std::chrono::steady_clock::now().time_since_epoch())
      .count();
}

std::atomic<uint32_t> g_ea_obj{0};
std::atomic<uint64_t> g_pass_cb{0}, g_end_cb{0}, g_kicks{0};
std::atomic<int64_t> g_last_pass_us{0}, g_last_end_us{0};
std::atomic<uint64_t> g_xa_after{0}, g_xa_timer{0};
std::atomic<int64_t> g_xa_after_us{0}, g_xa_timer_us{0};
// XAudio2 engine statics: tick event (processing thread waits on it), done event (the tick
// waits on it), abort event (manual reset, set by the timer routine), engine pointer.
constexpr uint32_t kXaTick = 0x829AC0B8, kXaDone = 0x829AC094, kXaAbort = 0x829AC0D8,
                   kXaEngine = 0x829AC104;

struct WrapStat {
  uint32_t addr;
  std::atomic<uint64_t> calls{0};
  std::atomic<int64_t> last_us{0};
  std::atomic<uint32_t> last_lr{0};
};

#define XA_LIST(X)                                                                              \
  X(821160A0) X(821160F8) X(82116168) X(821161D0) X(821162E8) X(82116350) X(821163B8)          \
  X(82116410) X(821164B8) X(82116518) X(82116590) X(821165D8) X(82116630) X(82116698)          \
  X(82116718) X(82116828) X(821168A8) X(82116908) X(82116A00) X(82116B70) X(82116BD8)          \
  X(82116C50) X(82116CE0) X(82116D68) X(82116E50) X(82116ED8) X(82116F60) X(82117018)          \
  X(82117120) X(821171F8) X(821172C8) X(821172F8)

#define XA_COUNT(a) +1
constexpr int kWrapCount = 0 XA_LIST(XA_COUNT);
WrapStat g_wrap[kWrapCount];
}  // namespace

// Defined in src/audio_hooks.cpp.
extern std::atomic<int64_t> g_dsp_last_update_us;

// --- wrapper hooks ----------------------------------------------------------
#define XA_DECL(a) extern "C" REX_FUNC(__imp__sub_##a);
XA_LIST(XA_DECL)

namespace {
template <int I>
void note(uint32_t addr, uint32_t lr) {
  auto& s = g_wrap[I];
  s.addr = addr;
  ++s.calls;
  s.last_us = now_us();
  s.last_lr = lr;
}
}  // namespace

#define XA_HOOK_I(a, i)                                    \
  extern "C" REX_FUNC(sub_##a) {                           \
    note<i>(0x##a, static_cast<uint32_t>(ctx.lr));         \
    __imp__sub_##a(ctx, base);                             \
  }
namespace {
constexpr int idx(uint32_t a) {
  constexpr uint32_t addrs[] = {
#define XA_ADDR(a) 0x##a,
      XA_LIST(XA_ADDR)
#undef XA_ADDR
  };
  for (int i = 0; i < kWrapCount; i++)
    if (addrs[i] == a) return i;
  return -1;
}
}  // namespace
#define XA_HOOK(a) XA_HOOK_I(a, idx(0x##a))
XA_LIST(XA_HOOK)

// --- EA audio thread and voice callbacks --------------------------------------
extern "C" REX_FUNC(sub_82650B78) {
  g_ea_obj = ctx.r3.u32;
  REXAPU_WARN("[ea-audio] audio thread loop started (object {:08X}, wait event {:08X})",
              ctx.r3.u32, rd32(base, ctx.r3.u32 + 0x30A0));
  __imp__sub_82650B78(ctx, base);
  REXAPU_WARN("[ea-audio] audio thread loop exited");
}

extern "C" REX_FUNC(sub_826509E8) {
  ++g_pass_cb;
  g_last_pass_us = now_us();
  __imp__sub_826509E8(ctx, base);
}

extern "C" REX_FUNC(sub_82650A08) {
  ++g_end_cb;
  g_last_end_us = now_us();
  __imp__sub_82650A08(ctx, base);
}

extern "C" REX_FUNC(sub_82118068) {
  ++g_xa_after;
  g_xa_after_us = now_us();
  __imp__sub_82118068(ctx, base);
}

extern "C" REX_FUNC(sub_82118750) {
  const uint64_t n = ++g_xa_timer;
  g_xa_timer_us = now_us();
  if (n <= 5) {
    REXAPU_WARN("[xaudio2] timer routine called (object {:08X}) - may set the abort event "
                "(#{}; first 5 logged)",
                ctx.r3.u32, n);
  }
  __imp__sub_82118750(ctx, base);
}

// --- called from the XAudio2 tick (src/audio_pacing.cpp) ----------------------
void ea_audio_keepalive(PPCContext& ctx, uint8_t* base) {
  const uint32_t obj = g_ea_obj.load();
  if (!obj || !base[kRunningFlag]) return;
  const int64_t last = g_dsp_last_update_us.load();
  if (!last || now_us() - last < 30000) return;
  const uint32_t event = rd32(base, obj + 0x30A0);
  if (!event) return;
  // The loop skips a pass while its current buffer slot is still marked in use; only the
  // voice's buffer-end callback clears it. Clear it so the pass (and the DSP update) runs.
  const uint32_t cur = rd32(base, obj + 0x309C);
  if (cur < 2) std::memset(base + obj + (cur + 3157) * 4, 0, 4);
  const uint64_t n = ++g_kicks;
  if (n <= 3 || n % 1000 == 0) {
    REXAPU_WARN("[ea-audio] no DSP update for {} ms - setting the audio thread's event "
                "{:08X} (keep-alive #{}; first 3 and every 1000th logged)",
                (now_us() - last) / 1000, event, n);
  }
  PPCContext c = ctx;
  c.r3.u64 = event;
  __imp__sub_82116998(c, base);
}

// --- called from the watchdog (src/audio_hooks.cpp) ---------------------------
void xma_report_errors(uint8_t* base);  // src/xma_guard.cpp

void ea_audio_stall_report(uint8_t* base) {
  const int64_t now = now_us();
  const uint32_t obj = g_ea_obj.load();
  auto ago = [&](int64_t t) { return t ? (now - t) / 1000 : -1; };
  REXAPU_WARN("[ea-audio] stall report: running={} mode(+0x8E)={} slots(+0x3098/+0x309C)={}/{} | "
              "voice pass callbacks {} (last {} ms ago), buffer-end callbacks {} (last {} ms ago), "
              "keep-alive kicks {}",
              obj ? int(base[kRunningFlag]) : -1, obj ? int(base[obj + 0x8E]) : -1,
              obj ? rd32(base, obj + 0x3098) : 0, obj ? rd32(base, obj + 0x309C) : 0,
              g_pass_cb.load(), ago(g_last_pass_us.load()), g_end_cb.load(),
              ago(g_last_end_us.load()), g_kicks.load());
  const uint32_t engine = rd32(base, kXaEngine);
  REXAPU_WARN("[xaudio2] stall report: engine {:08X} +0x12C={:08X} +0x130={} | events "
              "tick(type {} signaled {}) done(type {} signaled {}) abort(type {} signaled {}) | "
              "processing passes(82116D68) {} after-pass(82118068) {} (last {} ms ago), timer "
              "routine {} (last {} ms ago)",
              engine, engine ? rd32(base, engine + 0x12C) : 0, engine ? rd32(base, engine + 0x130) : 0,
              int(base[kXaTick]), rd32(base, kXaTick + 4), int(base[kXaDone]), rd32(base, kXaDone + 4),
              int(base[kXaAbort]), rd32(base, kXaAbort + 4), g_wrap[idx(0x82116D68)].calls.load(),
              g_xa_after.load(), ago(g_xa_after_us.load()), g_xa_timer.load(), ago(g_xa_timer_us.load()));
  for (auto& s : g_wrap) {
    const int64_t t = s.last_us.load();
    const uint32_t lr = s.last_lr.load();
    if (t && now - t < 3000000) {
      REXAPU_WARN("[ea-audio]   XAudio2 wrapper {:08X}: {} calls, last {} ms ago from {:08X}",
                  s.addr, s.calls.load(), (now - t) / 1000, lr);
    }
  }
  xma_report_errors(base);
}
