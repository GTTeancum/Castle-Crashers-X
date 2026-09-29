// SPDX-License-Identifier: MIT
// Original-Xbox audio output for the port's software mixer (runtime021
// audio.inc): 48 kHz 16-bit stereo on the AC97 through nxdk's XAudio HAL.
//
// Buffers are handed to the AC97 by polling its current descriptor index
// from the game thread (the completion interrupt is not relied on: under
// XEMU it stops arriving after the first buffers), and each one is mixed
// on demand, so audio keeps real-time pace whatever the game's frame rate.
#include <hal/audio.h>
#include <xboxkrnl/xboxkrnl.h>
#include <windows.h>
#include <cstdint>
#include <cstring>

namespace {
constexpr int kFrameSamples = 800;               // one 60 Hz frame at 48 kHz
constexpr int kFrameBytes = kFrameSamples * 4;   // stereo s16
constexpr unsigned kDma = 20;                    // DMA buffer ring

uint8_t* g_dma[kDma];
unsigned g_dma_next = 0;
unsigned g_provided = 0;                         // descriptors handed out
bool g_started = false, g_start_ok = false;
unsigned g_mixed = 0, g_underruns = 0, g_dropped = 0;

volatile uint8_t* ac97() { return reinterpret_cast<volatile uint8_t*>(0xFEC00000u); }

void provide(void (*render)(int16_t*, int)) {
  uint8_t* buf = g_dma[g_dma_next];
  g_dma_next = (g_dma_next + 1) % kDma;
  if (render) { render(reinterpret_cast<int16_t*>(buf), kFrameSamples); ++g_mixed; }
  else { std::memset(buf, 0, kFrameBytes); ++g_underruns; }
  XAudioProvideSamples(buf, kFrameBytes, 0);
  ++g_provided;
}

void on_interrupt(void*, void*) {}  // feeding is polled from the game thread

bool start() {
  for (unsigned i = 0; i < kDma; ++i) {
    g_dma[i] = static_cast<uint8_t*>(MmAllocateContiguousMemoryEx(
        kFrameBytes, 0, 0x03FFAFFF, 0, PAGE_READWRITE | PAGE_WRITECOMBINE));
    if (!g_dma[i]) return false;
  }
  XAudioInit(16, 2, &on_interrupt, nullptr);
  for (unsigned i = 0; i < 2; ++i) provide(nullptr);
  XAudioPlay();
  return true;
}
}  // namespace

// Called once per game frame: every descriptor the AC97 has consumed since
// the last call is replaced by a freshly mixed buffer, so audio advances at
// real-time speed. If the
// game stalls for longer than the queue, the hardware plays the last
// buffers again rather than stopping; that shows up as underruns here.
void cc_xbox_audio_pump(void (*render)(int16_t* out, int samples)) {
  if (!g_started) {
    g_started = true;
    g_start_ok = start();
  }
  if (!g_start_ok) return;
  // Queue depth follows the game's frame time: enough buffers to last until
  // the next call plus a margin, so a slow frame never drains the hardware,
  // while a fast game keeps latency low.
  static DWORD last_tick = 0;
  const DWORD now = GetTickCount();
  const DWORD dt = last_tick ? now - last_tick : 16u;
  last_tick = now;
  unsigned target = unsigned(dt * 60u / 1000u) + 3u;
  if (target < 4u) target = 4u;
  if (target > kDma - 2u) target = kDma - 2u;
  const unsigned civ = ac97()[0x114] & 31u;
  const unsigned last = (g_provided - 1u) & 31u;
  unsigned ahead = (last - civ) & 31u;
  if (ahead == 0) ++g_underruns;
  while (ahead < target) { provide(render); ++ahead; }
}

// Diagnostics for the on-screen overlay.
void cc_xbox_audio_stats(unsigned* started, unsigned* submitted, unsigned* callbacks,
                         unsigned* underruns, unsigned* dropped) {
  *started = g_start_ok ? 1u : 0u;
  *submitted = g_mixed; *callbacks = g_provided;
  *underruns = g_underruns; *dropped = g_dropped;
}

// Real clock for the play build's guest timebase, in ticks of `hz`.
uint64_t cc_xbox_clock(uint64_t hz) {
  static uint64_t freq = 0, start = 0;
  if (!freq) { freq = KeQueryPerformanceFrequency(); start = KeQueryPerformanceCounter(); }
  const uint64_t c = KeQueryPerformanceCounter() - start;
  return (c / freq) * hz + (c % freq) * hz / freq;
}

// Sleep for a relative interval in 100 ns units (the game's frame pacing),
// keeping the audio queue fed across the wait.
void cc_xbox_sleep_100ns(uint64_t interval) {
  if (interval == 0 || interval > 1000000u) return;  // ignore > 100 ms
  LARGE_INTEGER t;
  t.QuadPart = -static_cast<LONGLONG>(interval);
  KeDelayExecutionThread(KernelMode, FALSE, &t);
}
