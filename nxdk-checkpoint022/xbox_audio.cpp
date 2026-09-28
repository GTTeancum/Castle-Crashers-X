// SPDX-License-Identifier: MIT
// Original-Xbox audio output for the port's software mixer (runtime021
// audio.inc): 48 kHz 16-bit stereo on the AC97 through nxdk's XAudio HAL.
//
// The game thread mixes one frame (800 stereo samples) per game frame and
// queues it here. Buffers are handed to the AC97 by polling its current
// descriptor index from the game thread (the completion interrupt is not
// relied on: under XEMU it stops arriving after the first buffers). About
// three buffers are kept queued ahead of the hardware; when the game has
// no mixed audio ready, silence keeps the DMA running.
#include <hal/audio.h>
#include <xboxkrnl/xboxkrnl.h>
#include <windows.h>
#include <cstdint>
#include <cstring>

namespace {
constexpr int kFrameSamples = 800;               // 48000 / 60
constexpr int kFrameBytes = kFrameSamples * 4;   // stereo s16
constexpr unsigned kQueue = 16;                  // mixed frames waiting
constexpr unsigned kDma = 8;                     // DMA buffer ring
constexpr unsigned kAhead = 3;                   // descriptors kept queued

int16_t g_queue[kQueue][kFrameSamples * 2];
unsigned g_head = 0, g_tail = 0;
uint8_t* g_dma[kDma];
unsigned g_dma_next = 0;
unsigned g_provided = 0;                         // descriptors handed out
bool g_started = false, g_start_ok = false;
unsigned g_underruns = 0, g_submitted = 0, g_dropped = 0, g_polls = 0;

volatile uint8_t* ac97() { return reinterpret_cast<volatile uint8_t*>(0xFEC00000u); }

void provide_next() {
  uint8_t* buf = g_dma[g_dma_next];
  g_dma_next = (g_dma_next + 1) % kDma;
  if (g_tail != g_head) {
    std::memcpy(buf, g_queue[g_tail % kQueue], kFrameBytes);
    ++g_tail;
  } else {
    std::memset(buf, 0, kFrameBytes);
    ++g_underruns;
  }
  XAudioProvideSamples(buf, kFrameBytes, 0);
  ++g_provided;
}

// Top up the hardware queue: descriptors between the one playing (CIV) and
// the last one provided are still pending.
void pump() {
  ++g_polls;
  const unsigned civ = ac97()[0x114] & 31u;
  const unsigned last = (g_provided - 1u) & 31u;
  unsigned ahead = (last - civ) & 31u;
  while (ahead < kAhead) { provide_next(); ++ahead; }
}

void on_interrupt(void*, void*) {}  // feeding is polled (see above)

bool start() {
  for (unsigned i = 0; i < kDma; ++i) {
    g_dma[i] = static_cast<uint8_t*>(MmAllocateContiguousMemoryEx(
        kFrameBytes, 0, 0x03FFAFFF, 0, PAGE_READWRITE | PAGE_WRITECOMBINE));
    if (!g_dma[i]) return false;
  }
  XAudioInit(16, 2, &on_interrupt, nullptr);
  for (unsigned i = 0; i < kAhead; ++i) provide_next();
  XAudioPlay();
  return true;
}
}  // namespace

// Queue one mixed frame (kFrameSamples interleaved stereo samples), then top
// up the hardware. Drops the frame when the queue is full.
void cc_xbox_audio_submit(const int16_t* frame, int samples) {
  if (samples != kFrameSamples) return;
  if (!g_started) {
    g_started = true;
    g_start_ok = start();
  }
  if (!g_start_ok) return;
  if (g_head - g_tail >= kQueue) {
    ++g_dropped;
  } else {
    std::memcpy(g_queue[g_head % kQueue], frame, kFrameBytes);
    ++g_head;
    ++g_submitted;
  }
  pump();
}

// Diagnostics for the on-screen overlay.
void cc_xbox_audio_stats(unsigned* started, unsigned* submitted, unsigned* callbacks,
                         unsigned* underruns, unsigned* dropped) {
  *started = g_start_ok ? 1u : 0u;
  *submitted = g_submitted; *callbacks = g_provided;
  *underruns = g_underruns; *dropped = g_dropped;
}
