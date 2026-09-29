// SPDX-License-Identifier: MIT
// On-target sampling profiler for the play build (CC_XBOX_PROFILE): a
// time-critical thread wakes about once a millisecond and records which
// translated function the game thread last entered (self) and every guest
// return address on its PowerPC stack (inclusive). Results are shown on
// screen by xbox_render.cpp as a rolling 20-second window.
#include <windows.h>
#include <cstdint>
#include <cstring>

volatile const char* g_xprof_fn = nullptr;
volatile uint32_t g_xprof_r1 = 0, g_xprof_lr = 0;

namespace {
constexpr unsigned kSlots = 4096;
struct Table {
  uint32_t key[kSlots];
  uint32_t count[kSlots];
  void clear() { std::memset(key, 0, sizeof(key)); std::memset(count, 0, sizeof(count)); }
  void add(uint32_t k) {
    if (!k) return;
    uint32_t h = (k >> 2) * 2654435761u;
    for (unsigned i = 0; i < 64; ++i) {
      const unsigned s = (h + i) & (kSlots - 1);
      if (key[s] == k) { ++count[s]; return; }
      if (!key[s]) { key[s] = k; count[s] = 1; return; }
    }
  }
};
// Two sets (self, inclusive), double-buffered: the thread fills `live`,
// the display reads `shown`, swapped every 20 s.
Table g_tab[2][2];
unsigned g_live = 0;
uint32_t g_samples[2] = {};
bool (*g_read32)(uint32_t, uint32_t*) = nullptr;
bool g_started = false;

constexpr unsigned kTop = 14;
uint32_t g_top_addr[2][kTop], g_top_pm[2][kTop];  // per mille

uint32_t name_addr(const char* n) {
  // "sub_82085110" (optionally with a suffix) -> 0x82085110
  if (!n || std::strncmp(n, "sub_", 4)) return 0;
  uint32_t v = 0;
  for (int i = 4; i < 12; ++i) {
    const char c = n[i];
    v <<= 4;
    if (c >= '0' && c <= '9') v |= uint32_t(c - '0');
    else if (c >= 'A' && c <= 'F') v |= uint32_t(c - 'A' + 10);
    else return 0;
  }
  return v;
}

void rank(unsigned buf) {
  for (unsigned kind = 0; kind < 2; ++kind) {
    Table& t = g_tab[buf][kind];
    const uint32_t total = g_samples[buf] ? g_samples[buf] : 1;
    for (unsigned r = 0; r < kTop; ++r) {
      unsigned best = kSlots;
      for (unsigned s = 0; s < kSlots; ++s)
        if (t.count[s] && (best == kSlots || t.count[s] > t.count[best])) best = s;
      if (best == kSlots) { g_top_addr[kind][r] = 0; g_top_pm[kind][r] = 0; continue; }
      g_top_addr[kind][r] = t.key[best];
      g_top_pm[kind][r] = t.count[best] * 1000u / total;
      t.count[best] = 0;
    }
  }
}

DWORD WINAPI sampler(LPVOID) {
  DWORD window_start = GetTickCount();
  for (;;) {
    Sleep(1);
    const unsigned b = g_live;
    ++g_samples[b];
    const char* fn = const_cast<const char*>(g_xprof_fn);
    g_tab[b][0].add(name_addr(fn));
    // Inclusive: current function plus each caller on the guest stack.
    uint32_t seen[40]; unsigned n = 0;
    seen[n++] = name_addr(fn);
    seen[n++] = g_xprof_lr;
    uint32_t sp = g_xprof_r1, v = 0;
    while (n < 40 && sp && g_read32 && g_read32(sp, &v) && v > sp && v - sp < 0x100000u) {
      uint32_t ra = 0;
      if (!g_read32(v - 8u, &ra)) break;
      seen[n++] = ra;
      sp = v;
    }
    for (unsigned i = 0; i < n; ++i) {
      bool dup = false;
      for (unsigned k = 0; k < i; ++k) dup |= seen[k] == seen[i];
      if (!dup && (seen[i] >> 24) == 0x82u) g_tab[b][1].add(seen[i]);
    }
    if (GetTickCount() - window_start >= 20000) {
      window_start = GetTickCount();
      g_live = b ^ 1u;
      rank(b);
      g_tab[b][0].clear(); g_tab[b][1].clear(); g_samples[b] = 0;
    }
  }
  return 0;
}
}  // namespace

// Called each frame from the frame boundary; starts the thread once.
void cc_xprof_frame(bool (*read32)(uint32_t, uint32_t*)) {
  g_read32 = read32;
  if (g_started) return;
  g_started = true;
  g_tab[0][0].clear(); g_tab[0][1].clear(); g_tab[1][0].clear(); g_tab[1][1].clear();
  HANDLE t = CreateThread(nullptr, 0, sampler, nullptr, 0, nullptr);
  if (t) SetThreadPriority(t, THREAD_PRIORITY_TIME_CRITICAL);
}

// Ranked results of the last completed window. kind 0 = self (function
// entry address), 1 = inclusive (return addresses: the caller's address
// just after its call). Returns false past the end.
bool cc_xprof_top(unsigned kind, unsigned i, uint32_t* addr, unsigned* permille) {
  if (kind > 1 || i >= kTop || !g_top_addr[kind][i]) return false;
  *addr = g_top_addr[kind][i];
  *permille = g_top_pm[kind][i];
  return true;
}
