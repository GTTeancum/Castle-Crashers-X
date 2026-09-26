# Castle Crashers original-Xbox port — Checkpoint 011

## Result

**The original widget-container traversal and enclosing owner renderer now execute in the nxdk Xbox diagnostic.** The retained captured container dispatches its children through the original visibility and rendering virtual slots. Original visibility setter/getter routines hide and restore that container without reloading its object memory. The final rebuilt ISO passed telemetry AND all six visual-state comparisons in xemu configured with 64 MiB.

**This is not live Castle Crashers gameplay, a running original update loop or an interactive Xbox menu.** Initial objects and textures still come from real PC snapshots. Entry registers/output cursors are reset each frame; the retained container's object memory persists. Menu/book text roots outside that container remain per-call snapshots. Visibility changes are synthetic diagnostic controls applied through original functions, not player input or original animation.

The compiled base full-game policy from 009 remains unchanged. This exact XBE again passes **55/55 mode checks and sixteen original predicate calls**, returning/caching 1. Neither the original LIVE container nor firmware was modified.

## 1. Original code and contracts

| New original entry | Extent | Executed role |
|---|---:|---|
| `sub_8209CD08` | 140 bytes | Widget child-list traversal; original visible gate and virtual visibility/draw calls |
| `sub_8209DF48` | 160 bytes | Enclosing owner-stack/global handling, original scene owner, then widget children |
| `sub_8209CE40` | 8 bytes | Original low-byte visibility setter |
| `sub_8209CE48` | 8 bytes | Original visibility getter |

All four generated bodies remain byte-identical to the PC generated source and their pinned originals. The integrated rendering slice has **61 unique original entries** (57 prior + four), plus the two retained mode entries. Entry counts include helpers and are not a game-coverage percentage. The setter was statically identified and independently exercised; unlike the other three, it was not observed as a call inside the captured PC rendering root.

The original ten-slot widget vtable at `0x8204043c` is checked. The bounded adapter validates child-list cycles, owner-stack index limits, guest ranges, dispatch, work budgets and native service failures. The original GPU implementation remains replaced by native texture binding and quad submission. Supported shaders are still 0/5; unimplemented paths fail explicitly. This is not a full PowerPC/SIMD/kernel runtime or a general exception model.

## 2. Actual PC input/output evidence

The opt-in PC observer was extended above the prior owner. Hooks delegate to the unchanged original functions. Capture is read-only with respect to guest state, but adds timing and I/O overhead; first-touch pages are not an atomic whole-process snapshot.

The rebuilt PC executable ran for **621.196 seconds**, with **125 periodic desktop captures**, and was intentionally stopped. Normal keyboard input reached the title flow, local-game book and returned to the full-mode main menu. The first capture request named “menu” was visually identified as the book and classified accordingly; raw bytes were not relabelled to imply a different scene. No new combat, level-clear, audio or save test is claimed.

| Selected state | Actual frame | Root cases | Quads | Recursive scene visits | Largest compact input |
|---|---:|---:|---:|---:|---:|
| Animated title/start snapshot (`startup` file stem) | 724 | 1 | 37 | 52 | 26,880 bytes |
| Full-mode menu | 3040 | 217 | 260 | 32 | 41,408 bytes |
| Local-game book | 1697 | 21 | 121 | 41 | 75,264 bytes |

All **239 captured root cases, 418 emissions and 42,499 tracked non-stack write bytes** match original PC output. Preserved registers, stack/link, counts, projection, texture selection and blend state are checked. Store-byte totals sum comparisons, not unique process memory. Capture totals are **3,990 frame boundaries, 648,157 draw observations and zero read failures**; those are instrumentation counters, not FPS.

The PC executable is **25,134,888 bytes**, SHA-256 `996b8611bb628a17e63a396e7a52adc42677d304e2e24790125782af6905f6de`. The PC uses the existing Xenos/software Vulkan path and a silent audio sink. Its compiled base policy returned 1 even with the deliberately zero launcher mask. The Xbox captures below are not PC screenshots.

## 3. Persistence and original visibility

The first root is restored once per scene, then its whole captured widget container and reachable captured children remain resident for 60 diagnostic frames. The original setter writes the visibility flag and the original getter verifies it. Hidden traversal returns without entering the scene renderer; showing again reproduces exact baseline geometry without a new object-memory restore.

The title snapshot changes **37 → 0 → 37 quads**. The menu changes **260 → 216 → 260**; the book **121 → 20 → 121**. The latter remaining draws are separate text roots outside the retained container. They are not suppressed failed draws or a geometry fallback. Before host rendering, previous vertex/command buffers are poisoned; a corrupted output oracle is rejected, never used to repair geometry.

These controls do not construct new resources, advance a movie timeline or implement original input handling. Fixed workspaces still have two 256 KiB backing capacities plus metadata; the checked map remains 64 regions.

## 4. A visual acceptance failure and its correction

The first target run passed geometry, lifetime and memory telemetry but **failed the image comparisons**. It must not be treated as successful native rendering. A separate read-only QMP/HMP dump of this diagnostic's own book buffers showed **all 36 textures, all GPU vertex bytes and all command bytes matched the host staging**. The emulator was paused for coherent reads and resumed; no guest memory was edited.

The fault was in my checkpoint-cloning edit, not the original game routines: a broad replacement of `010` with `011` accidentally changed the backend's blend selector `0x07010701` and RGBA mask `0x01010101`. Restoring the backend byte-for-byte from Checkpoint 010 fixed the missing artwork. Six dedicated regression methods now reject those mutations and check unchanged native numeric state. The failed images, raw staging readback, source mistake and hashes remain under `logs/checkpoint011/`.

The new provenance checker also initially assumed a direct call. Inspection established the actual `bctrl` word and observed virtual slot; the checker was corrected without changing any original instructions. Two initial regression commands referenced incorrect test filenames; their unsuccessful logs and subsequent real passing runs are kept separately.

## 5. Final target acceptance

The accepted run uses xemu 0.8.136, the user's unchanged debug 4627 BIOS/MCPX, a fresh sparse FATX test HDD in snapshot mode, llvmpipe software OpenGL and a 640×480 guest display on 800×600 Xvfb. QMP and guest kernel counters identify 64 MiB. Firmware/EEPROM/HDD bytes are excluded.

Three scenes each execute 20 baseline, 20 hidden and 20 shown frames. Immutable completion records report:

| Counter/check | Verified result |
|---|---:|
| Diagnostic frames | 180 |
| Original top-level rendering calls | 14,340 |
| Emitted quads / byte-exact comparisons | 21,440 / 21,440 |
| Original recursive scene visits | 5,000 |
| Bounded indirect dispatches | 139,400 |
| Native texture binds | 5,360 |
| Resident restores | Three total, once per scene |
| Original visibility changes | Six total, two per scene |
| Control/error tests | 15 per scene; all masks 32767 |
| Base mask / predicate / cached flag | 1 / 1 / 1 |
| Diagnostic errors | Zero |

These repeat the 239 captured root cases. FNV-32 checks supplement exact vertex comparisons; FNV is not a cryptographic equality proof. The control suite covers invalid entry, work budget, virtual targets, texture/draw rejection, cycles, unmapped/bad links, empty list, invalid stack, overflow and original hide/low-byte behavior.

The final harness ran **45.338 seconds**, retained **79 periodic desktop captures plus a completion image**, validated the complete sequence and intentionally stopped xemu. Exit zero alone is not success. `accept_widget011.py` also requires the executed ISO's hash and every telemetry-gated visual state. The last combined build left accepted binary/ISO hashes unchanged.

### Memory recovery

| Final state | Available pages | Available MiB |
|---|---:|---:|
| Graphics initialized | 14,334 | 55.992188 |
| Title snapshot/caller resources loaded | 12,512 | 48.875000 |
| After title release | 14,334 | 55.992188 |
| Menu/caller resources loaded | 10,648 | 41.593750 |
| After menu release | 14,334 | 55.992188 |
| Final book retained | 9,284 | 36.265625 |

Both completed unloads return to the exact available-page baseline and balance this loader's allocations/frees (12/12, then 38/38 cumulative). The final book intentionally retains 39 allocations. This is not full-game residency, leak freedom across all paths or physical-Xbox performance.

## 6. Visual and regression evidence

Selected PNGs are actual Xbox-executable output in xemu, cropped only at `(80,60)-(720,540)` to remove the unused desktop border. All six visually distinct states compare successfully with the independent CPU rendering: mean absolute RGB-channel differences range **0.000000–0.284536** on a 0–255 scale. Twenty boot/transition captures remain nonmatches. Blank title-hidden output counts only with contemporaneous hidden-state telemetry; blank boot frames do not count. Showing-again state is established by telemetry, not identical pixels alone.

The unsped-up video is **44.5 seconds, 445 frames, 640×480 at a 10 fps recording setting**. The full stream decoded without errors. It shows automatic diagnostic controls, not interactive menus/gameplay. Recording rate and software emulator speed are not original-Xbox FPS.

| Test group | Actual passing result |
|---|---|
| Widget/owner slice | 1,922 assertions per variant; 239 cases / 418 emissions |
| Build variants | ASan/UBSan Debug and optimized Release, each with system and target software FMA |
| Visibility semantics | 43,528 checks per build; all 256 byte values + 4,096 deterministic 64-bit inputs |
| Fixture guards | 12,047 checks per build; 6,000 mutations (1,878 parsed/restored; 4,122 rejected) |
| Arbitrary mutated state | Never executed as game code |
| Host preview identity | All 12 previews byte-identical across four variants |
| Converter / native backend / telemetry methods | 10 / 6 / 15 passed |
| Memory and original leaf | 40,104 assertions; 10,000 model trials; 4,096 leaf inputs |
| Mode policy | 16,502 host assertions; shared target suite 55/55 |
| Software fused multiply-add | 112,202 numerical differential cases against independent system FMA |
| Existing raw converter / switch repair | 18 / 6 methods passed |
| Provenance / native container | 61 original rendering entries verified; four XBE sections; seven ISO files round-trip exactly |
| Final target | Complete nine-phase telemetry AND six visual states passed |

Assertion totals include repeated checks and are not a percentage of game coverage or arbitrary-input security proof. FMA supplies nearest-even value semantics, not complete PPC exception flags/NaN-payload emulation.

## 7. Outputs, reproducibility and next boundary

The accepted **XBE is 634,880 bytes (620 KiB)**, SHA-256 `1874bd245e57023bae9f84d26bf669e793daeac7071fa952b5a7d3ad8ab6dc6e`. The **ISO is 44,367,872 bytes**, SHA-256 `93e6ffd28bc124e71993604223e6800f07e244596a510a83b43ee5ce9a524e76`. `build_widget011.sh` actually ran with prepared offline dependencies, rebuilding/testing host variants, reconverting fixtures and linking/auditing the target. This is not an empty-OS install or full PC campaign acceptance.

The next observed outer renderer is **`sub_820759A8`**, a 732-byte routine. Its call at `0x82075B68` is `bctrl`, returning to `0x82075B6C`; the captured container render slot resolves to `8209CD08`. The neighboring widget vtable slot points to **`sub_8209DE50`**, whose original body takes a floating time input and calls `sub_820915F0` and `sub_8209CC98`, among others. These are **static next-step observations, not additional code running on Xbox**. Original update/resource creation is the more consequential remaining integration gap.

Complete menu/input/timeline execution, dynamic resource creation, broader rendering contracts, audible audio, saves, campaign gameplay and physical hardware remain unverified. The base full-game policy is preserved. Existing inputs suffice; no new upload is requested.

This private checkpoint includes matching source, captured game-derived state/resources, PC/native binaries, actual screenshots/video, failure/success evidence, tests and hashes. Full game/tool distributions, firmware, EEPROM, HDD and user profiles are excluded. All game/emulator/capture/display processes were stopped; finished zombie process records are not running tasks.

## 8. Curated-source verification

The delivered source was copied to `CastleCrashers-Checkpoint-011` and independently rechecked. Original-code provenance, all six backend guards, all fifteen telemetry methods and complete saved-ISO/telemetry/visual acceptance passed there. A fresh relocated ASan/UBSan host configure/build passed the 1,922 widget assertions, 43,528 visibility checks and 12,047 fixture checks. The first copy omitted the reference-preview directory by treating its name as a build cache; the relocated checker refused it. The filter was corrected and the successful recheck is retained. The entire native/PC build was not repeated in the relocated tree; delivered binaries are byte-identical to the accepted target/PC artifacts.
