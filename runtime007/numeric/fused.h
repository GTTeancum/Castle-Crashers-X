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
// Integer pre-check for the same shortcut (no x87 compares or float
// round trips): x and y are zero, or finite doubles whose exponent lies in
// the float normal range and whose low 29 mantissa bits are zero (exactly
// floats); |z| < 2^1000. Anything it does not accept (float subnormals,
// |z| == 2^1000, non-finite values) goes to fused_nearest_fast, so the
// accepted set and the results are unchanged.
inline bool fused_float_operand(double v) noexcept {
  unsigned long long b; __builtin_memcpy(&b, &v, 8);
  const unsigned hi = unsigned(b >> 32), lo = unsigned(b);
  if (((hi & 0x7FFFFFFFu) | lo) == 0u) return true;
  const unsigned e = (hi >> 20) & 0x7FFu;
  return (lo & 0x1FFFFFFFu) == 0u && e >= 1023u - 126u && e <= 1023u + 127u;
}
inline bool fused_small_addend(double z) noexcept {
  unsigned long long b; __builtin_memcpy(&b, &z, 8);
  return ((unsigned(b >> 32) >> 20) & 0x7FFu) < 1023u + 1000u;
}
inline double fused_nearest_fastpath(double x, double y, double z) noexcept {
#ifdef CC_NO_FMA_FAST  // bisect switch: software path only
  return fused_nearest(x, y, z);
#else
  if (fused_float_operand(x) && fused_float_operand(y) && fused_small_addend(z)) return x * y + z;
  double r;
  return fused_nearest_fast(x, y, z, r) ? r : fused_nearest(x, y, z);
#endif
}
} // namespace cc::numeric
