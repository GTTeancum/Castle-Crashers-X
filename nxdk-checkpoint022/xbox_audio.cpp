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
constexpr unsigned kDma = 31;                    // DMA buffer ring (the AC97 has 32 descriptors)

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

void (*g_render)(int16_t*, int) = nullptr;  // the mixer, set by each pump
unsigned g_target = 8;                      // queue depth the pump asked for

// Buffers queued ahead of the one the AC97 is playing.
unsigned queued() {
  const unsigned civ = ac97()[0x114] & 31u;
  const unsigned last = (g_provided - 1u) & 31u;
  return (last - civ) & 31u;
}

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
  // Margin of 8 buffers (~133 ms) past the last frame's length: the console
  // has frames of 55-140 ms in four-player fights, which drained the old
  // 3-buffer margin (music stutter, 2026-10-04). Here only the buffers the
  // next frame of the same length needs plus 3 are mixed; the rest of the
  // margin is topped up while the frame waits for its vblank
  // (cc_xbox_audio_idle), so a slow frame's refill no longer lands on the
  // next frame as a burst (up to ~20 ms of mixing in one frame).
  unsigned target = unsigned(dt * 60u / 1000u) + 8u;
  if (target < 8u) target = 8u;
  if (target > kDma - 2u) target = kDma - 2u;
  g_render = render;
  g_target = target;
  unsigned now_target = unsigned(dt * 60u / 1000u) + 3u;
  if (now_target > target) now_target = target;
  unsigned ahead = queued();
  if (ahead == 0) ++g_underruns;
  while (ahead < now_target) { provide(render); ++ahead; }
}

// One more buffer toward the frame boundary's target if the queue is short
// of it; false when it is full (the caller then waits for the vblank).
bool cc_xbox_audio_idle() {
  if (!g_start_ok || !g_render || queued() >= g_target) return false;
  provide(g_render);
  return true;
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
