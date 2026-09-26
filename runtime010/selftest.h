// SPDX-License-Identifier: MIT
#pragma once
#include "../runtime008/fixtures.h"
namespace cc::owner010 {
constexpr uint32_t control_count=12, control_mask=(1u<<control_count)-1;
uint32_t self_test(const cc::tree::Fixtures&, cc::tree::Workspace&) noexcept;
}
