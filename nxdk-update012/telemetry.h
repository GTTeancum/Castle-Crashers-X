// SPDX-License-Identifier: MIT
#pragma once
#include <stdint.h>
struct Event011 {
  uint32_t id, phase, scene, frame, roots, draws, visits, matches, raw_hash,
      error, available, total, allocations, frees, resident_frames,
      resident_restores, expected_hash, loops, checks, visibility_updates;
};
struct Status011 {
  char magic[8] = {'C', 'C', 'T', '0', '1', '1', 0, 0};
  uint32_t version = 1;
  uint32_t bytes = 0;
  uint32_t record_count = 0;
  uint32_t frame = 0;
  uint32_t scene = 0;
  uint32_t phase = 0;
  uint32_t completed = 0;
  uint32_t error = 0;
  uint32_t allocations = 0;
  uint32_t frees = 0;
  uint32_t roots = 0;
  uint32_t draws = 0;
  uint32_t visits = 0;
  uint32_t matches = 0;
  uint32_t raw_hash = 0;
  uint32_t failed_root = 0;
  uint32_t detail_address = 0;
  uint32_t quad_error = 0;
  uint32_t dispatches = 0;
  uint32_t binds = 0;
  uint32_t resident_frames = 0;
  uint32_t resident_restores = 0;
  uint32_t restore_total = 0;
  uint32_t tests = 0;
  uint32_t policy_mask = 0, mode_checks = 0, mode_passed = 0, mode_result = 0, mode_cached_flag = 0, mode_service_calls = 0;
  uint32_t visibility_updates = 0, visibility_total = 0;
  Event011 records[32]{};
};
static_assert(sizeof(Status011) == 2696);
static_assert(sizeof(Event011) == 80);
extern "C" {
extern volatile Status011 g_cc_status011;
}
