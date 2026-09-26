// SPDX-License-Identifier: MIT
#pragma once
#include "policy.h"
#include "../runtime006/bridge.h"
namespace cc::mode009 {
using Context = cc::quad::Context;
using AddressSpace = cc::xbox::AddressSpace;
inline constexpr uint32_t success = 0, invalid_parameter = 87, not_supported = 50;
enum class Error : uint32_t { ok, context, memory, alias };
struct Result { Error error{}; uint32_t full_game{}, cached_flag{}, service_calls{}; };
// Native synchronous replacement. No external configuration or profile lookup.
// Async is explicitly unsupported here; no completion is fabricated.
uint32_t query_license(AddressSpace &, uint32_t mask_address,
                       uint32_t overlapped_address) noexcept;
// Executes the exact original game predicate, with checked caller-owned memory.
// Caller guarantees no concurrent memory-map/data changes. The stack and cache
// must be separately backed and readable/writable. r1/lr must be 32-bit guest values.
Result query_full_game(Context &, AddressSpace &) noexcept;
struct SelfTest { uint32_t checks{}, passed{}, full_result{}, cached_flag{}, service_calls{}; };
// Runs the shared native self-test; never edits the loaded game/fixture memory.
SelfTest self_test() noexcept;
#ifdef CC_MODE009_TEST_SERVICE
// Host tests only. Deliberately not compiled into the Xbox/PC policy.
Result test_query(Context &, AddressSpace &, uint32_t mask, uint32_t result) noexcept;
#endif
}
