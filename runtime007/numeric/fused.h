// SPDX-License-Identifier: MIT
#pragma once
namespace cc::numeric {
// Binary64 fused multiply-add, round-to-nearest ties-to-even. This integer
// implementation does not model the host's FP exception flags or NaN payloads.
// Callers must not use it for directed rounding. The scalar bridge establishes
// nearest-even and masked exceptions with FloatScope.
double fused_nearest(double x, double y, double z) noexcept;
} // namespace cc::numeric
