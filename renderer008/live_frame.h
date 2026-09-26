// SPDX-License-Identifier: MIT
#pragma once
#include "../renderer005/stream_loader.h"
#include "../runtime008/fixtures.h"
namespace cc::scene008 {
// Only the first full original subtree is persistent here; remaining top-level
// calls are still driven by their captured inputs. Not a live game update loop.
struct Resident {
  cc::tree::Workspace work;
  cc::tree::Case root;
  uint32_t child_head{}, frames{}, restores{};
  const uint8_t *fixture_source{};
  size_t fixture_size{};
  bool ready{}, hidden{};
  void reset() noexcept {
    ready = false;
    hidden = false;
    frames = 0;
    restores = 0;
    child_head = 0;
    fixture_source = nullptr;
    fixture_size = 0;
  }
};
struct Result {
  uint32_t roots{}, draws{}, visits{}, dispatches{}, binds{}, matches{},
      raw_hash = 2166136261u, error{}, failed_root = 0xffffffffu, address{},
      quad_error{}, resident_frames{}, resident_restores{}, checked_writes{};
};
// hide controls the actual head pointer in the resident original scene object.
// It is synthetic diagnostic input, not the original game input/timeline path.
Result frame(const cc::tree::Fixtures &, cc::tree::Workspace &,
             cc::stream::Scene &, Resident &, bool hide,
             cc::replay::Vertex *normalized = nullptr,
             size_t normalized_count = 0) noexcept;
} // namespace cc::scene008
