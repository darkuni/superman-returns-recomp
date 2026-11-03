// Keeps the XAudio render callback running when the game skips a frame.
//
// The SDK paces the game's render-driver callback with a semaphore of 16
// permits: each callback takes one, and a permit only comes back when the
// output device plays a frame the game submitted (XAudioSubmitRenderDriverFrame).
// A callback that returns without submitting loses its permit for good; after 16
// of those the audio worker never calls the game again. On the console the
// callback is driven by a hardware timer instead, so a skipped frame is just
// 5 ms of silence.
//
// Test 5 caught it: when the flight cinematic started, the watchdog in
// src/audio_hooks.cpp saw DSP updates stop ("the audio driver stopped calling
// the game") while nothing was blocked. The game kept queueing mixer commands
// until the 1 MB command buffer overflowed into the voice list.
//
// Fix: wrap the registered callback (swapped in the function dispatcher at
// registration - the dispatcher's own table is what the audio worker calls through). If the game's callback returns without submitting a frame,
// submit one frame of silence for it, as the hardware would play.

#include <atomic>
#include <cstdint>
#include <cstring>

#include <rex/hook.h>
#include <rex/logging.h>
#include <rex/system/kernel_state.h>
#include <rex/system/function_dispatcher.h>
#include <rex/system/xmemory.h>
#include <rex/types.h>

namespace rex::kernel::xboxkrnl {
u32 XAudioRegisterRenderDriverClient_entry(mapped_u32 callback_ptr, mapped_u32 driver_ptr);
u32 XAudioSubmitRenderDriverFrame_entry(mapped_void driver_ptr, mapped_void samples_ptr);
}  // namespace rex::kernel::xboxkrnl

namespace rex::runtime {
PPCFunc* ResolveIndirectFunction(uint32_t guest_address);
}

// Read by the mixer watchdog (src/audio_hooks.cpp).
std::atomic<uint64_t> g_pacing_callbacks{0};
std::atomic<uint64_t> g_submits{0};
std::atomic<uint64_t> g_filled{0};

namespace {
namespace k = rex::kernel::xboxkrnl;

constexpr uint32_t kFrameBytes = 6 * 256 * 4;  // 6 channels x 256 float samples

std::atomic<PPCFunc*> g_game_callback{nullptr};
std::atomic<uint32_t> g_driver{0};
std::atomic<uint32_t> g_silence{0};

uint32_t rd32(const uint8_t* base, uint32_t addr) {
  uint32_t v;
  std::memcpy(&v, base + addr, 4);
  return __builtin_bswap32(v);
}

void callback_wrapper(PPCContext& __restrict ctx, uint8_t* base) {
  ++g_pacing_callbacks;
  PPCFunc* game = g_game_callback.load();
  const uint64_t before = g_submits.load();
  PPCContext saved = ctx;
  if (game) game(ctx, base);
  const uint32_t driver = g_driver.load();
  const uint32_t silence = g_silence.load();
  if (g_submits.load() == before && driver && silence) {
    const uint64_t n = ++g_filled;
    if (n <= 5 || n % 1000 == 0) {
      REXAPU_WARN("[audio-pacing] game's audio callback returned without a frame - submitted "
                  "silence so the callback keeps coming (#{}; first 5 and every 1000th logged)",
                  n);
    }
    PPCContext c = saved;
    c.r3.u64 = driver;
    c.r4.u64 = silence;
    rex::ppc::HostToGuestFunction<&k::XAudioSubmitRenderDriverFrame_entry>(c, base);
  }
  // No keep-alive here any more: freeing EA's buffer slot from outside broke its slot
  // bookkeeping with XAudio2 and killed all audio from the start (test 8).
}
}  // namespace

extern "C" REX_FUNC(__imp__XAudioSubmitRenderDriverFrame) {
  ++g_submits;
  rex::ppc::HostToGuestFunction<&k::XAudioSubmitRenderDriverFrame_entry>(ctx, base);
}

extern "C" REX_FUNC(__imp__XAudioRegisterRenderDriverClient) {
  const uint32_t callback_ptr = ctx.r3.u32;
  const uint32_t driver_ptr = ctx.r4.u32;
  const uint32_t callback = callback_ptr ? rd32(base, callback_ptr) : 0;
  rex::ppc::HostToGuestFunction<&k::XAudioRegisterRenderDriverClient_entry>(ctx, base);
  if (ctx.r3.u32 != 0 || !callback || !driver_ptr) return;  // registration failed

  auto* memory = REX_KERNEL_STATE()->memory();
  if (!g_silence.load()) {
    const uint32_t buf = memory->SystemHeapAlloc(kFrameBytes);
    if (buf) std::memset(base + buf, 0, kFrameBytes);
    g_silence = buf;
  }
  g_driver = rd32(base, driver_ptr);  // a re-registration gets a new handle
  PPCFunc* game = rex::runtime::ResolveIndirectFunction(callback);
  if (game && game != &callback_wrapper) {
    g_game_callback = game;
    if (REX_KERNEL_STATE()->function_dispatcher()->SetFunction(callback, &callback_wrapper)) {
      REXAPU_WARN("[audio-pacing] render callback {:08X} wrapped (driver {:08X}, silence frame {:08X})",
                  callback, g_driver.load(), g_silence.load());
    } else {
      REXAPU_WARN("[audio-pacing] could not wrap render callback {:08X}", callback);
    }
  }
}
