// SPDX-License-Identifier: MIT
#pragma once
namespace cc::numeric {
// Binary64 fused multiply-add, round-to-nearest ties-to-even. This integer
// implementation does not model the host's FP exception flags or NaN payloads.
// Callers must not use it for directed rounding. The scalar bridge establishes
// nearest-even and masked exceptions with FloatScope.
double fused_nearest(double x, double y, double z) noexcept;
// Exact shortcut for the common case (every single-precision fmadds-family
// op): when x and y are finite floats, x*y is exact in binary64 (at most 48
// significant bits, magnitude 2^-298..2^256), so x*y + z rounds once and
// equals the fused result. Finite |z| <= 2^1000 keeps the sum finite; a sum
// below 2^-1022 is a multiple of 2^-1074 and so exact, which rules out
// x87 double rounding in the subnormal range. Requires binary64 precision
// and round-to-nearest (FloatScope); anything else takes fused_nearest.
inline bool fused_nearest_fast(double x, double y, double z, double& out) noexcept {
  if (!(double(float(x)) == x && double(float(y)) == y)) return false;
  if (!(x <= 3.4028234663852886e38 && x >= -3.4028234663852886e38 &&
        y <= 3.4028234663852886e38 && y >= -3.4028234663852886e38 &&
        z <= 0x1p1000 && z >= -0x1p1000))
    return false;
  out = x * y + z;
  return true;
}
inline double fused_nearest_fastpath(double x, double y, double z) noexcept {
  double r;
  return fused_nearest_fast(x, y, z, r) ? r : fused_nearest(x, y, z);
}
} // namespace cc::numeric
