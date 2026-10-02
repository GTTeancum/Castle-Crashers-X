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

### CHECKPOINT 021 SEALED — `PlatformRenderer::Init` COMPLETE (2026-09-26)

The continuation slice now covers sealed `sub_820A7990` byte-for-byte from `loc_820A7B34` **through the original function return**: after the shader-descriptor loop it executes exact `sub_820A8190`, the exact `SetVertexShader`/`SetPixelShader`/`SetVertexDeclaration` chain (`sub_820BFEE8`/`sub_820BFC30`/`sub_820C00B8`, newly recovered byte-exact), exact `sub_820BB6A8`/`sub_820BD0F8`/`sub_820BCF50`, a final exact `sub_820C44A0` 640×480 resource published at `renderer+8` (allocator shapes 52/`0x64800000` and `0x12C000`/`0xBC800000`), the success result store, and the original epilogue.

**The original `PlatformRenderer::Init` call has returned.** The live frame unwinds to the original `sub_82070AC8` caller (`r1=0x0003EEE0`), returns the original result-struct argument (`r3=0x0003EF50`, `[r3]=0` success, `[r3+4]=0`).

Sealing acceptance on this exact state:

- focused Release: `platform_post_graphics result=ok`, **2,277 generated/helper executions, 67,387 guest-memory operations**;
- Release `update_boundary`: **4,001 assertions**; Release CTest **6/6**;
- ASan/UBSan CTest **6/6**, widget FMA + software-FMA **1,922 assertions each**, fixture **12,047 checks + 6,000 mutations**, visibility **43,528 checks**;
- provenance: **395 byte-exact local generated bodies** (`verify_provenance.py`), continuation slice verified `820A7B34..return` (10,663 fragment bytes, SHA-256 `ab6f5d6008f6282cbb05a6670c23cb5cfcd2b8cd3297a8e0d3e1b35b1bcbd6ae`).

Checkpoint 021's sealed artifact is the git history of this repository (private remote `GTTeancum/Castle-Crashers-X`); ZIP checkpoint archives are superseded by git. XEMU has **not** been re-run for Checkpoint 021 and no fresh nxdk XBE exists yet containing this logic; that remains the top follow-up.

New boundary: the original `sub_82070AC8` caller continuation immediately after `bl 0x820A7990` (the renderer-prefix slice still stops before that call; it must now be extended through the Init call's return and onward to the next genuine boundary).

### WIP 022 — caller continuation: main pool + font load closed (2026-09-26)

A second continuation slice, `sub_82070AC8_post_init` (byte-exact fragment `82070BA4..through the indirect dispatch at lr=0x82070C0C`, verified by `verify_provenance.py`), resumes the original caller with the live registers left by the completed Init. Verified closed on the observed path, **4,028 `update_boundary` assertions**, Release CTest 6/6, ASan/UBSan CTest 6/6 + widget/fixture regressions:

- exact `sub_8209BC98` → exact `sub_820B6108` obtain the title's **16 MiB main pool** through the new bounded `MmAllocatePhysicalMemoryEx` contract (one 0x01000FFF/PAGE_READWRITE/4 KiB-align request at fixture arena `0x10000000`; publication bound at `0x75240/0x75244`);
- exact `sub_820A9B58` (font create) with newly recovered exact `sub_820A7390`, `sub_820D7D70`, `sub_820C4498/4488/3930/3568`, `sub_820C7D48`, `sub_820C2D58`, `__save/__restgprlr_15`: builds the path via a third accepted sprintf shape (`game:\Fonts\%s.xpr` at `0x820420CC`), opens/reads the container's `fonts\synjUnicode_20.xpr` (2,252,812 bytes) through the bounded file contracts (font open shape r8=1/r9=1, 4 MiB size cap), allocates a **2 MiB write-combined texture block** (`0x404` protect, cursor arena `0x12000000`), and creates the font texture through the exact XPR chain — glyph bytes in guest memory bound byte-for-byte against the container file (offset `0x28834` ↔ block `+0x2828`);
- the caller's renderer-vtable slot `+12` dispatch resolves to exact `sub_820A7E80` (with exact `sub_820BFB50`), executed and returned; host bridge gained the PPC `lvrx` mask table (`VectorMaskR`) and `setzero` helper;
- focused result: `caller_post_init result=ok`, **56 executions / 2,254,372 guest-memory operations** (the 2.25 MB font read dominates), stop after `lr=0x82070C0C`.

Next boundary: extend `sub_82070AC8_post_init` beyond the indirect dispatch toward the next unrecovered call (`sub_8209D028`, `sub_82096828`, `sub_820756E0`, `sub_820B5F50`, `sub_820A71E8` (currently a hard stub), `sub_820A1BF8`, `sub_820757C8`, `sub_82075C88`, `sub_820759A8`, `sub_8212B180`, `sub_82070908`, ... remain ahead).

### WIP 022 — first frame presented: text measure + present + GPU consumption model (2026-09-26)

The post-Init slice now runs through **both** renderer-vtable dispatches (`82070BA4..through lr=0x82070C78`): exact `sub_8209D028` → `sub_820A9E98`/`sub_820A9D78` (font text measurement, 300+ exact executions), then vtable slot `+16` resolves to exact `sub_820A8010` → `sub_820A8030` → exact `sub_820C13B8`, i.e. the game's own **first frame present**. Verified at **4,026 assertions**, Release CTest 6/6, ASan/UBSan CTest 6/6 + widget/fixture.

Present-path platform closures, each bound to observed shapes: `VdGetSystemCommandBuffer` accepts the frame path's second query from `lr=0x820C0FB0`; `VdSwap` was rewritten frame-relative (identical r1-relative layout for both observed swaps; the post-Init frame writes its swap block through the ring write-pointer window `0x0201F000..0x0202F000` rather than the scaler region); `VdRetrainEDRAM`/`KeLeaveCriticalRegion` accept the frame's own `sub_820D19E8` re-entry (`frame022` shape, worker skipped); newly exact `sub_820C0B40` replaced its stub; renderer-vtable slots `+12/+16` targets `sub_820A7E80` (+`sub_820BFB50`, needing new host `VectorMaskR`/`setzero` lvrx helpers) and `sub_820A8010`/`sub_820A8030` are recovered and dispatched.

**GPU consumption contract:** the fixture Xenos now consumes submitted commands synchronously at the `CP_RB_WPTR` doorbell, publishing the caught-up read index through the ring descriptor word — this is what unblocks the exact ring-space wait (`sub_820C6B18` → `sub_820BE9F0`) that polls the read-index writeback against the submission phase. The descriptor word binding updated accordingly (now equals submission phase 15 after init; +30/+6 memops in the two earlier focused segments).

Also fixed: the per-thread block at `[r13+256]` is one structure (owner cookie +332, last error +352); the earlier separate error-block fixture wrongly repointed it and has been removed, restoring the checkpoint-020 owner-canary binding at `device+10888`.

Focused result: `caller_post_init result=ok`, **591 executions / 2,264,597 memory operations**, ending after the completed present at `lr=0x82070C78`. Next: extend the slice to the next unrecovered caller call (`sub_82096828` etc.).

### WIP 022 — notification listener, complete audio driver, and main-loop thread creation closed (2026-09-26)

The post-init slice now extends to before `bl 0x820A1BF8` and runs, all through byte-exact recovered code (provenance now **519 exact bodies**): exact `sub_82096828` → the notification-listener service (`sub_820D8580/820D84A8/8213AEE0/8213ACB0`, static CS `0x82151A6C` pre-registered as loader-era fixture, allocator flag `0x608A2002`); exact `sub_820756E0` → renderer-vtable query `sub_820A7480`; the **complete XAudio driver initialization** (`sub_820D7FD0` family, ~70 bodies including the third/fourth audio vtables): APU register snapshot (`[0x7FEA1800]` power-on zero), two suspended audio workers (start routines `0x820D99B0`/`0x820D9A78`, flags `0x10000001`/`0x20000001`, base priority 15), mixing/voice buffers (allocator flags `0x61820005`/`0x61820006`), and the kernel **`XAudioRegisterRenderDriverClient`** registration (callback `0x820E2B30`, opaque client token; render pump never runs, submit/unregister fail-closed); exact `sub_820B5F50` event wrapper backed by a bounded `NtCreateSemaphore` token registry; and creation of the **game's main-loop thread** (start routine `0x82070828` via the standard thunk, created suspended, base priority 1) recorded by the bounded scheduler without running it.

New/extended contracts: nested-IRQL level model with raised-IRQL spinlocks (`KeRaiseIrqlToDpcLevel`/`KfLowerIrql`/`KeAcquireSpinLockAtRaisedIrql`/`KeReleaseSpinLockFromRaisedIrql`), `KeInitializeSemaphore`/`KeSetEvent`/`KeResumeThread` trusted-kernel models, third `ExRegisterTitleTerminateNotification` record (`0x8223595C`), `Context` gained an `msr` mirror for generated `mfmsr/mtmsrd` sequences (no-op global lock on the single-threaded host), and the thread table grew to 12 slots.

Focused result: `caller_post_init result=ok`, **767 executions / 2,268,979 memory operations**, `lr=0x82070D34` (last completed call `sub_8209BDD8`), 4,026 assertions, Release CTest 6/6, ASan/UBSan CTest 6/6 + widget/fixture. Next: `sub_820A1BF8` and the remaining `sub_82070AC8` tail (`sub_820757C8`, `sub_82075C88`, `sub_820759A8`, `sub_8212B180`, final indirect call, `sub_82070908`) — after which the game's init caller itself completes.

### CHECKPOINT 022 SEALED — COMPLETE TITLE STARTUP TO THE MAIN LOOP (2026-09-26)

The `sub_82070AC8_post_init` slice now covers the caller byte-for-byte from `0x82070BA4` to the `loc_82070DB0` **main monitor loop** — the game's entire one-time initialization is executed. Beyond Checkpoint 021's graphics/font/present/audio closure this adds the XAM/Live-era profile-manager entry (`sub_820A1BF8` and the `sub_82075C88`/`sub_820759A8`/`sub_82070908` tail families; local provenance now **1,139 byte-exact bodies**) with these observed-shape platform contracts: `XamGetSystemVersion` (2.0.17559 lineage), `XexGetModuleHandle("xam.xex")` + `XexGetProcedureAddress`→`STATUS_NOT_FOUND` (original fallback path), `NetDll_XNetStartup`/`NetDll_WSAStartup` title-caller success with `NetDll_XNetCleanup`/`NetDll_WSACleanup` teardown mirrors (all other network operations fail-closed), one-shot `XamNotifyCreateListener` token, and the second static data-segment critical section `0x82235A5C`.

**ORIGINAL-XBOX PORT POLICY (user directive):** Xbox Live and achievements are 360-only services with no counterpart on the original Xbox. The Live session/profile singleton constructor (`sub_8210C860`) is deliberately stubbed to return `E_FAIL`; the exact caller `sub_8210C908` ships its own error path (refcount reset + propagate), and the game continues exactly as retail does with Live unavailable — it tears down XNet/WSA and proceeds offline. Achievements ride the same stack and are covered by the same refusal; remaining XAM imports (sign-in, profiles, enumerators) stay fail-closed/not-signed-in stubs and are bound individually if the offline path ever queries them.

Sealing acceptance: `caller_post_init result=ok`, **808 executions / 2,269,363 memory operations**, stop at the main monitor loop (`lr=0x82070D98`); `update_boundary` **4,026 assertions**; Release CTest **6/6**; ASan/UBSan CTest **6/6** plus widget 1,922×2, fixture 12,047+6,000, visibility 43,528. Sealed artifact: git history (private remote).

Startup state at the seal: renderer + device fully initialized, 15 shader pairs + font loaded from the retail container, first frame presented with the doorbell-consumption GPU contract, complete audio driver registered with two pinned workers, notification listener live, 16 MiB main pool published, CRT heap serving allocations, main-loop thread created (suspended, priority 1), Live declined by port policy. **The next frontier is the main loop itself and, in parallel, the fresh nxdk XBE/ISO build for XEMU validation — the diagnostic recovery has now reached the state a booting original-Xbox port must reproduce.**

Port-policy addendum (user directive): **leaderboards** are stubbed under the same original-Xbox policy as Live and achievements — they ride the same session/stats stack, which the Live singleton `E_FAIL` gates upstream; any leaderboard call that still surfaces on an observed path receives a graceful no-session stub rather than a hard stop.

### FRESH NXDK XBOX BUILD + LOCAL XEMU RUN (2026-09-26)

The full source→XBE→ISO→XEMU pipeline now works **on this machine**, ending the "no fresh nxdk build" gap carried since Checkpoint 011:

- Toolchain: local `C:\nxdk` checkout driven by MSYS2 CLANG64 (`tools/build_widget011_nxdk.sh`); clang 21.1.8 required `-fms-compatibility-version=19.29` for the bare `i386-pc-win32` triple (build-infrastructure flag in the project Makefile); the prebuilt `cxbe.exe`/`extract-xiso.exe` host tools are passed as command-line make variables and need `/mingw64/bin` on PATH for their runtime DLLs.
- Fresh artifacts (build outputs, gitignored, reproducible): `nxdk-widget011/bin/default.xbe` SHA-256 `6938330bdd27ef6f10a8e4f6c94bdebff8b84bc1519d5eed822a8831d52cca16` (905,216 bytes); `nxdk-widget011/CastleCrashers-Widget011.iso` SHA-256 `2d0170a52da85d1956b02a4d6aa11e87234560dd4d2bcda38d9cd68becb8eb3f` (44,630,016 bytes).
- **Actual XEMU execution**: local Windows `xemu.exe` 0.8.136 (`C:\Games\Emulators\Xemu`, its own configured BIOS/EEPROM/HDD tuple — distinct from the Linux CI tuple recorded for Checkpoint 020), launched with `-dvd_path` on the fresh ISO. The diagnostic booted and rendered the Castle Crashers mode-select book scene; window captures at ~50 s and ~75 s are committed under `logs/wip022/`.
- Honest scope: this fresh ISO carries the **Widget011 diagnostic content** (Checkpoint 011-era logic, rebuilt byte-fresh) — it does **not** yet embed the Checkpoint 022 recovered startup. The established Makefile pattern (the widget build already compiles `runtime011/bridge.cpp` for the Xbox) is the template for the next step: an `nxdk-checkpoint022` target compiling `runtime021/bridge.cpp` + a native driver for the recovered startup chain, with host-file contracts redirected to ISO-resident `game-data` files.

### CHECKPOINT 022 VALIDATED NATIVELY ON THE ORIGINAL-XBOX TARGET (2026-09-26)

The `nxdk-checkpoint022` target now exists and **the complete recovered startup chain runs to completion on the emulated original Xbox**: `native boundary run complete rc=0`, with the full `PASS update_boundary` banner on the Xbox debug console and segment measurements **identical to the host** (startup 182,986 execs / 2,671,382 memops; graphics init 17,008 / 194,116; the whole chain through shader loading from the disc, font creation, first present, audio init, and main-loop thread creation). Window captures under `logs/wip022/xemu-cp022-native-*.png`.

Build: `nxdk-checkpoint022/` (Makefile + `xbox_shims.cpp`) via `tools/build_checkpoint022_nxdk.sh`; compiles the identical `runtime021` sources (`update_boundary_tests.cpp` gains a `CC_XBOX_DRIVER` entry that renders through the nxdk debug console; disc layout `D:\data\{startup.cct, default.image.bin, game-data\{shaders,Fonts}}`). Portability work, all shared-source and host-verified after each change (host Release+ASan matrix green, 4,032 assertions): logging seam `runtime021/cc_log.h`; monotonic-clock seam replacing `std::chrono` in the bridge; fixed-buffer `g_game_root`/CS registry (no libc++ heap-string externs); stdio file loads instead of `ifstream`; two arena trims (heap 1 MiB, phys 4 MiB) for the 64 MiB budget; 1 MiB XBE thread stack (`-stack:0x100000`); `xbox_shims.cpp` supplies operator new/delete (plain/sized/aligned), the protected libc++ thrower symbols missing from the machine's prebuilt nxdk libc++, and `log2f`/`exp2f` (pdclib's Xbox math stubs assert; the corpus maps `vlogefp` to `log2f`, a 12-bit hardware estimate, so double-precision series implementations are well inside tolerance) plus the existing software `fma` from `runtime007/numeric`; Xbox-side path-separator normalization in the bounded NtCreateFile contract.

Fresh native artifacts (gitignored, reproducible): `nxdk-checkpoint022/bin/default.xbe` SHA-256 `057b91db0e1fe092940c0d25a5c345b06036fe6782a6e8270b80c4c476bfcf58`; `CastleCrashersX-Checkpoint022.iso` SHA-256 `f61f0f53de5b97cb362507149a1d306baa5a190dffb1ab55928367fb2b4adc29` (10,289,152 bytes).

**This closes the loop the project was built around: recovered Xbox 360 behavior, proven byte-equivalent on the host, now reproduces measurement-for-measurement on the original-Xbox target.** Next frontiers: (1) the game's main monitor loop / frame loop (routine `0x82070828`) to reach live menu rendering natively; (2) replacing the diagnostic presenter with a real pbkit-rendered frame so the native build shows the game's frame instead of console text.

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

### 2026-09-26 — WIP 023: THE MAIN GAME LOOP RUNS. Three complete frames execute deterministically.

The `sub_82070AC8_post_init` slice now covers sealed `sub_82070AC8` from `0x82070BA4` through its original return **including the `loc_82070DB0` main game loop** (fragment 14,158 bytes, provenance `range=82070BA4..return_including_main_loop`). Boundary-driven recovery closed the first frame end to end, and frames 2 and 3 then ran **without hitting any new boundary** — the frame loop is closed under the recovered set:

- Each frame executes the original update `sub_82075C88`, render pass `sub_820759A8`, `VdSwap` present (frame-N swap blocks accepted across the ring window `0x0201F000..0x02030000`, content validation unchanged), and the per-frame EDRAM retrain cycle (`KeEnterCriticalRegion` → `VdRetrainEDRAM` → `KeLeaveCriticalRegion`, now re-armed on each completed frame/suffix shape; the Checkpoint 020 worker-assisted init sequence stays one-shot).
- New narrow fixtures, all observed-shape-bound: **XamInput trio** (one standard idle gamepad on port 0, incrementing packet number; ports 1–3 `ERROR_DEVICE_NOT_CONNECTED 0x48F`; the original-Xbox driver will map real pads at this exact boundary), **XMsgInProcessCall** app `0xFA` msg `0x00070009` (XMP music-player status → idle; no system music player exists on the original Xbox), and the **KeDelayExecutionThread frame boundary** (`WaitMode=1, Alertable=0`, negative relative interval, `lr=0x820B7504` from exact Sleep wrapper `sub_820B6068`): accepted per frame, deliberate `Error::capacity` stop at the third frame's pacing sleep. `NtWriteFile` remains fail-closed.
- New exact bodies recovered and wired: `sub_82053888` and `sub_820C74D0` (both former hard boundaries, now genuinely reached), `sub_820A7470`, and the renderer vtable family at `0x82042048` (15 new bodies incl. `sub_820A75E0/7DE0/7E30/8650/86D0/8750/8810/8840/7550`, `sub_820BECF8/BED90/BFA70/D7D00/D7AF0`); `0x820A89F8` keeps bridge.cpp's modeled texture-bind sink case (first in the switch) — its exact body extraction is parked in `runtime021/generated/` unwired.
- **Measured: `caller_post_init result=capacity@8214a614 funcs=1331 memops=2276618 lr=820b7504`, 4,030 assertions, Release PASS, ASan PASS, provenance 1,202 exact bodies, fixture/widget/visibility suites PASS.**

The harness startup.cct lives at `D:\Programming\GitHub\Castle-Crashers-X\renderer011\startup.cct` (not `castle-crashers-port/reference/`).

### 2026-09-26 — WIP 023 VALIDATED NATIVELY: the main game loop runs on the emulated original Xbox, measurement-identical to the host.

`nxdk-checkpoint022` was rebuilt from the current sources and executed in the local Windows XEMU (`C:\Games\Emulators\Xemu\xemu.exe -dvd_path ...`, v0.8.136). First native run reproduced the frame loop with `funcs=1331` but **one memory op fewer** than the host (2,276,617 vs 2,276,618): raw clock magnitudes differ between platforms and one recovered path stores a value derived from them. Fix: the diagnostic timebase in `runtime021/bridge.cpp` is now **virtual and deterministic** (advances exactly 1 ms = 49,875 ticks per guest read; no host/Xbox clock reads). Host measurements were unchanged by this (still 1,331 / 2,276,618, 4,030 assertions, Release+ASan PASS). The rebuilt ISO then ran natively with **`caller_post_init result=capacity@8214a614 funcs=1331 memops=2276618` — identical to the host — full `PASS update_boundary assertions=4030` banner and `native boundary run complete rc=0`** on the Xbox debug console. Window captures: `logs/wip023/xemu-wip023-native-45s.png` (first run, one-memop mismatch preserved as evidence) and `logs/wip023/xemu-wip023-native-b2-50s.png` (identical PASS run). Fresh artifacts (gitignored, reproducible): `CastleCrashersX-Checkpoint022.iso` SHA-256 `393D170171EC7278BA0CE5C3C4A1233B87C196AD02F431EA763A7F09150BBAFA`, `bin/default.xbe` SHA-256 `11D16736C986700B3EC16F456FF74EBC506156697327DEA376574B40203D74AD`.

**Three frames of Castle Crashers' real main game loop — original update, render, present, retrain, input poll — now execute deterministically on the original-Xbox target.**

### 2026-09-26 — WIP 023b: 1,000 frames run; the game loads logo.pak (intro logo) through recovered code.

Raising the frame budget surfaced and closed the whole intro-asset path: `caller_post_init result=capacity@8214a614 funcs=330612 memops=7127931`, Release+ASan PASS, 4,034 assertions, provenance 1,223 exact bodies. New in this increment:

- **CRT `_mtinit` pre-step** (`crt_mtinit ok`, 56/819): exact `sub_8212A630` closure (11 bodies + `sub_8212A2E0`, `sub_82130408`) run after the heap pre-step exactly as the sealed XEX entry would; `KeTlsAlloc`/`KeTlsFree` fixtures (64-slot bitmap in bridge.cpp); CRT static lock-table page `0x82150000..0x82152000` auto-registers on first RtlEnterCriticalSection (image-initialized CS structs never pass RtlInitializeCriticalSection).
- **Pak file I/O**: third NtCreateFile shape (`FILE_ATTRIBUTE_NORMAL`/`FILE_SHARE_READ`, prefix `game:\game\` → `game-data/extracted/game/`, 16 MiB cap, case-insensitive prefix — the loader uppercases to `game:\GAME\LOGO.PAK`); NtSetInformationFile class 14 seek; NtQueryInformationFile class 14 position query; sprintf shapes 4-6 (`game\%s.pak` @0x8203FDD0, `game:\%s` @0x82040BF4, plain `%s` @0x8203E464).
- **Instant-GPU writeback contracts** (bridge.cpp prologue hooks, raw address-space stores so guest op counts are unaffected): `sub_820BE9F0` fence word `[desc+0]` (+ one-step worker retire when caught up), `sub_820C5E50` tagged read cursor `[desc+4]`, `sub_820C5EE8` read address `[desc+60]` — each published only when the exact waiter would block, leaving sealed init bindings intact.
- NtReleaseSemaphore fixture (recorded initial/limit per created semaphore); XNetRandom deterministic fixture bytes (port policy: no XNet on the original Xbox); XMsgInProcessCall XMP-status idle; VdSwap window now the whole command arena `[0x0200F140,0x0220F000)` (cursor wraps after ~15 frames); TLS shim thunk labels corrected to 0x8214ACC4/ACD4; harness caps raised (5M funcs / 500k dispatches / 20M memops budget); new exact bodies incl. `sub_82053888`, `sub_820C74D0`, `sub_820A7470`, `sub_821287B0`, `sub_82128A60`, `sub_820B00D8/06C0/AFF40`, renderer vtable family.
- `tools/recover_loop023.py`: automated run→extract→wire→rebuild loop; stops at platform imports and hand shims for manual review.

### 2026-09-27 — WIP 023d: THE GAME REACHES THE MAIN MENU. Full intro sequence + sign-in flow run under recovered code.

The bounded diagnostic now plays the whole boot flow: **LOGO.PAK → LOADING.PAK → PAUSE.PAK → LEGAL.PAK → intro music (NG90433.xma, 1.8 MB) → ATTRACT.PAK (title) → MENU.PAK (main menu)**. The injected START press at the title triggers the game's real sign-in call (XamShowSigninUI), the local-player sign-in fixture answers it, and the game settles into rendering menu frames (3,000+ frames) until the deliberate 900M memory-op budget expires mid-draw inside the exact quad body. **Measured: `caller_post_init capacity@0003e678 funcs=41,122,868 memops=900,000,001 lr=820a9318`, 4,037 assertions, Release PASS, ASan PASS, provenance 1,727 exact bodies.** No unrecovered boundary remains inside the budget.

New in this increment (~500 exact bodies since 023b, all byte-exact from the sealed corpus, wired mostly by `tools/recover_loop023.py`):

- **Audio stubbed by port policy (user directive)**: exact `sub_8209EA18` (music-stream open) replaced by a stub taking the function's own shipped failure contract (result 1 / stream 0) — the game continues silently on paths it already ships. XMA remnants kept honest: `XMACreateContext` hands out a zeroed 64-byte fixture context, the APU XMA register window `0x7FEA1800..0x7FEA1FFF` reads zero and swallows kick writes (silent hardware; no decode progress faked). The real port will re-encode audio (XBADPCM/WAV/OGG) behind the same `sub_8209EA18` boundary.
- **Sign-in flow (port policy)**: `XamShowSigninUI` succeeds instantly and queues one `XN_SYS_SIGNINCHANGED`; `XNotifyGetNext` delivers it once against the fixture listener then reports quiet; `XamUserGetSigninState` = signed-in-locally for user 0 only; `XamContentGetLicenseMask` = 0 (offline retail console, DLC hidden).
- **Clock/locale**: `KeQuerySystemTime` derives a FILETIME from the virtual timebase; trusted `RtlTimeToTimeFields` implementation; `ExGetXConfigSetting` category-3 settings 1–8 and 11–16 = zero (UTC console), 9/10 keep sealed startup semantics.
- **CRT third pre-step**: exact `sub_82127E48` (`_init_onexit_table`) — `crt_onexit_init ok`, table at 0x82290CAC/CB0 — plus the exact `_onexit` closure (`sub_82127FB0/EA8` + malloc-region chain; the runtime008 fail-closed stub for `sub_82127FB0` is superseded by the exact body).
- **Fixture capacity for a real game session**: CRT heap arena 32 MiB, physical cursor arena 96 MiB with exact-size block recycling (alloc/free tables in bridge.cpp), 8-slot multi-handle file table (XMA banks stay open across pak opens), MmFreePhysicalMemory recycles fixture blocks, `MmGetPhysicalAddress` identity contract across the mapped arenas, sub-page physical allocs (0x800), audio-flag allocation shapes (0x61820005/6, 0xA7820007, sizes ≥16), NtReadFile second shape (ApcContext=IOSB + explicit 8-byte offset), NtCreateFile directory-mapped opens (`game:\game\`, `game:\sounds\`, `game:\music\` — chosen by the guest path segment), sprintf shapes 7–9 (sounds/music prefixes, bounded literal copy, structural `game:\<dir>\%s`).
- Two new VMX helpers (`vadduws` saturating add, `vmaxsw` signed max) for the exact XMA-adjacent audio body.

### 2026-09-28 — WIP 023f: GAMEPLAY, VISUALLY VERIFIED. Every game function wired; the knight walks, attacks, collects gold, and the story advances.

- **Frame capture + host rasterizer.** `runtime021/bridge.cpp` (host only, raw reads, counts unaffected) records every draw of selected frames at the game's final draw call (exact `sub_820C1980`) plus the texture bound by `sub_820A89F8` into `CCFRAME1` files (`CC_CAPTURE_FRAMES=a,b,...`, `CC_CAPTURE_DIR=...`). `tools/render_capture.py` turns them into PNGs. Harness surfaces are linear (the Xenos untile path is kept for real GPU dumps). **Screen mapping solved:** the game's vertex constants (found in the command ring with `CC_CAPTURE_RING` + `tools/ring_consts.py`) are an orthographic **640x480** projection (c0.x = 2/640, c1.y = -2/480, set once per frame; per-draw packets only change blend, texture fetch and vertex fetch). Vertices are therefore 640x480 screen pixels, matching the console's reported video mode and the original Xbox's native resolution; in-level the game letterboxes its 16:9 view on the 4:3 screen. `render_capture.py` now renders 640x480 and all evidence PNGs were cropped to the visible screen. For the Xbox render path this means the game's draw output maps 1:1 onto a 640x480 NV2A framebuffer with a fixed ortho transform.
- **Console identity fixed:** `XGetGameRegion` was 0x0101 (Japan) and `XCONFIG_USER_LANGUAGE` failed, so the game ran in Japanese. Now `XGAME_REGION_NA_ALL` (0x00FF) + `XC_LANGUAGE_ENGLISH`; sealed startup checks rebound (language index 0, system region 0).
- **Full game, not trial:** `XamContentGetLicenseMask` = 0xFFFFFFFF (callers test bit 0; clear = Arcade trial with "Unlock Full Game" and the trial briefing screen).
- **All 3,910 registered functions wired** by `tools/wire_all021.py` (1,455 bodies extracted byte-exact, 3,182 dispatch cases, 17 HARD_ boundaries kept) + `tools/gen_stubs021.py` (31 fail-closed imports). Ten new VMX helpers (vmsum4fp, vcuxwfp, vsr, vavgsb/sh, vaddubm, vpkswss, vupk*, merges). Provenance: **3,613 exact bodies PASS**. The boundary-per-run loop is retired (`tools/recover_fastloop023.py` kept for history).
- **Built-in input script** now plays: title → menu → story → Live notice → character select → level: walk right, 4 light attacks, jump, walk down-left, heavy attack, walk up-right, 3 attacks, walk right. `CC_INPUT_SCRIPT` overrides on the host.
- **Visual evidence** (`logs/frames_full/*.png`): 3500 story book, 4200 Live notice, 5200 character select (green knight, level 1), 7500 in level with HUD, 7800 walking (camera scrolls), 8102/8200 sword swings, 8600 walked to the room's left edge, 9362 at the training dummy with **gold 2**, 9900 opening cutscene (wizard in the throne room).
- **Measured default session:** 10,000 frames, 4,046 assertions PASS (rc=0), `capacity@8214a614 funcs=361,075,719 memops=1,050,751,650`; physical memory peak 184 MB in the level.

### 2026-09-28 — WIP 023g: RETAIL 64 MB TARGET; textures DXT5-compressed at creation (level peak 184 MB -> 51 MB).

- **Target decided by the user: retail 64 MB original Xbox only.** Streaming policy: stream music, preload SFX where possible, stream art where possible (TODO.md budget table).
- `CC_MEM_REPORT=<frame>`: live physical blocks by allocating guest code/caller chain, drawn-texture blocks, content signatures, filled/empty, CRT heap and main-pool usage. Level 1: 158 of 166 MB were ~2,800 A8R8G8B8 textures; CRT heap ~20 KB; main pool 12.6 of 16 MB.
- The art is vector shapes rasterized on the CPU at load: exact `sub_820B1078` allocates the texture and parses the shape (SWF-style bit-packed RECT), exact `sub_820B1478` rasterizes into a float buffer and converts w*h pixels into `[obj+564]`. Wrappers (exact bodies unchanged): the texture block is shrunk to w*h at allocation, the rasterizer writes into a transient scratch block, the port DXT5-compresses into the texture (`cc_dxt5_block`, standard little-endian blocks for the NV2A). Freed blocks drop out of the tables; a second rasterization into a compressed texture fails closed.
- **Result: level live 166 -> 47 MB, peak 184 -> 51 MB; identical funcs/memops (361,075,719 / 1,050,751,650), 4,046 assertions PASS, provenance 3,613 PASS; frames verified by eye (`logs/frames_dxt/`).** Capture format code 100 = port DXT5; `render_capture.py` decodes it.

### 2026-09-28 — WIP 023h: art streaming; level graphics memory 10 MB live / 12 MB peak.

- Every texture keeps a 596-byte snapshot of its rasterizer job (inputs: the job bytes at +20/+540/+541/+552..+564/+572..+595 plus the shape tag bytes in the loaded movie; analysis in this entry's commit). The game's own texture block is cut to 16 bytes (its pointer stays the identity); DXT5 pixels live in a streaming cache (16 MB limit, LRU by last bind). A wrapper on exact `sub_820A89F8` (texture bind) re-rasterizes a missing texture by replaying exact `sub_820B1478` on a restored job with its output redirected to a scratch block, then compresses into the cache. Textures are rasterized on first bind (the exact rasterizer only allocates/frees its own temporaries, so skipping it at load leaves no game-visible state).
- Verification: each replay is hashed against the first compression. 2 MB stress cache: 45,614 replays, 0 mismatches over 10,000 frames. Default 16 MB: no evictions (peak ~7 MB), level graphics 10.2 MB live / 12.1 MB peak; frames verified by eye (`logs/frames_stream/`).
- Default sealed session rebound: **funcs 321,116,952 / memops 4,121,608,529, 4,046 assertions PASS, provenance 3,613 PASS**; nxdk build OK.

### 2026-09-28 — WIP 023i: audio. Xbox ADPCM, the port's own PlatformAudio layer, sound-bank strip.

- User decision: Xbox ADPCM for effects (preloaded as registered) and music (streamed). nxdk has no MCPX voice-processor driver, so the port decodes ADPCM and mixes in software (cheap: ~10 integer ops/sample).
- Findings (agent survey, verified): effects play from game:\sounds\<name>.xma (420 files) registered by linkage name (`sub_8209EA18`), music from game:\music\<name>.xma (`sub_8209ED28`), both loaded whole and played on XAudio voices. The SOUNDS.PAK SWF MP3 bank (342 DefineSounds, 9.8 MB) and RSND WAVs are never played but the bank was loaded whole into the main pool.
- `tools/xadpcm.cpp` (MCPX block layout per xemu's decoder), `tools/convert_audio.py` (sfx.xab 8.6 MB, music 172 MB), `tools/strip_sound_bank.py` (SOUNDS.PAK 16.5 -> 6.7 MB; main pool 13.5 -> 3.9 MB; identical instruction count and pixel-identical frames). Host port-data overlay: game-data/converted/data/ files take precedence.
- `runtime021/audio.inc` replaces RegisterSound/RegisterMusic/ClearSound/PlaySound/PlayMusic/Update/SetVolumePan and wraps the library's SetVolume (`sub_820D8430`) and Stop (`sub_820D8370`) for port voice handles. Newly reached exact bodies `sub_82074A58`/`sub_82074B00` (former hard boundaries) wired.
- Host recording of the 10,000-frame session: music and effects throughout; music bit-aligned with the original (correlation 1.000). Default session rebound (320,961,210 / 4,101,260,149), 4,046 assertions PASS, provenance 3,609 PASS, nxdk build OK.

### 2026-09-28 — WIP 023j: retail 64 MB budget enforced in the harness (~56 MB estimated total).

All guest regions map at retail size (TODO.md third-pass table): game heap 14 MB, main pool 4.5 MB backed, CRT 1 MB, graphics arena 2.1 MB (360 surfaces and ring aliased; the game never reads them back), physical memory in zones (general 4.5 MB, small blocks 1 MB, texture stubs 1.5 MB, texture cache 4 MB buddy zone with a Z: scratch swap). Game files read on demand; sound effects load on first play (2 MB cache). The 10,000-frame session runs with identical counts (320,961,210 / 4,101,260,149) and pixel-identical frames; 4,062 assertions PASS; provenance 3,609 PASS; nxdk build OK.

### 2026-09-28 .. 10-01 — WIP 023k: NATIVE AND PLAYABLE IN XEMU (retail 64 MB); speed work from a code audit.

The Xbox build renders through pbkit/NV2A, plays music and effects through the AC97 (software mixer, Xbox ADPCM), reads a real pad (nxdk SDL; set XEMU's Machine > Input to an Xbox controller), steps the game by a real clock, and loads pre-rasterized DXT5 art from `texbake.pak` (built on the host with `CC_TEX_BAKE`). The user played through level 1 by hand on 2026-10-01: no gameplay bugs seen, only low frame rate. A read-only audit (five parallel reviews of the port code) produced the speed work: exact float shortcut for the software `fma` (was ~3,000 cycles per call, 16 per call in the hottest matrix function), play-build hooks reduced to four by id (the old chain printed debug text on every call), native guest `memcpy`, inline flush-mode clear, no late-frame 2 ms sleep, no verification-only startup runs at boot, audio mixer rewrite (each block decoded once, sequential music reads, fixed point), `std::` substitutions inside the generated bodies (fence -> compiler barrier, `isnan` builtin, inline `fma`), stack accesses on their own hot memory entry, per-call-site inline cache for indirect calls, packed textures keep no job snapshot (~2 MB) and are re-read from the pack instead of swapped, same-frame textures evicted only after a GPU wait. Xbox code 12.2 -> 9.3 MB. Every change: default host session PASS with identical counts (320,961,210 / 4,101,260,149; 4,062 assertions; provenance 3,609) and the host play-mode build (`renderer021/build-fast`, `-DCC_FAST`) pixel-identical on frames 2000 and 9362. XEMU A/B (quiet machine, scripted input; `tools/xemu_ab.sh`): menu 58 -> 39 ms, character select 64 -> 32 ms, level 80-89 -> 46-57 ms, measured after the first batch; later batches not yet measured cleanly (shared machine with the TimeSplitters session; ask it for a quiet window first).

## 6. NEXT_ACTION

**WIP 023k: playable in XEMU at ~20 FPS in level 1; goal is a steady 30 FPS (33 ms) in XEMU on this PC. Next: (1) measure the current build (`CC-G-audit5.iso`: dispatch cache, pack-aware textures, eviction fix) against `CC-D-audit2.iso` in a quiet window; (2) remaining audit items: on-target profile (`make PROFILE=1`) to find what is left, texture zone eviction by block, allocator hash lookup, boot arenas oversized (~1.5 MB), input script behind a build switch, Sleep(0)/re-entrant critical section/finite-timeout wait fail paths, pitch alignment and non-power-of-two guards in `xbox_render.cpp`; (3) later levels' memory and pack coverage.**

**Earlier (WIP 023): the main game loop runs — three full frames (update `sub_82075C88` + render `sub_820759A8` + `VdSwap` + EDRAM retrain) execute deterministically against the idle-pad/no-music fixtures, stopping at the bounded `KeDelayExecutionThread` frame budget (`capacity@8214a614`, 1,331 / 2,276,618, 4,030 assertions). Reproduce first with `renderer011\startup.cct`. Frontiers, in preference order: (1) rebuild `nxdk-checkpoint022` with the current sources and run the frame loop natively in XEMU (`C:\Games\Emulators`) — native original-Xbox proof of live frames; (2) raise the frame budget and inject fixture input transitions (e.g. START press on port 0) at the XamInputGetState boundary as labeled diagnostic input to drive the menu state machine toward gameplay; (3) real pbkit rendering of the frame's draw output on the Xbox target.**

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
