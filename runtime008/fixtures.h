// SPDX-License-Identifier: MIT
#pragma once
#include "bridge.h"
namespace cc::tree {
constexpr uint32_t max_scratch = 262144, max_roots = 4096,
                   max_file = 32 * 1024 * 1024;
constexpr uint32_t context_bytes = 544, fixed_bytes = 1136, draw_bytes = 176;
struct Fixtures {
  const uint8_t *bytes{};
  size_t size{};
  uint32_t count{}, draws{}, scratch{};
};
enum class FixtureError { ok, header, size, count, range, context, capacity };
struct Workspace {
  Context ctx{};
  AddressSpace memory{};
  uint8_t data[max_scratch]{};
  Workspace() = default;
  Workspace(const Workspace &) = delete;
  Workspace &operator=(const Workspace &) = delete;
};
struct Case {
  uint32_t entry{}, regions{}, bytes{}, draws{}, initial_texture{},
      counter_before{}, counter_after{}, tree_visits{}, dispatches{}, binds{},
      first_draw{};
  bool counter_observed{true};
  const uint8_t *record{};
  const uint8_t *before{};
  const uint8_t *after{};
  const uint8_t *writes{};
  const uint8_t *expected{};
  Context initial{}, post{};
};
uint32_t little32(const uint8_t *) noexcept;
FixtureError parse(const void *, size_t, Fixtures &) noexcept;
FixtureError get(const Fixtures &, uint32_t, Case &) noexcept;
FixtureError restore(const Fixtures &, uint32_t, Workspace &, Case &) noexcept;
// Only compare original tracked NON-stack stores. Callee-saved
// registers/link/SP are compared separately. Untouched bytes and omitted
// GPU-callee stack scratch are not relabeled as original state assertions.
bool check_stores(const Case &, const Workspace &,
                  uint32_t *failed = nullptr) noexcept;
bool callee_saved(const Case &, const Context &) noexcept;
} // namespace cc::tree
