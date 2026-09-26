// SPDX-License-Identifier: MIT
#pragma once
#include "bridge.h"
namespace cc::caller {
constexpr size_t max_scratch = 16384, max_calls = 4096;
struct Fixtures {
  const uint8_t *bytes{};
  size_t size{};
  uint32_t count{}, scratch{}, draws{};
};
enum class FixtureError { ok, header, size, count, range, context, capacity };
FixtureError parse(const void *, size_t, Fixtures &) noexcept;
struct Workspace {
  Context ctx{};
  AddressSpace memory{};
  uint8_t data[max_scratch]{};
  Workspace() = default;
  Workspace(const Workspace &) = delete;
  Workspace &operator=(const Workspace &) = delete;
};
struct Case {
  const uint8_t *expected{};
  uint32_t texture{}, blend{}, shader{}, projection[16]{};
  uint32_t entry{}, emissions{}, descriptor{}, initial_texture{}, flags{},
      post_counter{};
  uint64_t returned{};
};
FixtureError restore(const Fixtures &, uint32_t, Workspace &, Case &) noexcept;
// Diagnostic changes of upper-caller input. Not original player/camera logic.
Error change_inputs(Workspace &, const Case &, float rotation,
                    uint8_t alpha) noexcept;
} // namespace cc::caller
