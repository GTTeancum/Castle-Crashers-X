// SPDX-License-Identifier: MIT
#include "fused.h"
#include <cfenv>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
static uint64_t bits(double v) {
  uint64_t b;
  std::memcpy(&b, &v, 8);
  return b;
}
static double value(uint64_t b) {
  double v;
  std::memcpy(&v, &b, 8);
  return v;
}
static uint64_t state = 0xcafebabe10203040ULL;
static uint64_t random_bits() {
  state ^= state << 13;
  state ^= state >> 7;
  state ^= state << 17;
  return state;
}
int main() {
  std::fesetround(FE_TONEAREST);
  unsigned cases = 0;
  auto check = [&](double a, double b, double c) {
    double expected = std::fma(a, b, c),
           actual = cc::numeric::fused_nearest(a, b, c);
    ++cases;
    if ((std::isnan(expected) && std::isnan(actual)) ||
        bits(expected) == bits(actual))
      return;
    std::fprintf(
        stderr, "FAIL a=%016llx b=%016llx c=%016llx got=%016llx want=%016llx\n",
        (unsigned long long)bits(a), (unsigned long long)bits(b),
        (unsigned long long)bits(c), (unsigned long long)bits(actual),
        (unsigned long long)bits(expected));
    std::exit(1);
  };
  const uint64_t specials[] = {0,
                               0x8000000000000000ULL,
                               1,
                               0x8000000000000001ULL,
                               0x000fffffffffffffULL,
                               0x0010000000000000ULL,
                               0x3ff0000000000000ULL,
                               0xbff0000000000000ULL,
                               0x7fefffffffffffffULL,
                               0xffefffffffffffffULL,
                               0x7ff0000000000000ULL,
                               0xfff0000000000000ULL,
                               0x7ff8000000000001ULL};
  for (auto a : specials)
    for (auto b : specials)
      for (auto c : specials)
        check(value(a), value(b), value(c));
  check(0x1.0000002p0, 0x1.ffffffcp-1, -1);
  check(1, 0x1p-53, 1);
  check(1, 0x1p-54, 1);
  check(0x1p-1074, 0.5, 0);
  check(0x1p-1074, 1.5, 0);
  for (unsigned i = 0; i < 100000; ++i)
    check(value(random_bits()), value(random_bits()), value(random_bits()));
  for (unsigned i = 0; i < 10000; ++i) {
    double a = value(random_bits()), b = value(random_bits());
    double c = -(a * b);
    check(a, b, c);
  }
  std::printf("PASS fused-nearest cases=%u; bit-exact finite/inf/zero against "
              "host std::fma, NaN class only\n",
              cases);
}
