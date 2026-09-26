// SPDX-License-Identifier: MIT
// Real generated quad code + native GPU submission, driven by captured CALLER
// state. The test controls below are not Castle Crashers' game update or
// animation loop.
#include "../renderer011/live_frame.h"
#include "../runtime011/selftest.h"
#include "../runtime013/selftest.h"
#include "expected.h"
#include "../port009/mode.h"
#include "telemetry.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <hal/debug.h>
#include <hal/video.h>
#include <initializer_list>
#include <pbkit/pbkit.h>
#include <windows.h>
using cc::replay::GpuVertex;
extern "C" {
volatile Status011 g_cc_status011;
}
static cc::stream::Scene scene;
static cc::tree::Workspace work;
static_assert(sizeof(cc::xbox::AddressSpace) == 1028);
static cc::widget011::Resident resident;
static cc::tree::Fixtures inputs;
static void *input_bytes;
static constexpr uint32_t max_gpu_address = 0x03ffafff;
static uint32_t physical(const void *p) {
  return uint32_t(reinterpret_cast<uintptr_t>(p)) & 0x03ffffff;
}
// Scene/caller allocations own explicit virtual regions so small freed fixtures
// do not leave a retained general-purpose heap arena in the kernel page budget.
static void *allocate(void *, size_t n, bool gpu) {
  void *p =
      gpu ? MmAllocateContiguousMemoryEx(n, 0, max_gpu_address, 0,
                                         PAGE_READWRITE | PAGE_WRITECOMBINE)
          : VirtualAlloc(nullptr, n, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
  if (p)
    g_cc_status011.allocations = g_cc_status011.allocations + 1;
  return p;
}
static void release(void *, void *p, bool gpu) {
  if (gpu)
    MmFreeContiguousMemory(p);
  else if (!VirtualFree(p, 0, MEM_RELEASE)) {
    g_cc_status011.error = 9020;
    return;
  }
  g_cc_status011.frees = g_cc_status011.frees + 1;
}
struct FileSource {
  FILE *f;
  uint32_t position;
};
static bool read_file(void *ctx, uint32_t off, void *out, size_t n) {
  auto &s = *static_cast<FileSource *>(ctx);
  if (s.position != off && std::fseek(s.f, long(off), SEEK_SET))
    return false;
  size_t got = std::fread(out, 1, n, s.f);
  s.position = off + uint32_t(got);
  return got == n;
}
static bool load_inputs(const char *path) {
  FILE *f = std::fopen(path, "rb");
  if (!f)
    return false;
  if (std::fseek(f, 0, SEEK_END)) {
    std::fclose(f);
    return false;
  }
  long n = std::ftell(f);
  if (n < 32 || n > 32 * 1024 * 1024) {
    std::fclose(f);
    return false;
  }
  std::rewind(f);
  input_bytes = allocate(nullptr, size_t(n), false);
  if (!input_bytes) {
    std::fclose(f);
    return false;
  }
  bool good = std::fread(input_bytes, 1, size_t(n), f) == size_t(n);
  std::fclose(f);
  if (!good || cc::tree::parse(input_bytes, size_t(n), inputs) !=
                   cc::tree::FixtureError::ok) {
    release(nullptr, input_bytes, false);
    input_bytes = nullptr;
    return false;
  }
  return true;
}
static cc::stream::Error load_scene(const char *path) {
  FILE *f = std::fopen(path, "rb");
  if (!f)
    return cc::stream::Error::read;
  if (std::fseek(f, 0, SEEK_END)) {
    std::fclose(f);
    return cc::stream::Error::read;
  }
  long n = std::ftell(f);
  if (n < 36 || n > long(cc::replay::max_bytes)) {
    std::fclose(f);
    return cc::stream::Error::size;
  }
  std::rewind(f);
  FileSource s{f, 0};
  auto e = cc::stream::load({&s, uint32_t(n), read_file},
                            {nullptr, allocate, release}, scene);
  std::fclose(f);
  return e;
}
static void record(uint32_t phase, uint32_t expected = 0, uint32_t loops = 0) {
  auto &g = g_cc_status011;
  g.phase = phase;
  uint32_t i = g.record_count;
  if (i >= 32) {
    g.error = 9999;
    return;
  }
  MM_STATISTICS m{};
  m.Length = sizeof(m);
  NTSTATUS status = MmQueryStatistics(&m);
  if (status) {
    g.error = 9000;
    return;
  }
  auto &r = g.records[i];
  r.id = i;
  r.phase = phase;
  r.scene = g.scene;
  r.frame = g.frame;
  r.roots = g.roots;
  r.draws = g.draws;
  r.visits = g.visits;
  r.matches = g.matches;
  r.raw_hash = g.raw_hash;
  r.error = g.error;
  r.available = m.AvailablePages;
  r.total = m.TotalPhysicalPages;
  r.allocations = g.allocations;
  r.frees = g.frees;
  r.resident_frames = g.resident_frames;
  r.resident_restores = g.resident_restores;
  r.expected_hash = expected;
  r.loops = loops;
  r.checks = g.tests;
  r.visibility_updates = g.visibility_updates;
  g.record_count = i + 1;
}
#include "backend.inc"
[[noreturn]] static void fail(const char *what, uint32_t error) {
  g_cc_status011.error = error;
  record(9);
  pb_show_debug_screen();
  debugPrint("CC WIDGET011 FAILED: %s (%u) call=%u\n", what, error,
             g_cc_status011.failed_root);
  for (;;)
    Sleep(1000);
}
static void regenerate(bool hide, uint32_t expected) {
  auto r = cc::widget011::frame(inputs, work, scene, resident, hide);
  auto &g = g_cc_status011;
  g.failed_root = r.failed_root;
  g.detail_address = r.address;
  g.quad_error = r.quad_error;
  if (r.error)
    fail("original scene bridge", r.error);
  if (r.roots != inputs.count || r.raw_hash != expected)
    fail("generated packet hash", 8001);
  g.roots = g.roots + r.roots;
  g.draws = g.draws + r.draws;
  g.matches = g.matches + r.matches;
  g.visits = g.visits + r.visits;
  g.raw_hash = r.raw_hash;
  g.dispatches = g.dispatches + r.dispatches;
  g.binds = g.binds + r.binds;
  g.visibility_total = g.visibility_total + (resident.visibility_updates - g.visibility_updates);
  g.visibility_updates = resident.visibility_updates;
  g.resident_frames = r.resident_frames;
  g.resident_restores = r.resident_restores;
  if (r.resident_frames == 1)
    g.restore_total = g.restore_total + 1;
  render(scene, r.draws);
  g.frame = g.frame + 1;
}
int main() {
  auto &g = g_cc_status011;
  g.bytes = sizeof(g);
  XVideoSetMode(640, 480, 32, REFRESH_DEFAULT);
  if (pb_init()) {
    g.error = 1000;
    for (;;)
      Sleep(1000);
  }
  const auto mode = cc::mode009::self_test();
  g.policy_mask = cc::mode009::base_game_mask;
  g.mode_checks = mode.checks; g.mode_passed = mode.passed;
  g.mode_result = mode.full_result; g.mode_cached_flag = mode.cached_flag;
  g.mode_service_calls = mode.service_calls;
  debugPrint("%s\nOriginal full-game predicate: %u; cached: %u; checks: %u/%u\n",
      cc::mode009::build_policy, mode.full_result, mode.cached_flag, mode.passed, mode.checks);
  if (mode.checks != 55 || mode.passed != 55 || mode.full_result != 1 || mode.cached_flag != 1)
    fail("hard-coded base full mode", 9901);
  record(1);
  pb_show_debug_screen();
  Sleep(2000);
  constexpr uint32_t frames = 20;
  const char *resources[]={"D:\\startup.ccr","D:\\menu.ccr","D:\\book.ccr"};
  const char *callers[]={"D:\\startup.cct","D:\\menu.cct","D:\\book.cct"};
  for (uint32_t id = 0; id < 3; ++id) {
    g.scene = id;
    g.resident_frames = 0;
    g.resident_restores = 0;
    g.tests = 0;
    g.visibility_updates = 0;
    resident.reset();
    if (load_scene(resources[id]) !=
            cc::stream::Error::ok ||
        !load_inputs(callers[id]))
      fail("load", 1001);
    if (scene.width() != 640 || scene.height() != 480 ||
        scene.draw_count() != inputs.draws)
      fail("contract", 1002);
    record(3);
    if (id == 0) {
      const uint32_t synthetic_checks = cc::update013::synthetic_chain_test();
      debugPrint("Update013 synthetic chain checks: %u/%u\n", synthetic_checks,
                 cc::update013::synthetic_chain_mask);
      if (synthetic_checks != cc::update013::synthetic_chain_mask)
        fail("update013 synthetic chain", 8130 + synthetic_checks);
      const uint32_t update_checks = cc::update013::captured_boundary_test(inputs, work);
      debugPrint("Update013 captured boundary checks: %u/%u\n", update_checks,
                 cc::update013::captured_boundary_mask);
      if (update_checks != cc::update013::captured_boundary_mask)
        fail("update012 captured boundary", 8120 + update_checks);
    }
    g.tests = cc::widget011::self_test(inputs, work);
    if (g.tests != cc::widget011::control_mask)
      fail("scene error/control test", 7000 + g.tests);
    record(6, g.tests, cc::widget011::control_count);
    pb_show_front_screen();
    for (uint32_t mode = 0; mode < 3; ++mode) {
      for (unsigned i = 0; i < frames; ++i) {
        regenerate(mode == 1, expected_hashes[id][mode]);
        Sleep(10);
      }
      if (g.visibility_updates != mode)
        fail("original visibility transition count", 8011);
      record(10 + mode, expected_hashes[id][mode], frames);
      Sleep(1500);
    }
    if (id < 2) {
      pb_wait_for_vbl();
      while (pb_busy()) {
      }
      scene.reset();
      release(nullptr, input_bytes, false);
      input_bytes = nullptr;
      inputs = {};
      resident.reset();
      record(2);
    }
  }
  if (g.visibility_total != 6) fail("visibility total", 8012);
  g.completed = 1;
  record(5, expected_hashes[2][2]);
  for (;;) {
    render(scene, scene.draw_count());
    Sleep(30);
  }
}
