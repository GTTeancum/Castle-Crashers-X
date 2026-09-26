// SPDX-License-Identifier: MIT
// Hard-coded, per-port base-game mode. Not a configurable launcher mask.
// The original XAM handler still provides its real completion/return behavior.
#include "generated/default/castle_crashers_pch.h"
#include "../../port009/policy.h"
#include <rex/cvar.h>
#include <rex/system/flags.h>
#include <atomic>
#include <cstdio>
REX_EXTERN(__imp__sub_820B6818);
REX_HOOK_RAW(sub_820B6818) {
  const uint32_t output = ctx.r3.u32;
  const uint32_t overlapped = ctx.r4.u32;
  REXCVAR_SET(license_mask, cc::mode009::base_game_mask);
  __imp__sub_820B6818(ctx, base);
  static std::atomic<unsigned> calls{0};
  const unsigned n = calls.fetch_add(1, std::memory_order_relaxed);
  if (n < 8) {
    // Only inspect successful synchronous output here. No extra pointer writes.
    const uint32_t returned = (!overlapped && ctx.r3.u32 == 0 && output)
        ? REX_LOAD_U32(output) : 0;
    std::fprintf(stderr, "CC009_MODE query=%u policy=%08x result=%08x returned=%08x async=%u\n",
      n + 1, cc::mode009::base_game_mask, ctx.r3.u32, returned, unsigned(overlapped != 0));
    std::fflush(stderr);
  }
}
