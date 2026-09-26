// SPDX-License-Identifier: MIT
#pragma once
#include "../runtime006/bridge.h"
namespace cc::tree {
using Context = cc::quad::Context;
using AddressSpace = cc::xbox::AddressSpace;
using Draw = cc::quad::Draw;
using Register = cc::quad::Register;
enum class Error : uint32_t {
  ok,
  entry,
  context,
  memory,
  dispatch,
  texture,
  quad,
  sink,
  capacity,
  unsupported,
  cycle
};
struct Sink {
  void *user{};
  // Implements a real texture-binding boundary, not an original 360 GPU cache.
  bool (*bind)(void *, uint32_t descriptor, const uint32_t words[20]){};
  bool (*submit)(void *, const Draw &){};
};
struct Result {
  Error error{};
  uint32_t address{}, dispatches{}, quad_calls{}, bind_calls{}, submits{},
      quad_error{}, functions{}, tree_visits{}, memory_ops{},
      deepest_dispatch{};
};
// Single-threaded supported scalar caller slice. No full PPC/kernel emulation.
// A failure may leave caller memory changed; the failed frame MUST NOT render.
Result invoke(uint32_t entry, Context &, AddressSpace &, Sink,
              uint32_t budget = 200000) noexcept;
const char *name(Error) noexcept;
} // namespace cc::tree
