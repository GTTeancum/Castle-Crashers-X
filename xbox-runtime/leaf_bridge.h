// SPDX-License-Identifier: MIT
#pragma once
#include "guest_memory.h"
namespace cc::xbox {
// Executes only the recovered 40-byte leaf at 0x820B20C8. Not a general PPC runtime.
// Guest r4 is passed as a full 64-bit register. Stack scratch [r1+24,r1+32) is required.
MemoryError run_leaf_820b20c8(AddressSpace& memory,uint32_t stack,uint64_t r4,uint32_t& result);
bool bridge_selftest(unsigned* cases = nullptr);
} // namespace cc::xbox
