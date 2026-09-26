// SPDX-License-Identifier: MIT
#pragma once
#include "bridge.h"
namespace cc::quad {
constexpr size_t max_scratch = 16384, max_calls = 4096;
struct Fixtures {
  const uint8_t *bytes{};
  size_t size{};
  uint32_t count{}, scratch{};
};
enum class FixtureError { ok, header, size, count, range, context, capacity };
FixtureError parse(const void *, size_t, Fixtures &) noexcept;
struct Workspace {
  Context ctx{};
  cc::xbox::AddressSpace memory{};
  uint8_t data[max_scratch]{};
  Workspace() = default;
  Workspace(const Workspace &) = delete;
  Workspace &operator=(const Workspace &) = delete;
};
struct Case {
  const uint8_t *expected{};
  uint32_t texture{}, blend{}, shader{}, projection[16]{};
};
FixtureError restore(const Fixtures &, uint32_t, Workspace &, Case &) noexcept;
// Test-driver edits of caller inputs, not an original-game movement or
// animation system.
Error change_inputs(Workspace &, float screen_dx, float screen_dy,
                    uint8_t alpha) noexcept;
} // namespace cc::quad
