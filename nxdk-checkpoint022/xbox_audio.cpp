// SPDX-License-Identifier: MIT
// Original-Xbox audio output for the port's software mixer (runtime021
// audio.inc): 48 kHz 16-bit stereo on the AC97 through nxdk's XAudio HAL.
//
// The game thread mixes one frame (800 stereo samples) per game frame and
// queues it here; the AC97 completion DPC hands the next queued frame to the
// hardware, or silence when the game has fallen behind (never blocks).
#include <hal/audio.h>
#include <xboxkrnl/xboxkrnl.h>
#include <windows.h>
#include <cstdint>
#include <cstring>

namespace {
constexpr int kFrameSamples = 800;               // 48000 / 60
constexpr int kFrameBytes = kFrameSamples * 4;   // stereo s16
constexpr unsigned kQueue = 16;                  // ~0.27 s of mixed audio
constexpr unsigned kDma = 4;                     // hardware buffers in flight

int16_t g_queue[kQueue][kFrameSamples * 2];
volatile unsigned g_head = 0, g_tail = 0;        // written by game / DPC
uint8_t* g_dma[kDma];
unsigned g_dma_next = 0;
bool g_started = false;
volatile unsigned g_underruns = 0, g_callbacks = 0, g_submitted = 0, g_dropped = 0;
bool g_start_ok = false;

// Called from the AC97 DPC: integer work only (no FPU state is saved).
void provide(void*, void*) {
  g_callbacks = g_callbacks + 1;
  uint8_t* buf = g_dma[g_dma_next];
  g_dma_next = (g_dma_next + 1) % kDma;
  if (g_tail != g_head) {
    std::memcpy(buf, g_queue[g_tail % kQueue], kFrameBytes);
    g_tail = g_tail + 1;
  } else {
    std::memset(buf, 0, kFrameBytes);
    g_underruns = g_underruns + 1;
  }
  XAudioProvideSamples(buf, kFrameBytes, 0);
}

bool start() {
  for (unsigned i = 0; i < kDma; ++i) {
    g_dma[i] = static_cast<uint8_t*>(MmAllocateContiguousMemoryEx(
        kFrameBytes, 0, 0x03FFAFFF, 0, PAGE_READWRITE | PAGE_WRITECOMBINE));
    if (!g_dma[i]) return false;
  }
  XAudioInit(16, 2, &provide, nullptr);
  for (unsigned i = 0; i < 2; ++i) provide(nullptr, nullptr);
  XAudioPlay();
  return true;
}
}  // namespace

// Queue one mixed frame (kFrameSamples interleaved stereo samples). Drops
// the frame when the queue is full (the game is running ahead of real time).
void cc_xbox_audio_submit(const int16_t* frame, int samples) {
  if (samples != kFrameSamples) return;
  if (!g_started) {
    g_started = true;
    g_start_ok = start();
    if (!g_start_ok) return;
  }
  if (!g_start_ok) return;
  if (g_head - g_tail >= kQueue) { g_dropped = g_dropped + 1; return; }
  g_submitted = g_submitted + 1;
  std::memcpy(g_queue[g_head % kQueue], frame, kFrameBytes);
  g_head = g_head + 1;
}

// Diagnostics for the frame probe log.
void cc_xbox_audio_stats(unsigned* started, unsigned* submitted, unsigned* callbacks,
                         unsigned* underruns, unsigned* dropped) {
  *started = g_start_ok ? 1u : 0u;
  *submitted = g_submitted; *callbacks = g_callbacks;
  *underruns = g_underruns; *dropped = g_dropped;
}
