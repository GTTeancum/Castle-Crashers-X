// SPDX-License-Identifier: MIT
// Original-Xbox audio output for the port's software mixer (runtime021
// audio.inc): 48 kHz 16-bit stereo on the AC97 through nxdk's XAudio HAL.
//
// A dedicated audio thread, above the game thread's priority, keeps a short
// queue of mixed buffers ahead of the one the AC97 is playing, checking
// every 2 ms; it polls the AC97's current descriptor index (the completion
// interrupt is not relied on). The queue no longer depends on the game's
// frame time: when the mixer ran on the game thread, the queue had to cover
// the slowest frame (~170 ms at 30 FPS), so sound effects started that late,
// and long frames still drained it (music stutter). Now it is 4 buffers of
// 8.3 ms (~33 ms). The game's PlatformAudio calls and the mixer share one
// lock (cc_xbox_audio_lock / unlock around audio.inc's entry points).
#include <hal/audio.h>
#include <xboxkrnl/xboxkrnl.h>
#include <windows.h>
#include <cstdint>
#include <cstring>

namespace {
constexpr int kBufSamples = 400;                 // 8.3 ms at 48 kHz
constexpr int kBufBytes = kBufSamples * 4;       // stereo s16
constexpr unsigned kDma = 31;                    // DMA buffer ring (the AC97 has 32 descriptors)
constexpr unsigned kQueue = 4;                   // buffers kept ahead of the playing one (~33 ms)

uint8_t* g_dma[kDma];
unsigned g_dma_next = 0;
unsigned g_provided = 0;                         // descriptors handed out
bool g_started = false, g_start_ok = false;
unsigned g_mixed = 0, g_underruns = 0, g_dropped = 0;
CRITICAL_SECTION g_lock;
bool g_lock_ready = false;
void (*g_render)(int16_t*, int) = nullptr;       // the mixer

volatile uint8_t* ac97() { return reinterpret_cast<volatile uint8_t*>(0xFEC00000u); }

void provide(void (*render)(int16_t*, int)) {
  uint8_t* buf = g_dma[g_dma_next];
  g_dma_next = (g_dma_next + 1) % kDma;
  if (render) { render(reinterpret_cast<int16_t*>(buf), kBufSamples); ++g_mixed; }
  else { std::memset(buf, 0, kBufBytes); ++g_underruns; }
  XAudioProvideSamples(buf, kBufBytes, 0);
  ++g_provided;
}

void on_interrupt(void*, void*) {}  // feeding is polled by the audio thread

// Buffers queued ahead of the one the AC97 is playing.
unsigned queued() {
  const unsigned civ = ac97()[0x114] & 31u;
  const unsigned last = (g_provided - 1u) & 31u;
  return (last - civ) & 31u;
}

void lock_init() {
  if (!g_lock_ready) { InitializeCriticalSection(&g_lock); g_lock_ready = true; }
}

DWORD WINAPI audio_thread(LPVOID) {
  for (;;) {
    EnterCriticalSection(&g_lock);
    unsigned ahead = queued();
    if (ahead == 0) ++g_underruns;
    while (ahead < kQueue) { provide(g_render); ++ahead; }
    LeaveCriticalSection(&g_lock);
    LARGE_INTEGER t;
    t.QuadPart = -20000;  // 2 ms
    KeDelayExecutionThread(KernelMode, FALSE, &t);
  }
  return 0;
}

bool start() {
  for (unsigned i = 0; i < kDma; ++i) {
    g_dma[i] = static_cast<uint8_t*>(MmAllocateContiguousMemoryEx(
        kBufBytes, 0, 0x03FFAFFF, 0, PAGE_READWRITE | PAGE_WRITECOMBINE));
    if (!g_dma[i]) return false;
  }
  XAudioInit(16, 2, &on_interrupt, nullptr);
  for (unsigned i = 0; i < 2; ++i) provide(nullptr);
  XAudioPlay();
  HANDLE h = CreateThread(nullptr, 64 * 1024, &audio_thread, nullptr, 0, nullptr);
  if (!h) return false;
  SetThreadPriority(h, THREAD_PRIORITY_TIME_CRITICAL);
  return true;
}
}  // namespace

void cc_xbox_audio_lock() { lock_init(); EnterCriticalSection(&g_lock); }
void cc_xbox_audio_unlock() { LeaveCriticalSection(&g_lock); }

// Called once per game frame with the mixer: the first call starts the
// output and the audio thread; later calls have nothing to do.
void cc_xbox_audio_pump(void (*render)(int16_t* out, int samples)) {
  if (g_started) return;
  g_started = true;
  lock_init();
  g_render = render;
  g_start_ok = start();
  if (!g_start_ok) DbgPrint("FAIL audio: output or audio thread could not start\n");
}

// Silence before leaving for the dashboard (in-game reset): the output is
// paused and the audio thread stops refilling it.
void cc_xbox_audio_stop() {
  if (!g_started) return;
  lock_init();
  EnterCriticalSection(&g_lock);
  g_render = nullptr;
  XAudioPause();
  LeaveCriticalSection(&g_lock);
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
