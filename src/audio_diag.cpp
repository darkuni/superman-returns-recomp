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
#include <thread>

#include <rex/hook.h>

#include "ea_track.h"
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
}  // namespace

thread_local bool t_is_ea_audio = false;
std::atomic<uint32_t> g_ea_stack[kEaStackMax] = {};
std::atomic<int64_t> g_ea_stack_since[kEaStackMax] = {};
std::atomic<int> g_ea_depth{0};
std::atomic<uint64_t> g_ea_xma_calls{0};
int64_t ea_now_us() { return now_us(); }

namespace {
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
    EaScope scope(0x##a);                                  \
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

// --- EA audio thread call tracking (scopes only count on that thread) ---------
#define EA_TRACK_DECL(a) extern "C" REX_FUNC(__imp__sub_##a);
#define EA_TRACK_HOOK(a)          \
  extern "C" REX_FUNC(sub_##a) {  \
    EaScope scope(0x##a);         \
    __imp__sub_##a(ctx, base);    \
  }
// sub_8264C540 (DSP update) is hooked in src/audio_hooks.cpp; it calls ea_track_dsp().
#define EA_TRACKED_HERE(X) X(8265A148) X(82658958) X(8265AAD0) X(8265AB00) \
  X(82650810) X(825FC108) X(821169A8) X(8264C400) X(8264C410) X(8265A6C0)
EA_TRACKED_HERE(EA_TRACK_DECL)
EA_TRACKED_HERE(EA_TRACK_HOOK)

// The XMA stream reader: loops until its voices have produced the samples it needs. Test 8
// caught EA's audio thread spinning in here (440 million XMA calls in 5 s).
extern "C" REX_FUNC(__imp__sub_826592F0);
namespace {
std::atomic<uint32_t> g_reader_obj{0};
std::atomic<uint32_t> g_reader_need{0};
}  // namespace
namespace {
std::atomic<PPCContext*> g_reader_ctx{nullptr};  // EA thread's live registers while inside

// Who touches a reader: submit (826592A8, appends a stream chunk then feeds), feed (826586A0,
// moves queued chunks onto the voices' XMA input buffers), read (826592F0). On the console
// these share one hardware thread; here they can overlap on different host threads.
std::atomic<uint64_t> g_reader_owner{0};  // host thread id currently inside, 0 = none
std::atomic<uint32_t> g_reader_owner_fn{0}, g_reader_owner_obj{0};
std::atomic<uint64_t> g_reader_overlaps{0};
std::atomic<uint64_t> g_reader_calls_other[3] = {};
std::atomic<bool> g_reader_other_logged[3] = {};
thread_local int t_reader_depth = 0;
uint64_t thread_key() {
  static std::atomic<uint64_t> next{1};
  thread_local uint64_t key = next++;
  return key;
}

struct ReaderAccess {
  bool owned = false;
  ReaderAccess(int which, uint32_t fn, uint32_t obj, uint32_t lr) {
    if (!t_is_ea_audio) {
      ++g_reader_calls_other[which];
      if (!g_reader_other_logged[which].exchange(true)) {
        REXAPU_WARN("[ea-audio] reader sub_{:08X} also runs on another thread (thread #{}, reader "
                    "{:08X}, from {:08X}) - first time",
                    fn, thread_key(), obj, lr);
      }
    }
    if (t_reader_depth++ > 0) return;
    uint64_t expected = 0;
    if (g_reader_owner.compare_exchange_strong(expected, thread_key())) {
      owned = true;
      g_reader_owner_fn = fn;
      g_reader_owner_obj = obj;
    } else {
      const uint64_t n = ++g_reader_overlaps;
      if (n <= 10 || n % 10000 == 0) {
        REXAPU_WARN("[ea-audio] reader race #{}: thread #{} entered sub_{:08X} (reader {:08X}) while "
                    "thread #{} is inside sub_{:08X} (reader {:08X})",
                    n, thread_key(), fn, obj, expected, g_reader_owner_fn.load(),
                    g_reader_owner_obj.load());
      }
    }
  }
  ~ReaderAccess() {
    --t_reader_depth;
    if (owned) g_reader_owner = 0;
  }
};
}  // namespace

thread_local ReaderSpin t_reader_spin;
std::atomic<uint64_t> g_reader_breaks{0};

extern "C" REX_FUNC(sub_826592F0) {
  if (t_is_ea_audio) {
    g_reader_obj = ctx.r3.u32;
    g_reader_need = ctx.r5.u32;
    g_reader_ctx = &ctx;
  }
  t_reader_spin = ReaderSpin{};
  ReaderAccess access(2, 0x826592F0, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  EaScope scope(0x826592F0);
  __imp__sub_826592F0(ctx, base);
  if (t_is_ea_audio) g_reader_ctx = nullptr;
}

extern "C" REX_FUNC(__imp__sub_826592A8);
extern "C" REX_FUNC(sub_826592A8) {
  ReaderAccess access(0, 0x826592A8, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_826592A8(ctx, base);
}
extern "C" REX_FUNC(__imp__sub_826586A0);
extern "C" REX_FUNC(sub_826586A0) {
  ReaderAccess access(1, 0x826586A0, ctx.r3.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_826586A0(ctx, base);
}

void xma_dump_context(uint8_t* base, uint32_t c, const char* label);  // src/xma_guard.cpp

// Called by the XMAGetOutputBufferWriteOffset guard for the reader's per-voice poll (LR
// 0x826593F0), after the real call (ctx.r3 = write offset in 256-byte blocks).
//
// The reader retries a voice until it has r27 frames, and only clears its retry flag (r26)
// when a read succeeds. Two ways that never ends:
//  - r27 == 0: the reader's chunk queue ran dry mid-request (avail +0x24 == 0, ready queue
//    empty -> r20 forced to 0, r27 = min(r20, avail) = 0). A zero-frame read can't succeed,
//    and the feeder that would refill the queue only runs after the voice loop.
//  - the voice's XMA context stops producing while the reader waits on it.
// Break: r18 is the constant the retry flag is set from (li r18,1 per pass) - with r18 = 0
// and r26 = 0 the voice loop finishes; r20 = r27 makes the outer loop end too
// (r20 -= r27). The reader returns what it read so far (r19). r18 is non-volatile: the
// epilogue restores the caller's value.
namespace {
int64_t spin_now_us() { return now_us(); }
}  // namespace

void reader_spin_check(PPCContext& ctx, uint8_t* base, uint32_t xctx) {
  ReaderSpin& s = t_reader_spin;
  const uint32_t voice = ctx.r31.u32;
  const uint32_t pos = rd32(base, voice + 8);
  const uint32_t wr = ctx.r3.u32;
  const char* why = nullptr;
  if (ctx.r27.s32 <= 0) {
    why = "no stream data queued (reader ran dry)";
  } else {
    if (s.r23 != ctx.r23.u32 || s.pos != pos || s.wr != wr) {
      s.r23 = ctx.r23.u32;
      s.pos = pos;
      s.wr = wr;
      s.attempts = 0;
    }
    if (++s.attempts == 64) s.since = spin_now_us();
    if (s.attempts > 64) {
      std::this_thread::yield();
      if (spin_now_us() - s.since > 10000) why = "voice's XMA context produced nothing for 10 ms";
    }
  }
  if (!why) return;

  const uint32_t r = ctx.r28.u32;
  const uint64_t n = ++g_reader_breaks;
  if (n <= 12 || n % 1000 == 0) {
    REXAPU_WARN("[ea-audio] reader stall #{} broken: {} | reader {:08X} voice #{} entry {:08X} | "
                "need {} frames (r27), left {} (r20), read {} (r19), retry {} (r26) | voice pos {} "
                "skip {} ch {} | write offset {} blocks | avail +24 {} ready +30 {:08X} count +38 {} "
                "pending +0C {:08X} count +14 {} | +3C {:08X}",
                n, why, r, ctx.r23.u32, voice, ctx.r27.s32, ctx.r20.s32, ctx.r19.s32, ctx.r26.u32, pos,
                rd32(base, voice + 16), int(base[voice + 12]), wr, rd32(base, r + 0x24),
                rd32(base, r + 0x30), rd32(base, r + 0x38), rd32(base, r + 0x0C), rd32(base, r + 0x14),
                rd32(base, r + 0x3C));
    xma_dump_context(base, xctx, "      ");
  }
  // r29 is what the exit adds to the frames-read total (r19): nothing for a dry queue, the
  // whole request for a timed-out voice (avail +0x24 drops by r27 either way).
  ctx.r29.u64 = ctx.r27.s32 <= 0 ? 0 : ctx.r27.u64;
  ctx.r18.u64 = 0;
  ctx.r26.u64 = 0;
  ctx.r20.u64 = ctx.r27.u64;
  s = ReaderSpin{};
}

void xma_dump_context(uint8_t* base, uint32_t c, const char* label);  // src/xma_guard.cpp
void file_read_report();                                                // src/xma_guard.cpp

void reader_dump(uint8_t* base) {
  const uint32_t r = g_reader_obj.load();
  if (!r) return;
  auto w = [&](uint32_t a) { return rd32(base, a); };
  REXAPU_WARN("[ea-audio]   stream reader object {:08X} (asked for {}): +18 {:08X} +1C {:08X} +20 {:08X} "
              "+24(avail) {:08X} +28 {:08X} +2C {:08X} +30(queue) {:08X} +34 {:08X} +38 {:08X} +3C {:08X}",
              r, g_reader_need.load(), w(r + 0x18), w(r + 0x1C), w(r + 0x20), w(r + 0x24), w(r + 0x28),
              w(r + 0x2C), w(r + 0x30), w(r + 0x34), w(r + 0x38), w(r + 0x3C));
  if (PPCContext* c = g_reader_ctx.load()) {
    REXAPU_WARN("[ea-audio]   reader registers: r18 {} r19 {} r20 {} r21 {:08X} r23 {} r24 {} r25 {} "
                "r26 {} r27 {} r28 {:08X} r29 {} r30 {} r31 {:08X} lr {:08X}",
                c->r18.s32, c->r19.s32, c->r20.s32, c->r21.u32, c->r23.s32, c->r24.s32, c->r25.s32,
                c->r26.s32, c->r27.s32, c->r28.u32, c->r29.s32, c->r30.s32, c->r31.u32,
                static_cast<uint32_t>(c->lr));
  }
  REXAPU_WARN("[ea-audio]   reader pending queue +0C {:08X} +10 {:08X} +14 {} | breaks so far {} | "
              "other-thread calls: submit {} feed {} read {} | overlaps {}",
              w(r + 0x0C), w(r + 0x10), w(r + 0x14), g_reader_breaks.load(),
              g_reader_calls_other[0].load(), g_reader_calls_other[1].load(),
              g_reader_calls_other[2].load(), g_reader_overlaps.load());
  const uint32_t arr = w(r + 0x18), count = w(r + 0x20);
  for (uint32_t i = 0; i < count && i < 8; i++) {
    const uint32_t e = arr + i * 24;
    const uint32_t obj = w(e);
    REXAPU_WARN("[ea-audio]     voice {} entry {:08X}: {:08X} {:08X} {:08X} {:08X} {:08X} {:08X} -> xma context {:08X}",
                i, e, w(e), w(e + 4), w(e + 8), w(e + 12), w(e + 16), w(e + 20), obj ? w(obj) : 0);
    if (obj && w(obj)) xma_dump_context(base, w(obj), "      ");
  }
}

// --- EA audio thread and voice callbacks --------------------------------------
extern "C" REX_FUNC(sub_82650B78) {
  g_ea_obj = ctx.r3.u32;
  t_is_ea_audio = true;
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
  const int depth = g_ea_depth.load();
  REXAPU_WARN("[ea-audio]   audio thread call stack (depth {}), XMA calls made by it so far {}:", depth,
              g_ea_xma_calls.load());
  for (int d = 0; d < depth && d < kEaStackMax; d++) {
    REXAPU_WARN("[ea-audio]     #{} sub_{:08X} (entered {} ms ago)", d, g_ea_stack[d].load(),
                (now - g_ea_stack_since[d].load()) / 1000);
  }
  reader_dump(base);
  file_read_report();
  xma_report_errors(base);
}
