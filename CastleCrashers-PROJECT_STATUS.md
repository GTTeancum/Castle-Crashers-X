# Castle Crashers Xbox Build â€” PROJECT_STATUS.md

> **AUTHORITATIVE CONSTANT HANDOFF FILE**
>
> This is the portable source of truth for continuing the Castle Crashers Xbox-only build project across turns and chats. The source behavior is recovered from the Xbox 360 version, while the deliverable is an Xbox XBE/ISO validated in xemu and, where possible, on hardware. If this file appears in a fresh chat, do not ask the user to reconstruct prior history.
>
> **Accepted resume triggers:** `continue` or `go`.
>
> **CURRENT USER TURN-SIZE OVERRIDE:** The user explicitly requested **smaller focused turns** because long runs keep timing out. Prefer one coherent engineering boundary plus focused verification per turn; do not launch long combined acceptance/build jobs unless needed to seal a checkpoint.

---

## 1. Mandatory continuation protocol

### At the start of every Castle Crashers work turn

1. Read this entire file before changing code or making project claims.
2. Treat **CURRENT VERIFIED STATE**, **CURRENT BOUNDARY**, and **NEXT_ACTION** as authoritative unless newer attached evidence proves otherwise.
3. On `continue` / `go`, immediately resume from `NEXT_ACTION`.
4. Do not re-plan completed work or ask the user to repeat known information.
5. Recover and verify the newest checkpoint before editing.
6. Keep unknown/unverified behavior fail-closed. Never fake device/resource/gameplay/XEMU success to advance the instruction pointer.

### During the turn

- Prefer exact original bytes / byte-exact generated ReXGlue bodies over synthetic behavior.
- Platform shims must be narrow, argument/order/state asserted, and reject unobserved shapes.
- Preserve provenance against the sealed corpus.
- Run relevant regressions after meaningful closure.
- Distinguish diagnostic-harness convergence, runtime capture replay, freshly built nxdk/Xbox artifacts, xemu execution, and real Xbox gameplay/hardware behavior.
- Do not silently promote emulator behavior to retail Xbox 360 hardware/kernel proof.

### At the end of every turn

1. Update this file with the newest checkpoint, exact proof, boundary, tests, artifacts/checksums, and `NEXT_ACTION`.
2. Replace/save canonical `CastleCrashers-PROJECT_STATUS.md`.
3. Read the updated file completely before the final chat response.
4. Make `NEXT_ACTION` executable by a fresh chat without hidden context.

---

## 2. Project goal

Continue the Castle Crashers Xbox-only build effort, using recovered Xbox 360 game behavior as source evidence while targeting an Xbox XBE/ISO that reaches actual gameplay in xemu and, where possible, on hardware.

The diagnostic ReXGlue harness exists only to recover, execute, and verify exact game behavior needed by the Xbox build. It is not a product target.

Principles:

- Execute original/generated game code rather than replace game semantics with approximations.
- Use diagnostic/platform shims only at true platform boundaries; the diagnostic harness is recovery tooling, not the deliverable.
- Fail closed on unknown behavior.
- Preserve reproducibility, provenance, regression coverage, and checkpoint integrity.
- Do not claim completed `PlatformRenderer::Init`, live Xbox gameplay, retail Xenos behavior, or a fresh Xbox rebuild unless actually demonstrated.

---

## 3. CURRENT VERIFIED STATE

### Latest sealed checkpoint

**Checkpoint 020**

Artifacts:

- `CastleCrashers-Checkpoint-020.zip`
- `CastleCrashers-Checkpoint-020.sha256`

Checkpoint ZIP SHA-256:

`d61b2ed0329abaed1a5dbe9661227e279f6864ee4af8508face7c07289e411eb`

Archive/inventory verification:

- ZIP CRC test: passed; no compressed-data errors.
- `package-manifest020.json`: **4,637** inventoried project files.
- `CHECKSUMS-020.sha256`: **4,638** entries (includes the package manifest, excludes itself), all verified before packaging.
- ZIP payload files: **4,639** (project files + package manifest + checksum set).
- Inventoried project bytes: **432,606,770**.
- ZIP size: **75,131,104 bytes**.
- CMake caches/intermediate object trees excluded.
- Private BIOS/MCPX/EEPROM/HDD bytes excluded.
- Large external emulator/toolchain distributions excluded.

### Inherited startup / renderer facts still valid

- `sub_820701D0` executes entry-to-return:
  - 182,963 generated/helper executions,
  - 10,501 original indirect/virtual dispatches,
  - 2,670,630 guest-memory operations.
- Original live update-manager construction/publication is preserved.
- Five original startup worker records complete the observed create/priority/affinity/resume lifecycle without pretending infinite worker loops ran concurrently.
- 613-entry lookup table verified.
- 10,500-object state pool verified and published at `0x8225E608`.
- Region/system state publishes at `0x8225E63C`.
- Control returns into original `sub_82070AC8`.
- Renderer object is 30,216 bytes; exact constructor publishes it at `0x8225E628`.
- `PlatformRenderer::Init` consumes the deterministic original 640Ã—480 / 60 Hz presentation state.
- Sealed refresh threshold remains 58.0 Hz (`0x42680000`).

### Checkpoint 018 graphics facts retained

- `sub_820BEFD0` allocates a **24,064-byte** lower graphics object with **128-byte alignment** from a 24,192-byte raw allocation.
- Raw pointer is stored at `object-4`; object is zeroed/initialized through original code.
- Observed graphics flags: `0x0C000000`.
- Exact default ring from `sub_820C7548`:
  - 32 KiB primary ring,
  - 2 MiB secondary buffer,
  - 64 KiB secondary chunks,
  - primary dword capacity minus one = 8,191,
  - secondary dword capacity = 524,288.
- Initial 19-word ring descriptor contract verified.
- Exact `sub_820BEAC8` command/state allocations complete.
- Exactly two graphics-worker records are created for `0x820D7578`, with 64 KiB stacks and priority 17; asynchronous worker routines are not executed.

### Checkpoint 019 resource/presentation facts retained

The exact 640Ã—480 `sub_820CBBF0` path creates three resource-like objects through original/generated game code:

1. `sub_820C44A0`:
   - 52-byte resource header;
   - backing allocation **1,228,800 bytes (`0x12C000`)**, flags `0xBC800000`;
   - size equals `640 Ã— 480 Ã— 4`;
   - published at graphics-object offset **14,828**;
   - deterministic diagnostic-fixture pointer `0x02211730`.
2. First `sub_820C45C0` surface:
   - 48-byte object;
   - 240-tile allocation;
   - published at offset **14,832**;
   - pointer `0x0233D770`.
3. Second `sub_820C45C0` surface:
   - 48-byte object;
   - another 240-tile allocation;
   - published at offset **14,824**;
   - pointer `0x0233DAD0`.

Observed format/state constants remain `0x28280106`, `0x18280186`, and `0x2D200196`. Do not assign stronger backbuffer/render-target semantics than the recovered code proves.

Tiled allocator invariant:

- capacity: 6,144 tiles;
- first 240-tile request â†’ start tile 0;
- second 240-tile request â†’ start tile 240;
- 480 bits allocated;
- 5,664 tiles free.

`sub_820CBBF0` returns successfully through original code, including exact resource binders, presentation notification, and gamma/state generation.

### New Checkpoint 020 lower-device closure

Checkpoint 020 closes the previously unsupported `sub_820CB988` state fanout and the observed remainder of the lower-device initialization chain.

Verified measured slice for exact `sub_820BEFD0`:

- result: **success / HRESULT 0**;
- generated/helper executions: **17,008**;
- guest-memory operations: **194,110**;
- lower graphics object: `0x02000080` (deterministic diagnostic fixture);
- primary ring: `0x02007140`;
- secondary buffer: `0x0200F140`;
- descriptor: `0x0220F140`;
- graphics workers: 2;
- resource pointers: `0x02211730`, `0x0233D770`, `0x0233DAD0`.

Most importantly:

- **original `sub_820BEFD0` publishes `0x02000080` through `renderer+4`;**
- publication is not test-side synthetic state;
- the original `PlatformRenderer::Init` frame remains live after the return, with guest `r1 = 0x0003ED30` and `r3 = 0`.

The large `sub_820CB988` GPU-state fanout is no longer a hard boundary. Checkpoint 020 recovers/executes the actual setter/state family reached by this deterministic path rather than using a blanket no-op table.

The exact command-buffer/flush family reached by this state setup is also closed for the observed path, with only the narrowly bounded platform write-pointer/MMIO contract modeled at the true platform boundary.

### EDRAM / HSIO finalization

The observed late initialization path now executes exact:

- `sub_820D19E8`;
- `sub_820BDE48`;
- `sub_820D1C08`.

The required platform/runtime contracts are deliberately narrow:

- loader-resolved `VdHSIOCalibrationLock` is supplied as the observed 28-byte critical-section-shaped variable;
- `KeEnterCriticalRegion` / `KeLeaveCriticalRegion` are balanced and sequence checked;
- `VdRetrainEDRAMWorker` accepts only the observed call shape;
- `VdRetrainEDRAM` accepts only the exact generated argument/output shape reached here;
- `VdIsHSIOTrainingSucceeded` is consumed only on this path;
- the retry path remains fail-closed because the observed branch does not take it.

Acceptance checks the resulting late-state invalidation/timing fields rather than merely advancing the instruction pointer.

### Checkpoint 020 provenance and diagnostic-harness acceptance

- **297 byte-exact local generated bodies** verified against the sealed generated corpus.
- Plus four inherited original diagnostic artifacts:
  - manager slice,
  - full startup wrapper,
  - renderer caller prefix,
  - PlatformRenderer entry prefix.
- Boundary/startup/graphics suite: **1,248 assertions**.
- Release CTest: **6/6**.
- ASan/UBSan CTest: **6/6**.
- Renderer/widget regression, FMA-enabled and software-FMA variants:
  - **1,922 assertions each**,
  - 239 roots,
  - 418 draws,
  - 125 tree visits,
  - 42,499 checked store bytes.
- Visibility regression:
  - **43,528 checks** over 4,352 inputs.
- Fixture regression:
  - **12,047 checks + 6,000 mutations**,
  - 1,878 restore-only accepts,
  - 4,122 rejects,
  - mutated game state never executed.

Acceptance-log note:

The clean combined 020 driver completed all ASan/UBSan acceptance and then hit the execution window during Release compilation. The timeout is retained explicitly. Release compilation resumed from that same clean configured tree and all Release CTest/direct regressions subsequently passed. Do not interpret the driver timeout as either a test failure or a hidden success.


### Unsealed focused continuation after Checkpoint 020 (WIP 021)

A deliberately small continuation is in progress after Checkpoint 020. **Checkpoint 020 remains the latest sealed baseline.** The newest overlay is preserved separately as `CastleCrashers-WIP-021-85e8.zip`; it is self-contained relative to Checkpoint 020 but is not sealed checkpoint acceptance.

Current refreshed WIP ZIP SHA-256:

`7f950085e0911ae002c809507c0353a3b7cd934f0c0ad15002b0447150e4f67c`

Focused progress now established:

- clean pre-edit Release reproduction matched the carried CF858 handoff exactly at `unsupported@821368C0`, **851 generated/helper executions**, **19,157 guest-memory operations**, and **3,978 assertions**;
- exact `sub_820CF728` remains byte-for-byte unchanged, SHA-256 `8bb7efc53f4e5fdf60d6827b1166defdf7294b45fa1d4729c83976d8c6395718`;
- exact `sub_820CF9D0` remains byte-for-byte unchanged at **10,770 bytes**, SHA-256 `2a44d5bcbbedae513828fd3bfff38825c5fec561aa1dd558d637fef286fb6852`;
- exact `sub_820CF858` remains byte-for-byte unchanged at **5,859 bytes**, SHA-256 `ad4094e5aa8c81a8abb8b143c8e39a4c3278ccffc6853a78a9a2f658028c5a83`;
- exact `sub_821368C0` is now recovered byte-for-byte from sealed `pc/generated/default/castle_crashers_recomp.11.cpp`: **659 bytes**, SHA-256 `3f548f0368b98565f5d7a2d09f7f2fb8cd77f51d9744a904e4f9b7c14108f48d`;
- on the observed loader state, `[0x8200068C] = 0x02500004` and `[0x02500004] = 0`, so exact `sub_821368C0` takes its null-service branch, returns `r3=0`, and performs no indirect dispatch;
- exact `sub_820CF858` therefore skips still-fail-closed `sub_820CD258`, completes normally, and exact `sub_820C13B8` fully unwinds back to the live `PlatformRenderer::Init` frame;
- a separately provenance-checked original-code continuation slice now resumes sealed `sub_820A7990` at **0x820A7B34**, the already-proven successful post-graphics branch, and executes through the first later indirect call at `lr=0x820A7BC8`; the executed instruction fragment is copied byte-for-byte from the sealed generated source, while its wrapper scaffolding is diagnostic-only and is not counted as an exact original function body;
- that caller continuation executes the first suffix `sub_820C2C98`, exact `sub_820C13B8` (including exact `sub_821368C0`), then the second exact `sub_820C2C98` before resolving renderer vtable slot `+28` to **`0x820A85E8`**;
- focused optimized Release result is now `dispatch@820A85E8`, **964 generated/helper executions**, **21,113 guest-memory operations**;
- live boundary state: `r1=0x0003ED30`, `lr=0x820A7BC8`, `r3=renderer=0x00501060`, `r6=ctr=0x820A85E8`, `r7=480`, `r8=640`, `r9=0x82042048`, `r10=0x82040000`;
- renderer durable presentation fields immediately before the vtable call are `renderer+28720=640` and `renderer+28724=480`;
- exact second suffix setter advances the durable command write pointer to `device+48=0x0201F73C`; `device+52=0x0202F37C`, `device+56=0x0202F2DC`, `device+14928=0x0201F380`, `device+14916=0x0202F40C`, and `device+14932=0x54` are acceptance-bound at the new boundary;
- transient stack words previously used by VdPersistDisplay/VdGetSystemCommandBuffer are no longer treated as durable after the later second setter legitimately reuses that stack region;
- focused Release `update_boundary` passes **3,974 assertions**;
- complete Release CTest passes **6/6**, including visibility, update provenance, vtable provenance, capture-source verification, and generated-seal verification;
- local provenance is now **338 exact generated bodies**, plus the four inherited original diagnostic artifacts and the separately verified `sub_820A7990` post-graphics continuation slice; generated game bodies were not edited;
- all previous persist/free/retrain/CF9D0/ring/resource/tile/HSIO invariants remain intact.

XEMU was **not** re-run for this increment. The currently reusable runnable ISO is still the retained Checkpoint 011 Widget011 diagnostic artifact; it does not contain this WIP 021 suffix. Prefer a fresh XEMU run once a newly built nxdk XBE/ISO actually incorporates current WIP code.

Sanitizer re-validation for the newer WIP 021 suffix and the full inherited renderer/widget/fixture sealing matrix remain pending. Therefore this WIP must not yet be promoted to Checkpoint 021.

### WIP 021 continuation â€” exact sub_820A85E8 closed (2026-09-25, Windows environment)

The project moved to a Windows 11 host and is now a git repository pushed to the private GitHub remote `GTTeancum/Castle-Crashers-X` (the retail LIVE package and emulator firmware are excluded by `.gitignore`; `.gitattributes` disables all line-ending conversion because sources are checksum-sealed). Toolchain: Clang 22.1.2 (`x86_64-pc-windows-msvc`), CMake 4.3.1, VS 2022-bundled Ninja, `-D_CRT_SECURE_NO_WARNINGS` added via `CMAKE_CXX_FLAGS` (CRT deprecation warnings under `-Werror`; no source edits). The full prior WIP 021 state was reproduced exactly on this toolchain before editing: `dispatch@820A85E8`, 964/21,113, 3,974 assertions, Release CTest 6/6.

New closure:

- exact `sub_820A85E8` recovered byte-for-byte from sealed `pc/generated/default/castle_crashers_recomp.4.cpp`: **2,317 bytes**, SHA-256 `b8c496093f943ce7276b65c6662f0a9872e8bfc21d8b4ed07105e2d42e589e5c`; registered in `bodies.inc`/`decls.inc`/`dispatch.inc` with no semantic edits;
- on the observed state the guard byte `renderer+28715` is still **0** (original code only stores it later at `stb r29,28715(r31)` after the 17-iteration loop), so the exact body takes its `beqlr cr6` early return: **no stores, no indirect dispatch**; the color-byte path to `renderer+28736..28739` was not taken and those bytes are acceptance-bound as still zero;
- focused Release result: `platform_post_graphics result=ok`, **965 generated/helper executions, 21,114 guest-memory operations** (exactly +1/+1 over the prior boundary);
- focused Release `update_boundary`: **3,976 assertions** (two new observed-branch bindings);
- Release CTest **6/6**; local provenance now **339 exact generated bodies**;
- ASan/UBSan matrix re-validated on this increment: CTest **6/6**, widget FMA + software-FMA **1,922 assertions each**, fixture **12,047 checks + 6,000 mutations**. Windows notes: ASan requires the release CRT (`CMAKE_MSVC_RUNTIME_LIBRARY=MultiThreadedDLL`) and `-D_DISABLE_STRING_ANNOTATION -D_DISABLE_VECTOR_ANNOTATION` (VS ASan STL-annotation lib not installed); sanitizer coverage of the generated/game code itself is unaffected.

The dispatch boundary at the renderer vtable is therefore closed. The new boundary is the original caller continuation at `lr=0x820A7BC8` inside `sub_820A7990`: the diagnostic post-graphics slice still ends at the indirect call, and the first unrecovered original call beyond it is `sub_820AA5B8` (17-iteration loop), followed by `sub_82129FA0`*, `sub_82129A70`*, `sub_820A8190`, `sub_820BB6A8`*, `sub_820BFEE8`, `sub_820BFC30`, `sub_820C00B8`, `sub_820BD0F8`* (* = already recovered).

### WIP 021 continuation â€” full shader-descriptor loop closed (2026-09-26)

The `sub_820A7990` continuation slice now runs byte-exact from `0x820A7B34` through the closed vtable call, the presentation-state stores, the complete 17-iteration `loc_820A7BF0` shader-descriptor loop, and the post-loop setup (`stb r29,28715`, exact `sub_82129FA0`, exact `sub_82129A70`), stopping fail-closed before `bl 0x820A8190`. Focused Release result: **`platform_post_graphics result=ok`, 2,231 generated/helper executions, 66,888 guest-memory operations, 3,999 `update_boundary` assertions**; Release CTest **6/6**; ASan/UBSan CTest 6/6 plus widget (1,922Ã—2) and fixture (12,047+6,000) regressions.

Newly recovered byte-exact bodies (all verified against the sealed corpus by `verify_provenance.py`; local provenance now **391 exact generated bodies**): `sub_820AA5B8`, `sub_820AA488`, `sub_820B64E0`, `sub_820B6310`, `sub_820B6498`, `sub_820B6AD8`, `sub_820B75C0`, `sub_820B7278`, `sub_820B73C8`, `sub_820B7290`, `sub_820B6CD0`, `sub_820B7630`, `sub_820B7BC0`, `sub_820B7880`, `sub_820B93B0` (RtlCreateHeap family), `sub_8212A760`, `sub_82128F70` (malloc) plus the full statically linked heap internals (`sub_820B7BC8/7D88/7EA8/8138/8540/8CA0/8E08/9048/9958/BA1D4/BA228/BA4C8/BB280`, `sub_82129470/82129880/8212A040/8212A2E8/8212A3B8/8212C298/8212C368/8212C3B0/8212E140/8212E218/8212EC50/821294E0/821325C0`), `sub_82136390`/`sub_82138200` (XMemCpy), and the shader-object creators `sub_820BFDF0`, `sub_820C0440`, `sub_820C0330`, `sub_820C00D0`, `sub_820C01C0`.

The exact CRT heap is now created by original code (`sub_820B7880` executed as harness pre-step, handle published at `0x82290B3C`, first reservation at fixture arena `0x04000000`) and serves all original allocations on this path. New narrow platform contracts, each fail-closed outside its observed shape: `NtCreateFile`/`NtQueryInformationFile`/`NtReadFile`/`NtClose` (bounded to `game:\shaders\<name>` backed by files extracted from the retail container into gitignored `game-data/extracted/` via `castle-crashers-port/tools/extract_stfs.py`), `NtAllocateVirtualMemory`/`NtFreeVirtualMemory` (fixture arena; free still fail-closed), `RtlInitAnsiString` (exact semantics), `RtlNtStatusToDosError` (only `0xC0000034`â†’2), `RtlCompareMemoryUlong`, `KeTlsGetValue`/`KeTlsSetValue` (64 bounded slots), `RtlInitializeCriticalSection` extended with a registry consumed by enter/leave, kernel debug trap 20 (`DbgPrint`) as logged no-op, `KeBugCheck(Ex)`/`RtlRaiseException`/`RtlImageXexHeaderField`/`NtWaitForSingleObjectEx` fail-closed, and the `XexExecutableModuleHandle` loader variable fixture-resolved to a null module. The sealed 15-shape graphics allocator gained a documented WIP 021 shader phase (flags `0x24800000`/`0xB5800000`, â‰¤64 KiB). Kernel-side allocator/TLS/CS state now persists across diagnostic invocations (file-scope fixtures), matching hardware persistence. Two ReXGlue VMX helpers (`VectorShiftTableL`, `vperm`) were added to the host bridge with PPC big-endian semantics, validated end-to-end by binding the exact `GenericVS.xvu` microcode bytes XMemCpy produced in guest memory.

Observed and bound original behavior: 15 of 17 shader pairs load and create vertex/pixel shaders and vertex declarations; the sealed name table's `SobelEdge.xpu` and `VertexColorFillPS.xpu` are absent from the retail container (per the sealed container manifest), so those iterations take the original `STATUS_OBJECT_NAME_NOT_FOUND` error path, exactly as on hardware. Durable bindings include the descriptor table at `renderer+29836` (slot 0 success with nonzero shader/declaration pointers), `renderer+30176/30208`, guard byte `renderer+28715=1`, and the copied microcode header words at `0x0233DE68`.

## 4. XBOX / XEMU STATUS

### Persistent Xbox/XEMU test kit

Future turns should prefer the persistent Library folder **`/CastleCrashers-Xbox-TestKit`** rather than depending on old chat attachments. It now contains the reusable project/Xbox inputs plus the exact emulator/firmware tuple used for the fresh validation below.

Persistent project/Xbox artifacts include:

- `Project/CastleCrashers-Checkpoint-020.zip` + checksum;
- `Project/CastleCrashers-WIP-021-updated.zip` + checksum (older persistent copy; newest conversation handoff is `CastleCrashers-WIP-021-85e8.zip`);
- `Project/CastleCrashers-PROJECT_STATUS.md`;
- `Xbox/CastleCrashers-Widget011.iso`;
- `Xbox/CastleCrashers-Widget011.xbe`;
- `Xbox/XEMU-FRESH-20260925-REPORT.md` and fresh run evidence files.

Persistent emulator/firmware artifacts include:

- `Emulator/Xemu.7z` â€” user-supplied firmware bundle, SHA-256 `4f042bb128362c6b32aec8d160873b4642f6c4fe3716079a5d9a525cebe1d468`;
- `Emulator/xemu-ubuntu-x86_64-release-c231997.zip` â€” GitHub Actions artifact for commit `c231997ef0fefc47e535cdb82ff9237c04e85769`;
- `Emulator/xemu-0.8.136-15-gc231997ef0-x86_64.AppImage`;
- `Emulator/Complex_4627.bin`;
- `Emulator/mcpx_1.0.bin`;
- `Emulator/eeprom.bin`;
- `Emulator/SHA256SUMS.txt`.

Validated tuple hashes:

- XEMU extracted binary SHA-256 `15e102b7a3353fbfaa42a0a9866f1cff6f96526d5ec8c8247a10b49a84132707`;
- Complex 4627 BIOS SHA-256 `34f1c8ded59116436065783f8ad2ef0939df3cbfc76277ec9e5c41bf9ccb93cd`;
- MCPX 1.0 SHA-256 `e99e3a772bf5f5d262786aee895664eb96136196e37732fe66e14ae062f20335`;
- EEPROM SHA-256 `01086645b94346e7e99ea33951d2bbf16e25dce833ef3e10362fb9b25edd5d51`;
- retained `CastleCrashers-Widget011.iso` SHA-256 `93e6ffd28bc124e71993604223e6800f07e244596a510a83b43ee5ce9a524e76`.

Do not silently substitute a different emulator or firmware tuple for direct baseline comparisons.

### Fresh actual XEMU execution â€” 2026-09-25

A **new XEMU process was actually executed** on 2026-09-25 after the firmware bundle was re-uploaded. This is fresh evidence, not a recovered screenshot or stale result.

Fresh tuple:

- XEMU `0.8.136-15-gc231997ef0`;
- commit `c231997ef0fefc47e535cdb82ff9237c04e85769`;
- extracted XEMU binary SHA-256 `15e102b7a3353fbfaa42a0a9866f1cff6f96526d5ec8c8247a10b49a84132707`;
- Complex 4627 BIOS / MCPX / EEPROM hashes exactly as listed above;
- retained `CastleCrashers-Widget011.iso` SHA-256 `93e6ffd28bc124e71993604223e6800f07e244596a510a83b43ee5ce9a524e76`;
- 64 MiB guest RAM;
- freshly generated sparse 8 GiB FATX HDD in XEMU snapshot mode;
- Xvfb 800x600;
- Mesa llvmpipe software OpenGL;
- 5-second telemetry/capture interval to match the historical Checkpoint 020 baseline.

Fresh result:

- emulator return code: **0**;
- stop reason: **diagnostic completed; requested stop**;
- telemetry validation: **passed**;
- completed / error: **1 / 0**;
- mode checks: **55/55 passed**;
- diagnostic frames: **180**;
- roots: **14,340**;
- draws: **21,440**;
- scene visits: **5,000**;
- matches: **21,440**;
- dispatches: **139,400**;
- binds: **5,360**;
- original visibility changes: **6**;
- resident restores: **3**;
- available pages initial / after menu release: **14,391 / 14,391**.

All nine baseline/hidden/shown phases across the three diagnostic scenes completed successfully with exactly the retained packet hashes:

- scene 0 baseline/shown `cba599f9`, hidden `811c9dc5`;
- scene 1 baseline/shown `3c3dff7b`, hidden `662e8ebd`;
- scene 2 baseline/shown `992e2ac3`, hidden `4279c201`.

Fresh timing/performance baseline:

- total XEMU/harness wall time: **49.637 s**;
- first valid telemetry: **6.120 s**;
- completion telemetry: **46.450 s**;
- effective initialized-to-completion diagnostic throughput: **4.463 guest frames/s**;
- median non-zero 5-second polling-interval throughput: **4.173 guest frames/s**.

Historical Checkpoint 020 run with the same XEMU/firmware/ISO tuple measured **49.855 s** total and **4.468 guest frames/s** effective throughput. Fresh delta is **0.218 s faster (0.44%)** total and **0.11% lower** effective diagnostic throughput. Treat this as essentially unchanged within normal run-to-run variance.

These are **diagnostic guest-frame throughput measurements, not gameplay FPS**. The retained Widget011 target is a deterministic diagnostic and does not expose a sustained combat/level gameplay FPS counter.

Fresh visual evidence reached the Castle Crashers menu UI and the book/menu scene. The fresh completion frame SHA-256 is `058404e8edb87d46965cf32098698314eb2f61d67394e30f105c9f6799ded9b8`, exactly matching the retained historical completion capture byte-for-byte.

Fresh run evidence is persistent under `/CastleCrashers-Xbox-TestKit/Xbox/`, including the report, result JSON, telemetry polls, validation JSON, stdout log, and completion screenshot.

### Scope of the fresh XEMU result

The fresh run re-executes the retained **Checkpoint 011 Widget011 original-Xbox diagnostic ISO**. It does **not** yet execute a freshly rebuilt XBE containing current WIP 021's recovered graphics-chain work. Therefore it demonstrates fresh emulator boot, deterministic menu/widget rendering, memory stability, and telemetry parity for that retained Xbox diagnostic artifact, but it does not establish current WIP 021 gameplay, combat, audio, save/load, or sustained gameplay FPS.

### Fresh nxdk rebuild status

A fresh nxdk XBE incorporating current WIP 021 was **not built in this XEMU-validation turn**. The current reusable XEMU test still uses the retained Widget011 artifact. Do not claim that the fresh 2026-09-25 XEMU run validates current WIP 021 until a fresh Xbox target containing those changes is actually built and executed.

---

## 5. CURRENT BOUNDARY

WIP 021 now closes the observed `VdPersistDisplay`, exact `MmFreePhysicalMemory(1, token)`, the later distinct `VdRetrainEDRAM` shape, exact `sub_820CF9D0`, exact `sub_820CF858`, and exact `sub_821368C0` for the observed loader state. Exact `sub_820C13B8` now returns normally to the still-live original `PlatformRenderer::Init` frame.

A provenance-checked continuation of original `sub_820A7990` resumes at the already-proven success label `0x820A7B34`, executes the first suffix setter/restoration chain and the second `sub_820C2C98`, then reaches:

**UPDATE 2026-09-25: exact `sub_820A85E8` is now closed (see the WIP 021 continuation subsection above). The live boundary is the original caller continuation at `lr=0x820A7BC8`, first unrecovered call `sub_820AA5B8`. The historical boundary description below is retained for provenance:**

**renderer vtable target `sub_820A85E8` at `0x820A85E8`**

- outer path: exact `sub_820A7990` success continuation â†’ exact `sub_820C2C98` â†’ exact `sub_820C13B8` â†’ exact `sub_820C0DA8` â†’ exact `sub_820CF9D0` â†’ exact `sub_820CF858` â†’ exact `sub_821368C0` â†’ return through exact suffixes â†’ second exact `sub_820C2C98` â†’ renderer vtable slot `+28`;
- current indirect-call return address: `lr=0x820A7BC8`;
- live `PlatformRenderer::Init` stack: `r1=0x0003ED30`;
- boundary registers: `r3=0x00501060` (renderer), `r4=0`, `r5=0`, `r6=0x820A85E8`, `r7=480`, `r8=640`, `r9=0x82042048`, `r10=0x82040000`, `ctr=0x820A85E8`;
- sealed renderer vtable `[0x00501060]=0x82042048`, with slot `+28` resolving to `0x820A85E8`;
- exact `sub_821368C0` body: **659 bytes**, SHA-256 `3f548f0368b98565f5d7a2d09f7f2fb8cd77f51d9744a904e4f9b7c14108f48d`;
- exact CF858/CF9D0/CF728 hashes remain unchanged;
- focused invocation result: `dispatch@820A85E8`;
- focused invocation measurements: **964 generated/helper executions, 21,113 guest-memory operations**;
- focused Release `update_boundary`: **3,974 assertions**; Release CTest: **6/6**;
- local provenance: **338 exact generated bodies** plus the four inherited original diagnostic artifacts and the separately verified PlatformRenderer continuation slice.

The original `PlatformRenderer::Init` call has therefore **not returned yet**. Do not advance the live outer `sub_82070AC8` caller until exact `sub_820A85E8` and the remaining `sub_820A7990` suffix actually complete.

### Critical honesty constraint

Do **not** describe WIP 021 as sealed Checkpoint 021 or completed `PlatformRenderer::Init`.

`sub_820A85E8` was recovered byte-exact, not stubbed. Do **not** replace `sub_820AA5B8` or any later suffix call with a synthetic success stub. Recover byte-exact generated bodies from the sealed corpus and keep unknown downstream behavior fail-closed.

## 6. NEXT_ACTION

**The full shader-descriptor loop is closed (see the 2026-09-26 subsection). Resume at the `sub_820A7990` suffix beyond the slice stop: recover exact `sub_820A8190`, extend the slice through it and the subsequent calls (`sub_820BB6A8`*, `sub_820BFEE8`, `sub_820BFC30`, `sub_820C00B8`, `sub_820BD0F8`*, ...), and continue until the original `PlatformRenderer::Init` frame actually returns to `sub_82070AC8`. Reproduce first: `platform_post_graphics ok`, 2,231 / 66,888, 3,999 assertions, CTest 6/6, provenance 391 exact bodies.**

Concrete sequence:

1. Working tree is the git repository at `D:\Programming\GitHub\Castle-Crashers-X` (private remote `GTTeancum/Castle-Crashers-X`); the WIP/checkpoint ZIP recovery flow is superseded by git history.
2. Reproduce `platform_post_graphics result=ok`, **965 / 21,114**, and **3,976 assertions** using Clang (Windows: Clang 22.1.2, VS Ninja, `-D_CRT_SECURE_NO_WARNINGS`).
3. Confirm exact `sub_820A85E8` remains byte-exact at **2,317 bytes**, SHA-256 `b8c496093f943ce7276b65c6662f0a9872e8bfc21d8b4ed07105e2d42e589e5c`; CF858/CF9D0/CF728/821368C0 hashes unchanged.
4. Preserve the distinct retrain contracts and all persist/free/ring/resource/tile/CF9D0 invariants. Do not broaden platform shims.
5. Extend `sub_820A7990_platform_post_graphics` byte-for-byte from the sealed corpus through the stores after the indirect call (`renderer+28756/28760` from f30/f31, `renderer+29124/28740/28744` = 0, `renderer+28748`=640, `renderer+28752`=480) and stop fail-closed before `bl 0x820AA5B8`; update `verify_provenance.py`'s slice contract to the new cut point.
6. Bind the new durable renderer fields; update focused acceptance counts.
7. Then recover exact `sub_820AA5B8` from the sealed corpus, execute only the observed 17-iteration loop path, and continue boundary-by-boundary through the remaining `sub_820A7990` suffix calls (`sub_820A8190`, `sub_820BFEE8`, `sub_820BFC30`, `sub_820C00B8`, ...), stopping at each first genuine unknown.
8. Run focused Release acceptance, complete Release CTest, and the ASan/UBSan matrix after meaningful closure.
9. Use XEMU (local Windows copy under `C:\Games\Emulators`) only once a fresh nxdk/Xbox artifact containing current WIP logic exists; do not re-run the older Widget011 ISO as if it validates this code.
10. Update this handoff and re-read it completely before reporting.

Preferred next milestone: **complete the `sub_820A7990` suffix far enough that the original `PlatformRenderer::Init` frame actually returns to `sub_82070AC8`, then seal Checkpoint 021.**

## 7. Important non-regression history

### Checkpoint 015

- Removed synthetic hand-built manager tree from full synthetic update path.
- Exercised original manager initializer / ordered-map insertion.
- Preserved fail-closed unknown live capture state.

### Checkpoint 016

- Closed 10,500-object state-pool constructor.
- Reached worker scheduling boundary and bounded observed startup platform behavior.

### Checkpoint 017

- Closed original startup return, five-worker lifecycle, and 613-entry table.
- Constructed/published renderer and entered original `PlatformRenderer::Init`.
- Stopped at `sub_820BEFD0`.

### Checkpoint 018

- Closed lower graphics-object construction, engine setup, default rings, two graphics-worker records, command/state buffers, and baseline GPU state.
- Moved boundary to `sub_820CBBF0` with outer lower-device output still unpublished.

### Checkpoint 019

- Closed observed 640Ã—480 `sub_820CBBF0` presentation/resource path.
- Created/published all three resource-like objects through original code.
- Verified 1,228,800-byte backing allocation and two 240-tile surface allocations.
- Closed exact resource binders and gamma/presentation state.
- Moved boundary to `sub_820CB988`.

### Checkpoint 020

- Closed the large observed `sub_820CB988` GPU-state fanout and adjacent command-buffer/finalization chain.
- Closed exact EDRAM/HSIO finalization path through `sub_820D19E8`, `sub_820BDE48`, and `sub_820D1C08` with narrow platform contracts.
- `sub_820BEFD0` now returns success and **original code publishes the lower device through `renderer+4`**.
- Provenance increased to 297 exact local generated bodies.
- New actual xemu regression executed and passed on retained Checkpoint 011 diagnostic ISO using supplied Complex 4627 + matching MCPX and xemu lineage `0.8.136-15-gc231997`.
- No fresh nxdk XBE rebuild is claimed.
- New diagnostic-harness boundary is the `PlatformRenderer::Init` success suffix, first unclosed call `sub_820C2C98`.

---

## 8. Evidence hierarchy / working rules

Prefer, in order:

1. exact original bytes / sealed mapped image;
2. byte-exact generated ReXGlue bodies;
3. verified original disassembly slices with explicit provenance;
4. observed runtime captures;
5. narrow platform shims matching a verified external contract;
6. synthetic fixtures only for isolated regression testing.

Never silently promote lower-confidence evidence.

A platform shim is acceptable only when it is genuinely platform-specific, asserts observed inputs/order/state, models explicit outputs/state changes, rejects unexpected shapes, and does not invent game-side semantics.

Do not casually edit generated code to satisfy another compiler. Use the intended Clang/toolchain behavior.

Regression passes are necessary but not proof of full gameplay.

Always distinguish:

- diagnostic-harness/synthetic acceptance;
- runtime capture replay;
- freshly built nxdk/Xbox artifact behavior;
- xemu re-execution of a retained artifact;
- real Xbox gameplay / physical hardware.

---

## 9. Fresh-chat checklist

- [ ] Read this file completely.
- [ ] Prefer `/CastleCrashers-Xbox-TestKit` in persistent Library storage for project/Xbox test inputs. The `Emulator/` subfolder now contains `Xemu.7z`, the exact Complex 4627 / MCPX / EEPROM bytes, and the reproducible xemu `0.8.136-15-gc231997ef0` AppImage.
- [ ] Recognize latest sealed baseline as **Checkpoint 020**.
- [ ] Verify archive SHA-256 `d61b2ed0329abaed1a5dbe9661227e279f6864ee4af8508face7c07289e411eb`.
- [ ] Recognize `sub_820BEFD0` as closed with genuine `renderer+4` publication.
- [ ] Recognize current diagnostic-harness boundary as the `PlatformRenderer::Init` success suffix at `0x820A7B18`.
- [ ] Recognize sealed Checkpoint 020 boundary as `sub_820C2C98` at `0x820A7B5C`.
- [ ] If refreshed `CastleCrashers-WIP-021-85e8.zip` is available, verify SHA-256 `7f950085e0911ae002c809507c0353a3b7cd934f0c0ad15002b0447150e4f67c`; it is self-contained relative to Checkpoint 020. Recognize `VdPersistDisplay`, `MmFreePhysicalMemory`, the separately bounded second `VdRetrainEDRAM` shape, exact `sub_820CF9D0`, exact `sub_820CF858`, and exact observed `sub_821368C0` as closed to the current unsealed renderer-vtable boundary `sub_820A85E8` (`0x820A85E8`); sanitizer re-validation and full sealing acceptance are still pending.
- [ ] Preserve all resource/tile/ring/worker/HSIO invariants.
- [ ] Recognize the 2026-09-25 xemu `0.8.136-15-gc231997ef0` Widget011 run as the latest actual XEMU execution; it passed fresh telemetry/visual validation but is still a retained diagnostic ISO, not a fresh WIP 021 nxdk build.
- [ ] Do not conflate the new Complex-BIOS/dev-XEMU run with historical Checkpoint 011's debug-BIOS/official-0.8.136 tuple.
- [ ] Make a small focused work turn per the userâ€™s current preference.
- [ ] Preserve inherited regressions/provenance.
- [ ] Seal the next checkpoint only after meaningful closure.
- [ ] Update and fully re-read this handoff before final response.

---

## 10. TURN LOOP DIRECTIVE

When the user sends `continue` or `go`:

> Read `CastleCrashers-PROJECT_STATUS.md` first. Prefer persistent inputs from `/CastleCrashers-Xbox-TestKit` when materializing project/Xbox test artifacts. Resume immediately from `NEXT_ACTION`. Make a **small focused engineering turn** per the userâ€™s current preference. Preserve fail-closed behavior and provenance. Continue the real `PlatformRenderer::Init` suffix rather than revisiting closed lower-device work. Treat the diagnostic harness only as recovery/verification tooling; the project deliverable is the Xbox build. When a fresh nxdk/Xbox build is possible, distinguish it from xemu re-execution of retained artifacts. Before ending, update this file with exact new state/checksums/NEXT_ACTION, read it fully, report completed work/artifacts, and stop until the next trigger.

**Do not depend on hidden conversational context for the next turn. Put durable project state here.**
