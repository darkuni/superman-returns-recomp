// NULL-context guard for the XMA kernel calls Superman Returns makes.
//
// Test 3 crashed inside XMAGetOutputBufferWriteOffset(NULL): EA's XMA stream
// reader (sub_826592F0) walks its voice list and reads each voice's context
// without a null check. A voice released on another thread was still on the
// list with its context pointer already cleared. On the console the audio
// threads' fixed scheduling hides that window; on PC it doesn't.
//
// These definitions take precedence over the SDK's exports of the same name
// (an object file beats the import library on Windows; the executable's
// symbols interpose the shared library's on Linux). Each one forwards to the
// SDK's own implementation unless the context is NULL, in which case it logs
// once per call and returns 0 - the voice reads as "no progress" and the game
// drops it on its next pass. Release-time errors are not hidden: decode errors
// the game polls for are logged once per context.

#include <atomic>
#include <chrono>
#include <algorithm>
#include <cstdint>

#include <rex/audio/xma/context.h>
#include <rex/hook.h>
#include <rex/logging.h>
#include <rex/types.h>

#include "ea_track.h"

namespace rex::kernel::xboxkrnl {
u32 XMACreateContext_entry(mapped_u32 context_out_ptr);
u32 XMAReleaseContext_entry(mapped_void context_ptr);
u32 XMASetInputBuffer0_entry(mapped_void context_ptr, mapped_void buffer, u32 packet_count);
u32 XMASetInputBuffer1_entry(mapped_void context_ptr, mapped_void buffer, u32 packet_count);
u32 XMAIsInputBuffer0Valid_entry(mapped_void context_ptr);
u32 XMAIsInputBuffer1Valid_entry(mapped_void context_ptr);
u32 XMASetInputBuffer0Valid_entry(mapped_void context_ptr);
u32 XMASetInputBuffer1Valid_entry(mapped_void context_ptr);
u32 XMAIsOutputBufferValid_entry(mapped_void context_ptr);
u32 XMASetOutputBufferValid_entry(mapped_void context_ptr);
u32 XMAGetOutputBufferReadOffset_entry(mapped_void context_ptr);
u32 XMASetOutputBufferReadOffset_entry(mapped_void context_ptr, u32 value);
u32 XMAGetOutputBufferWriteOffset_entry(mapped_void context_ptr);
u32 XMAEnableContext_entry(mapped_void context_ptr);
u32 XMADisableContext_entry(mapped_void context_ptr, u32 wait);
}  // namespace rex::kernel::xboxkrnl

namespace {
namespace k = rex::kernel::xboxkrnl;

// One log line per guarded call (by name), so a recurring race doesn't flood the log.
struct Once {
  std::atomic<bool> fired{false};
  bool first() { return !fired.exchange(true); }
};

bool null_context(PPCContext& ctx, const char* name, Once& once) {
  if (t_is_ea_audio) ++g_ea_xma_calls;
  if (ctx.r3.u32 != 0) return false;
  if (once.first()) {
    REXAPU_WARN("[xma-guard] {}(NULL) from {:08X} - voice already released; returning 0 "
                "(logged once)",
                name, static_cast<uint32_t>(ctx.lr));
  }
  ctx.r3.u64 = 0;
  return true;
}

// Decode errors (the stock decoder sets these where the hardware would not) are
// what EA's mixer reacts to by tearing voices - or the whole engine - down.
std::atomic<uint32_t> g_error_logged[10] = {};
void note_errors(uint8_t* base, uint32_t context) {
  rex::audio::XMA_CONTEXT_DATA data(base + context);
  if (!data.error_set && !data.parser_error_set) return;
  const uint32_t key = (data.error_status << 5) | data.parser_error_status;
  for (auto& slot : g_error_logged) {
    uint32_t cur = slot.load();
    if (cur == (key | 0x80000000u)) return;
    if (cur == 0 && slot.compare_exchange_strong(cur, key | 0x80000000u)) {
      REXAPU_WARN("[xma-guard] context {:08X} reports decode error {} / parser error {} "
                  "(first time this error pair is seen)",
                  context, uint32_t(data.error_status), uint32_t(data.parser_error_status));
      return;
    }
  }
}
}  // namespace

#define XMA_GUARD(name, ...)                                                    \
  extern "C" REX_FUNC(__imp__##name) {                                          \
    static Once once;                                                           \
    if (null_context(ctx, #name, once)) return;                                 \
    rex::ppc::HostToGuestFunction<&k::name##_entry>(ctx, base);                 \
  }

XMA_GUARD(XMAReleaseContext)
XMA_GUARD(XMASetInputBuffer0)
XMA_GUARD(XMASetInputBuffer1)
XMA_GUARD(XMAIsInputBuffer0Valid)
XMA_GUARD(XMAIsInputBuffer1Valid)
XMA_GUARD(XMASetInputBuffer0Valid)
XMA_GUARD(XMASetInputBuffer1Valid)
XMA_GUARD(XMAIsOutputBufferValid)
XMA_GUARD(XMASetOutputBufferValid)
XMA_GUARD(XMASetOutputBufferReadOffset)
XMA_GUARD(XMAEnableContext)

// Timed: the audio_hooks watchdog reports a call that never returns (deadlock suspect).
extern std::atomic<int64_t> g_xma_disable_enter_us;
extern std::atomic<uint32_t> g_xma_disable_ctx;
extern std::atomic<uint32_t> g_xma_disable_lr;
extern std::atomic<uint32_t> g_xma_disable_wait;

extern "C" REX_FUNC(__imp__XMADisableContext) {
  static Once once;
  if (null_context(ctx, "XMADisableContext", once)) return;
  g_xma_disable_ctx = ctx.r3.u32;
  g_xma_disable_wait = ctx.r4.u32;
  g_xma_disable_lr = static_cast<uint32_t>(ctx.lr);
  g_xma_disable_enter_us = std::chrono::duration_cast<std::chrono::microseconds>(
                               std::chrono::steady_clock::now().time_since_epoch())
                               .count();
  rex::ppc::HostToGuestFunction<&k::XMADisableContext_entry>(ctx, base);
  g_xma_disable_enter_us = 0;
}

// The two the game polls every mixer pass: also where decode errors get noticed.
extern "C" REX_FUNC(__imp__XMAGetOutputBufferReadOffset) {
  static Once once;
  if (null_context(ctx, "XMAGetOutputBufferReadOffset", once)) return;
  note_errors(base, ctx.r3.u32);
  rex::ppc::HostToGuestFunction<&k::XMAGetOutputBufferReadOffset_entry>(ctx, base);
}

extern "C" REX_FUNC(__imp__XMAGetOutputBufferWriteOffset) {
  static Once once;
  if (null_context(ctx, "XMAGetOutputBufferWriteOffset", once)) return;
  note_errors(base, ctx.r3.u32);
  rex::ppc::HostToGuestFunction<&k::XMAGetOutputBufferWriteOffset_entry>(ctx, base);
}

// Every context the game creates, so a stall report can check them all for error flags:
// XAudio2 reads the context memory directly, which the accessor guards above never see.
namespace {
constexpr int kMaxContexts = 512;
std::atomic<uint32_t> g_contexts[kMaxContexts] = {};
std::atomic<int> g_context_count{0};
}  // namespace

extern "C" REX_FUNC(__imp__XMACreateContext) {
  const uint32_t out = ctx.r3.u32;
  rex::ppc::HostToGuestFunction<&k::XMACreateContext_entry>(ctx, base);
  if (ctx.r3.u32 == 0 && out) {
    uint32_t v;
    __builtin_memcpy(&v, base + out, 4);
    v = __builtin_bswap32(v);
    const int i = g_context_count.fetch_add(1);
    if (i < kMaxContexts) g_contexts[i] = v;
  }
}

void xma_report_errors(uint8_t* base) {
  const int n = std::min(g_context_count.load(), kMaxContexts);
  int bad = 0;
  for (int i = 0; i < n; i++) {
    const uint32_t c = g_contexts[i].load();
    if (!c) continue;
    rex::audio::XMA_CONTEXT_DATA data(base + c);
    if (data.error_set || data.parser_error_set) {
      if (++bad <= 8) {
        REXAPU_WARN("[xma-guard]   context {:08X}: decode error {} (set {}), parser error {} (set {}), "
                    "input valid {}/{}, output valid {}",
                    c, uint32_t(data.error_status), uint32_t(data.error_set),
                    uint32_t(data.parser_error_status), uint32_t(data.parser_error_set),
                    uint32_t(data.input_buffer_0_valid), uint32_t(data.input_buffer_1_valid),
                    uint32_t(data.output_buffer_valid));
      }
    }
  }
  REXAPU_WARN("[xma-guard]   {} of {} XMA contexts have an error flag set", bad, n);
}
