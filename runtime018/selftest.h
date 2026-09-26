// SPDX-License-Identifier: MIT
#pragma once
#include "../runtime008/fixtures.h"
#include <cstdint>
namespace cc::update014 {
static constexpr uint32_t captured_boundary_mask = 7;
static constexpr uint32_t synthetic_chain_mask = 7;
uint32_t captured_boundary_test(const cc::tree::Fixtures&, cc::tree::Workspace&) noexcept;
uint32_t synthetic_chain_test() noexcept;
}
