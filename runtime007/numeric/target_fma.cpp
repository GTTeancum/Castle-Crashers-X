// SPDX-License-Identifier: MIT
// Replace nxdk's currently unimplemented fma symbol, not its entire math
// library. The same object is also linked in a separate host integration-test
// executable.
#include "fused.h"
extern "C" double fma(double x, double y, double z) noexcept {
  return cc::numeric::fused_nearest_fastpath(x, y, z);
}
