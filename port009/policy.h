// SPDX-License-Identifier: MIT
// Native offline port policy. Only the base-game entitlement bit is provided.
// Not a profile/license-file editor, store client, DLC grant or progression unlock.
#pragma once
#include <cstdint>
namespace cc::mode009 {
inline constexpr uint32_t title_id = 0x584108b7u;
inline constexpr uint32_t base_game_mask = 0x00000001u;
inline constexpr uint32_t cached_full_game_address = 0x82290a90u;
inline constexpr uint32_t query_entry = 0x820a0f88u;
inline constexpr uint32_t license_thunk = 0x820b6818u;
static_assert(base_game_mask == 1u, "This port always selects the base full game.");
inline constexpr char build_policy[] = "CC009:BASE_GAME_FULL:MASK=00000001:TITLE=584108B7";
} // namespace cc::mode009
