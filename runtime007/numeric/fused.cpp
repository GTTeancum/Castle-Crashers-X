// SPDX-License-Identifier: MIT
#include "fused.h"
#include <cstdint>
#include <cstring>
namespace cc::numeric {
namespace {
constexpr unsigned limbs =
    132; // 4224 bits, covers exact exponents -2148..2047.
constexpr uint64_t fraction = (uint64_t(1) << 52) - 1, sign = uint64_t(1) << 63;
uint64_t bits(double v) {
  uint64_t b;
  std::memcpy(&b, &v, 8);
  return b;
}
double value(uint64_t b) {
  double v;
  std::memcpy(&v, &b, 8);
  return v;
}
struct Number {
  uint64_t m;
  int e;
  bool negative;
  unsigned category;
};
Number unpack(uint64_t b) {
  unsigned e = unsigned((b >> 52) & 2047);
  uint64_t m = b & fraction;
  if (e == 2047)
    return {m, 0, bool(b & sign), m ? 2u : 1u};
  if (!e)
    return {m, -1074, bool(b & sign), 0};
  return {m | (uint64_t(1) << 52), int(e) - 1075, bool(b & sign), 0};
}
struct Wide {
  uint32_t w[limbs]{};
  void insert(uint32_t v, unsigned pos) {
    unsigned i = pos / 32, s = pos % 32;
    w[i] |= v << s;
    if (s && i + 1 < limbs)
      w[i + 1] |= v >> (32 - s);
  }
  bool bit(unsigned i) const { return (w[i / 32] >> (i % 32)) & 1; }
  bool any_below(unsigned end) const {
    for (unsigned i = 0; i < end / 32; ++i)
      if (w[i])
        return true;
    return end % 32 && (w[end / 32] & ((uint32_t(1) << (end % 32)) - 1));
  }
  int top() const {
    for (int i = int(limbs) - 1; i >= 0; --i)
      if (w[i])
        return i * 32 + 31 - __builtin_clz(w[i]);
    return -1;
  }
};
void multiply(uint64_t x, uint64_t y, uint32_t p[4]) {
  uint32_t a[2] = {uint32_t(x), uint32_t(x >> 32)},
           b[2] = {uint32_t(y), uint32_t(y >> 32)};
  for (unsigned i = 0; i < 2; ++i) {
    uint64_t carry = 0;
    for (unsigned j = 0; j < 2; ++j) {
      uint64_t v = uint64_t(a[i]) * b[j] + p[i + j] + carry;
      p[i + j] = uint32_t(v);
      carry = v >> 32;
    }
    p[i + 2] = uint32_t(carry);
  }
}
int compare(const Wide &a, const Wide &b) {
  for (int i = int(limbs) - 1; i >= 0; --i)
    if (a.w[i] != b.w[i])
      return a.w[i] > b.w[i] ? 1 : -1;
  return 0;
}
void add(Wide &a, const Wide &b) {
  uint64_t carry = 0;
  for (unsigned i = 0; i < limbs; ++i) {
    uint64_t v = uint64_t(a.w[i]) + b.w[i] + carry;
    a.w[i] = uint32_t(v);
    carry = v >> 32;
  }
}
void subtract(Wide &a, const Wide &b) {
  uint64_t borrow = 0;
  for (unsigned i = 0; i < limbs; ++i) {
    uint64_t v = uint64_t(b.w[i]) + borrow;
    uint32_t old = a.w[i];
    a.w[i] = uint32_t(uint64_t(old) - v);
    borrow = uint64_t(old) < v;
  }
}
} // namespace
double fused_nearest(double x, double y, double z) noexcept {
  const Number a = unpack(bits(x)), b = unpack(bits(y)), c = unpack(bits(z));
  const bool ps = a.negative != b.negative;
  constexpr uint64_t inf = 0x7ff0000000000000ULL, nan = 0x7ff8000000000000ULL;
  if (a.category == 2 || b.category == 2 || c.category == 2)
    return value(nan);
  if (a.category == 1 || b.category == 1) {
    if ((a.category == 0 && !a.m) || (b.category == 0 && !b.m))
      return value(nan);
    if (c.category == 1 && c.negative != ps)
      return value(nan);
    return value(inf | (ps ? sign : 0));
  }
  if (c.category == 1)
    return z;
  Wide product, addend;
  uint32_t p[4]{};
  multiply(a.m, b.m, p);
  unsigned pos = unsigned(a.e + b.e + 2148);
  for (unsigned i = 0; i < 4; ++i)
    product.insert(p[i], pos + i * 32);
  pos = unsigned(c.e + 2148);
  addend.insert(uint32_t(c.m), pos);
  addend.insert(uint32_t(c.m >> 32), pos + 32);
  bool negative = ps;
  if (ps == c.negative)
    add(product, addend);
  else {
    const int order = compare(product, addend);
    if (!order)
      return value(0); // Exact opposite-sign cancellation, nearest-even.
    if (order > 0)
      subtract(product, addend);
    else {
      subtract(addend, product);
      product = addend;
      negative = c.negative;
    }
  }
  int h = product.top();
  if (h < 0)
    return value(negative ? sign : 0); // Same-sign zero summands.
  unsigned shift =
      h >= 1126 ? unsigned(h - 52) : 1074; // Normal vs subnormal units.
  uint64_t m = 0;
  if (h >= int(shift))
    for (unsigned i = shift; i <= unsigned(h); ++i)
      if (product.bit(i))
        m |= uint64_t(1) << (i - shift);
  const bool guard = product.bit(shift - 1),
             sticky = product.any_below(shift - 1);
  if (guard && (sticky || (m & 1)))
    ++m;
  if (m == (uint64_t(1) << 53)) {
    m >>= 1;
    ++shift;
  }
  uint64_t out;
  if (!m)
    out = 0;
  else if (m < (uint64_t(1) << 52))
    out = m; // Subnormal, including rounded-to-zero above.
  else {
    int exponent = int(shift) - 2148 + 52;
    out = exponent > 1023 ? inf
                          : (uint64_t(exponent + 1023) << 52) | (m & fraction);
  }
  return value(out | (negative ? sign : 0));
}
} // namespace cc::numeric
