#include "generated/__savegprlr_29.inc"
#include "generated/__restgprlr_29.inc"
#include "generated/sub_8208C5D8.inc"
#include "generated/sub_8209CC98.inc"

// ReXGlue's generated PPC trap intrinsic is a non-returning failure path. The
// bounded host runtime reports it as context failure; it never converts a trap
// into success.
static void ppc_trap([[maybe_unused]] Context& ctx, Machine& base, uint32_t code) {
  base.fail(Error::context, code);
}

#include "generated/sub_82097720.inc"

#define HARD_BOUNDARY(sym, addr) \
  static void sym([[maybe_unused]] Context& ctx, Machine& base) { \
    base.fail(Error::unsupported, addr); \
  }
HARD_BOUNDARY(sub_82099A80, 0x82099A80u)
HARD_BOUNDARY(sub_82099968, 0x82099968u)
HARD_BOUNDARY(sub_82097AC8, 0x82097AC8u)
HARD_BOUNDARY(sub_82099680, 0x82099680u)
HARD_BOUNDARY(sub_82094420, 0x82094420u)
HARD_BOUNDARY(sub_820B0F18, 0x820B0F18u)
HARD_BOUNDARY(sub_82084BE8, 0x82084BE8u)
HARD_BOUNDARY(sub_82053A00, 0x82053A00u)
HARD_BOUNDARY(sub_82084D18, 0x82084D18u)
HARD_BOUNDARY(sub_82084DB8, 0x82084DB8u)
HARD_BOUNDARY(sub_8208AE78, 0x8208AE78u)
#undef HARD_BOUNDARY

#include "generated/sub_820915F0.inc"
#include "generated/sub_8209DE50.inc"
