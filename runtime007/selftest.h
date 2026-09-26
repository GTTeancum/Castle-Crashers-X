// SPDX-License-Identifier: MIT
#pragma once
#include "fixtures.h"
namespace cc::caller {
// Eight diagnostic scenarios on one observed visible sprite, no GPU submission.
uint32_t self_test(const Fixtures &, Workspace &) noexcept;
} // namespace cc::caller
