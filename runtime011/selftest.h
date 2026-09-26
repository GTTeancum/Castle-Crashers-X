// SPDX-License-Identifier: MIT
#pragma once
#include "../runtime008/fixtures.h"
namespace cc::widget011 {
constexpr uint32_t control_count=15, control_mask=(1u<<control_count)-1u;
uint32_t self_test(const cc::tree::Fixtures&, cc::tree::Workspace&) noexcept;
}
