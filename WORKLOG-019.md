# Checkpoint 019 worklog

- Resumed from sealed Checkpoint 018 at `sub_820CBBF0` and re-verified the 018 archive SHA-256 before editing.
- Reproduced the 018 1,139-assertion boundary acceptance unchanged before extending it.
- Extracted the exact `sub_820CBBF0` body and its taken resource/helper closure from the sealed generated corpus.
- Added the narrow 640×480 / 60 Hz `VdQueryVideoMode` host contract; an initial adapter argument-order bug failed closed at the exact output pointer and was corrected without altering generated code.
- Switched the 019 development build to the intended Clang family after GCC rejected generated rotate builtins; generated code was not rewritten for GCC.
- Extended the deterministic graphics arena only enough for the exact newly observed allocations.
- Recovered the first `sub_820C44A0` backing request: 1,228,800 bytes (`640*480*4`) with flags `0xBC800000`.
- Recovered both `sub_820C45C0` surface paths and their 240-tile requests.
- Modeled only the fresh two-request `sub_820D62F8` tile-allocation contract because the original uses PPC atomic/global-lock operations absent from the reduced host Context; all other shapes fail closed.
- Verified tile starts 0 and 240, 480 allocated bits, and 5,664 remaining tiles.
- Executed exact `sub_820BE2D8` and `sub_820BE620` binding/state paths for the two created surfaces.
- Executed exact `sub_820D19B8`, graphics notification, `sub_820C9090`, `sub_820BDCA8`, and required gamma/math helpers.
- Proved `sub_820CBBF0` returns successfully through original code and moves `sub_820CC100` to `sub_820CB988`.
- Strengthened acceptance to 1,167 assertions covering all three resource pointers and tile allocator state.
- Provenance increased from 99 to 143 exact local generated bodies plus the inherited startup/renderer diagnostic artifacts.
- Full ASan/UBSan acceptance passed before the combined driver hit its execution window during Release compile. The interrupted Release compile is retained; Release was resumed and all acceptance passed.
- Checked the retained nxdk/xemu harness and the user's saved Library. Native diagnostic source/XBE/ISO remain, but external nxdk plus BIOS/MCPX/EEPROM boot inputs are absent. No new xemu result is claimed.
