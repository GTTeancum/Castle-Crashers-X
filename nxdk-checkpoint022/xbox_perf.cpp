// SPDX-License-Identifier: MIT
// Per-second console measurement lines printed next to PERF (called once a
// second from cc_xr_frame_end in xbox_render.cpp):
//   FRAME: where each frame's time goes besides the game's update and
//          render, in 0.1 ms per frame like PERF: audio mix (aud), frame end
//          with the overlay, GPU wait and present (end), frame-pacing sleep
//          (slp), worker jobs at the frame boundary (wrk) and everything
//          else (oth = frame - upd - ren - aud - end - slp - wrk: the main
//          loop outside update/render and the frame-boundary glue); and the
//          baked textures read in the second (count, KiB).
//   PMC (make PMC=1): two Pentium III performance counters, rotating through
//          event pairs one second at a time. The title runs in ring 0, so it
//          programs PerfEvtSel0/1 (MSR 0x186/0x187) and reads with rdpmc.
#include <windows.h>
#include <xboxkrnl/xboxkrnl.h>
#include <cstdint>

// runtime021 (bridge.cpp): FRAME line counters since the last call, reset:
// {frames, baked-texture reads, baked-texture bytes, then microseconds of
// frame, audio, end, sleep, workers, update, render}.
void cc_xbox_frame_stats(uint64_t out[10]);

#ifdef CC_PMC
namespace {
struct PmcEvent { uint8_t event, umask; const char* name; };
// Pairs: counter 0, counter 1. The P6 family has no data-TLB miss event.
constexpr PmcEvent kSets[][2] = {
  {{0x79, 0x00, "clk"}, {0xC0, 0x00, "inst"}},            // CPU_CLK_UNHALTED, INST_RETIRED
  {{0x45, 0x00, "dcu_in"}, {0x24, 0x00, "l2_in"}},        // DCU_LINES_IN, L2_LINES_IN
  {{0x86, 0x00, "ifu_stall"}, {0x81, 0x00, "ifu_miss"}},  // IFU_MEM_STALL, IFU_IFETCH_MISS
  {{0x85, 0x00, "itlb_miss"}, {0x28, 0x0F, "l2_ifetch"}}, // ITLB_MISS, L2_IFETCH (all MESI states)
  {{0xA2, 0x00, "res_stall"}, {0xC5, 0x00, "br_miss"}},   // RESOURCE_STALLS, BR_MISS_PRED_RETIRED
  {{0x03, 0x00, "ld_block"}, {0x48, 0x00, "dcu_out"}},    // LD_BLOCKS (store-forward blocks), DCU_MISS_OUTSTANDING
};
constexpr unsigned kSetCount = sizeof(kSets) / sizeof(kSets[0]);
unsigned g_set = 0;
bool g_armed = false;
inline void wrmsr(uint32_t msr, uint64_t v) {
  __asm__ volatile("wrmsr" : : "c"(msr), "a"(uint32_t(v)), "d"(uint32_t(v >> 32)));
}
inline uint64_t rdpmc(uint32_t i) {
  uint32_t lo, hi;
  __asm__ volatile("rdpmc" : "=a"(lo), "=d"(hi) : "c"(i));
  return (uint64_t(hi & 0xFFu) << 32) | lo;  // 40-bit counters
}
// PerfEvtSel: event, unit mask, USR (bit 16), OS (bit 17; the title runs in
// ring 0); EN (bit 22, PerfEvtSel0 only) enables both counters.
void arm(unsigned set) {
  wrmsr(0x186, 0);  // stop both while reprogramming
  wrmsr(0xC1, 0); wrmsr(0xC2, 0);
  const PmcEvent& a = kSets[set][0];
  const PmcEvent& b = kSets[set][1];
  wrmsr(0x187, uint64_t(b.event) | uint64_t(b.umask) << 8 | 1u << 16 | 1u << 17);
  wrmsr(0x186, uint64_t(a.event) | uint64_t(a.umask) << 8 | 1u << 16 | 1u << 17 | 1u << 22);
}
}  // namespace
#endif

// frames: frames completed in the second just ended.
void cc_xbox_perf_second([[maybe_unused]] unsigned frames) {
  uint64_t fs[10] = {};
  cc_xbox_frame_stats(fs);
  const uint64_t f = fs[0] ? fs[0] : 1u;
  uint64_t known = 0;
  for (unsigned i = 4; i < 10; ++i) known += fs[i];
  const uint64_t other = fs[3] > known ? fs[3] - known : 0u;
  DbgPrint("FRAME frames=%u ms=%u aud=%u end=%u slp=%u wrk=%u oth=%u bake=%u bakeKB=%u\n", unsigned(fs[0]),
           unsigned(fs[3] / f / 100u), unsigned(fs[4] / f / 100u), unsigned(fs[5] / f / 100u),
           unsigned(fs[6] / f / 100u), unsigned(fs[7] / f / 100u), unsigned(other / f / 100u),
           unsigned(fs[1]), unsigned(fs[2] >> 10));
#ifdef CC_PMC
  const unsigned n = frames ? frames : 1u;
  if (g_armed) {
    // The pair counted over the second just ended: totals in thousands, and
    // per frame.
    const uint64_t c0 = rdpmc(0), c1 = rdpmc(1);
    DbgPrint("PMC %s=%uK %s=%uK per_frame %s=%u %s=%u\n", kSets[g_set][0].name, unsigned(c0 / 1000u),
             kSets[g_set][1].name, unsigned(c1 / 1000u), kSets[g_set][0].name, unsigned(c0 / n),
             kSets[g_set][1].name, unsigned(c1 / n));
    g_set = (g_set + 1u) % kSetCount;
  }
  arm(g_set);
  g_armed = true;
#endif
}
