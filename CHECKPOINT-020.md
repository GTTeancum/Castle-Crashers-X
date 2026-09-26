# Castle Crashers original-Xbox port — Checkpoint 020

## Result

Checkpoint 020 closes the observed lower graphics-device initialization chain through exact/original game code. `sub_820BEFD0` now returns success on the established 640×480 path, and its original success epilogue publishes the lower graphics object through the outer renderer's `renderer+4` output slot.

This is a materially stronger state than Checkpoint 019: the host fixture is no longer stopped inside `sub_820CC100`, and publication is not synthesized by the test harness. The successful store occurs in the exact generated `sub_820BEFD0` body after its callee chain returns success.

Measured deterministic graphics initialization slice:

```text
entry                    sub_820BEFD0
result                   ok / HRESULT 0
exact/generated helpers  17,008
guest memory operations  194,110
lower graphics object    0x02000080 (deterministic host fixture)
renderer+4               0x02000080 (published by original code)
ring                      0x02007140
secondary buffer          0x0200F140
descriptor                0x0220F140
resource +14828           0x02211730
resource +14832           0x0233D770
resource +14824           0x0233DAD0
graphics worker records   2
```

The host addresses are deterministic fixture addresses, not addresses observed on retail hardware or xemu.

## GPU-state initialization closed

The large `sub_820CB988` state fanout is no longer a hard boundary. Checkpoint 020 recovers and executes the exact setter/state family reached by the observed path rather than installing a blanket no-op dispatch table. The chain includes the large state-table initialization, its indirect target family, adjacent exact direct helpers, command-buffer state, and the bounded command-buffer flush/write-pointer path.

The platform write-pointer contract remains narrow: only the observed Xenos `CP_RB_WPTR`-style write shape/order is accepted. It is not a generic GPU MMIO implementation.

The graphics state established in Checkpoint 019 remains intact: the 1,228,800-byte framebuffer-sized backing allocation, both 240-tile surface allocations, all three resource pointers, and the 480 allocated / 5,664 free tiled-memory invariant are preserved.

## EDRAM / HSIO finalization

The observed late-device path now executes exact `sub_820D19E8`, exact `sub_820BDE48`, and exact `sub_820D1C08`.

The true Xbox-kernel/video boundaries are modeled only for the exact branch reached:

- `VdHSIOCalibrationLock` is supplied as the observed 28-byte critical-section-shaped import variable;
- `KeEnterCriticalRegion` / `KeLeaveCriticalRegion` are balanced and sequence checked;
- `VdRetrainEDRAMWorker` accepts only the observed argument shape and returns the modeled successful-path value;
- `VdRetrainEDRAM` accepts only the exact generated arguments/output pointers reached here;
- `VdIsHSIOTrainingSucceeded` is consumed only on this finalization path.

The platform contract is consistent with contemporary open-source Xbox 360 emulator behavior, but it is not promoted to proof of every retail-kernel or hardware behavior. The retry path remains fail-closed because the observed branch does not take it.

Acceptance also verifies the exact late state produced by the original bodies, including the initial invalidated 64-bit device slots, the 41-dword invalidation region, HSIO success state, and timing-derived state written during finalization.

## Next original boundary

After `sub_820BEFD0` returns, the original `PlatformRenderer::Init` frame is still live at guest stack pointer `0x0003ED30`. The generated body resumes at return address **`0x820A7B18`**. The successful HRESULT takes the original branch at `0x820A7B34`, loads the newly published lower device from `renderer+4`, loads sealed float constant `1.0f` from `0x82042544`, and the next unclosed original call is:

- **`sub_820C2C98`**, call instruction `0x820A7B5C`, return `0x820A7B60`.

Observed arguments immediately before that call are the published lower device in `r3`, `r4=0`, `r5=0`, `r6=15`, `r7=0`, `r9=0`, `r10=0`, and `f1=1.0`.

The next direct call after it in the sealed body is `sub_820C13B8`. Neither is claimed closed by this checkpoint.

## Provenance and host acceptance

`runtime020/verify_provenance.py` verifies **297 byte-exact local generated bodies** against the sealed generated corpus, plus the inherited manager slice, complete startup wrapper, renderer-caller prefix, and PlatformRenderer entry prefix.

Final host acceptance:

- boundary/startup/graphics suite: **1,248 assertions**;
- Release CTest: **6/6**;
- ASan/UBSan CTest: **6/6**;
- renderer/widget regression, native-FMA: **1,922 assertions**, 239 roots, 418 draws, 125 tree visits, 42,499 checked store bytes;
- renderer/widget regression, software-FMA: the same **1,922 assertions** and counts;
- visibility regression: **43,528 checks** over 4,352 inputs;
- fixture regression: **12,047 checks + 6,000 mutations**, 1,878 restore-only accepts, 4,122 rejects, and no mutated game state executed.

The clean combined acceptance driver completed all ASan/UBSan phases, then was stopped by the execution window during Release compilation. The partial compile is retained; Release was resumed from the same clean configured tree and all Release acceptance completed successfully. This timeout is not recorded as a regression pass or failure.

## New native / xemu regression

A new actual xemu regression was executed in this work turn after the user supplied BIOS/MCPX/EEPROM material.

The retained Checkpoint 011 original-Xbox diagnostic ISO was run with:

- xemu lineage **`0.8.136-15-gc231997`**;
- xemu binary SHA-256 `15e102b7a3353fbfaa42a0a9866f1cff6f96526d5ec8c8247a10b49a84132707`;
- supplied `Complex_4627.bin` BIOS SHA-256 `34f1c8ded59116436065783f8ad2ef0939df3cbfc76277ec9e5c41bf9ccb93cd`;
- supplied `mcpx_1.0.bin` SHA-256 `e99e3a772bf5f5d262786aee895664eb96136196e37732fe66e14ae062f20335`;
- retained `CastleCrashers-Widget011.iso` SHA-256 `93e6ffd28bc124e71993604223e6800f07e244596a510a83b43ee5ce9a524e76`;
- 64 MiB guest RAM;
- a sparse 8 GiB FATX test HDD in snapshot mode;
- software OpenGL/Xvfb as in the retained diagnostic lineage.

The diagnostic completed intentionally with emulator return code 0 and telemetry validation passed. It executed **180 diagnostic frames** with aggregate telemetry:

- roots: **14,340**;
- draws: **21,440**;
- scene visits: **5,000**;
- matches: **21,440**;
- original visibility changes: **6**;
- resident restores: **3**;
- initial and post-menu-release available pages: **14,391**.

All three scene baseline/hidden/shown phases completed; baseline and shown packet hashes agree per scene. This remains an **original-Xbox diagnostic regression**, not live Castle Crashers gameplay and not proof of Xbox 360 Xenos `Vd*` equivalence.

This new run is not the same firmware/emulator tuple as the historical Checkpoint 011 acceptance: Checkpoint 011 used the user's separate debug 4627 BIOS and official xemu 0.8.136. The newly supplied Complex BIOS has a different hash, and this run uses a development lineage 15 commits after 0.8.136. Both results are kept distinct.

A fresh nxdk XBE rebuild was **not** completed in this scratch environment because the large external nxdk/buildkit tree was not retained in the portable checkpoints and shell network access is unavailable. The actual new xemu run therefore re-executes the retained, previously built Checkpoint 011 diagnostic ISO. Private firmware and HDD bytes are excluded from this checkpoint; only hashes and execution evidence are retained.

## Scope

Checkpoint 020 proves lower graphics-device initialization and original publication in the host convergence path, plus a fresh native/original-Xbox diagnostic regression. It does **not** yet prove completion of `PlatformRenderer::Init`, live native PC gameplay, a retail Xbox 360 Xenos device, or an updated nxdk build of the newly recovered host graphics chain.
