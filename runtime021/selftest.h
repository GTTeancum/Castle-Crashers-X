// SPDX-License-Identifier: MIT
#pragma once
#include "../runtime008/fixtures.h"
#include <cstdint>
namespace cc::tree {
// WIP 021: host directory containing the files extracted from the retail
// container (used only by the bounded shader-file platform contract).
void set_game_root(const char*) noexcept;
}
namespace cc::update014 {
static constexpr uint32_t captured_boundary_mask = 7;
static constexpr uint32_t synthetic_chain_mask = 7;
uint32_t captured_boundary_test(const cc::tree::Fixtures&, cc::tree::Workspace&) noexcept;
uint32_t synthetic_chain_test() noexcept;
}
