// SPDX-License-Identifier: MIT
#pragma once
#include "../renderer005/stream_loader.h"
#include "../runtime006/fixtures.h"
namespace cc::live {
struct Controls {
  float dx{}, dy{};
  uint8_t alpha = 255;
};
struct Result {
  uint32_t calls{}, baseline_matches{}, raw_hash = 2166136261u, error{},
                                        failed_call{};
};
// All output vertices are regenerated. No replay-vertex fallback. Caller waits
// for GPU idle first. A failure may leave staged vertices partly updated, but
// MUST NOT submit that frame. Optional normalized output is used only by host
// previews/tests, not as the target's input.
Result frame(const cc::quad::Fixtures &, cc::quad::Workspace &,
             cc::stream::Scene &, Controls,
             cc::replay::Vertex *normalized = nullptr,
             size_t normalized_count = 0) noexcept;
} // namespace cc::live
