// Where is EA's audio thread? A tiny call stack kept only for that thread (src/audio_diag.cpp
// marks it when its loop starts), read by the watchdog's stall report.
#pragma once
#include <atomic>
#include <cstdint>

extern thread_local bool t_is_ea_audio;
constexpr int kEaStackMax = 16;
extern std::atomic<uint32_t> g_ea_stack[kEaStackMax];
extern std::atomic<int64_t> g_ea_stack_since[kEaStackMax];
extern std::atomic<int> g_ea_depth;
extern std::atomic<uint64_t> g_ea_xma_calls;
int64_t ea_now_us();

struct EaScope {
  bool active;
  explicit EaScope(uint32_t addr) : active(t_is_ea_audio) {
    if (!active) return;
    const int d = g_ea_depth.load();
    if (d < kEaStackMax) {
      g_ea_stack[d] = addr;
      g_ea_stack_since[d] = ea_now_us();
    }
    g_ea_depth = d + 1;
  }
  ~EaScope() {
    if (active) g_ea_depth = g_ea_depth.load() - 1;
  }
};
