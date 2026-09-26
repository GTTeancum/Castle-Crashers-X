# Castle Crashers original-Xbox port — Checkpoint 018

## Result

Checkpoint 018 moves the host original-code convergence boundary materially deeper into `PlatformRenderer::Init`. Starting from the exact register/presentation state established by Checkpoint 017, it executes original/generated code through `sub_820BEFD0`, lower graphics-object construction, engine setup, default command-ring construction, command/state buffer initialization, the observed two graphics-worker creations, `sub_820BF930`, and `sub_820D7920`.

The new honest host boundary is **`sub_820CBBF0`**. The outer renderer's device/output field (`renderer+4`) is still zero at that boundary. Checkpoint 018 therefore does **not** claim that a Direct3D/Xenos device, backbuffer, render target, or complete graphics interface has been created.

Measured deterministic graphics-slice run:

```text
graphics_init_chain:
  entry               sub_820BEFD0
  result              unsupported@820CBBF0
  generated/helpers   138
  memory operations   8505
  device object       02000080 (host fixture address)
  primary ring        02007140
  secondary buffer    0200F140
  ring descriptor     0220F140
  graphics workers    2 recorded, not executed
  renderer+4          00000000 (unpublished)
```

The deterministic guest addresses are bounded host-fixture addresses, not addresses observed on an Xbox or in xemu.

## `sub_820BEFD0`: ownership and lower graphics object

The exact generated body establishes that `sub_820BEFD0` is not a boolean create-device wrapper. On this path it:

1. receives the original `PlatformRenderer::Init` contract (`r3=0`, `r4=1`, `r5=0`, `r6=0`, `r7=presentation`, `r8=renderer+4`);
2. clears the output slot;
3. requests 24,192 bytes from the runtime allocator for a **24,064-byte** graphics object with **128-byte alignment**;
4. records the raw allocation at `object-4`, zeroes the aligned 24,064-byte object, and initializes it through exact `sub_820CC088`;
5. allocates the initial 4,800-byte internal block;
6. stores the observed flags `0x0C000000` at object offset 23,980;
7. enters exact `sub_820CC100`.

Only successful completion of the full chain would publish the lower object through `renderer+4`. Because Checkpoint 018 stops inside `sub_820CC100`, that publication has not occurred.

The allocator shim is sequence-locked to the ten allocation requests actually reached by this path. Unexpected size, flags, ordering, or unmapped result fails closed.

## Engine, process, loader, and ring boundaries

Exact `sub_820CBFF0` reaches the Xbox graphics/platform imports with the observed arguments. The host boundary validates:

- `VdInitializeEngines(0x1DDD0000, 0x820CB900, 0, 0x82005820, 0x82005CA0)`;
- the two title-termination notifications;
- `VdSetGraphicsInterruptCallback(0x820C60E0, object)`;
- normal title-process classification;
- the one imported-variable slot dereferenced by this path.

The sealed image contains the unresolved loader token `0x000101BE` at `0x820005CC`. The host fixture patches only that imported-variable slot to a mapped platform-global location; provenance verifies the sealed token before the patch. TLS access used by exact `sub_82136728` is likewise provided only in the exact shape consumed here.

The presentation sub-structure entering exact `sub_820C7548` is zeroed on the tested path, causing original code to select its own defaults:

- primary ring: **32 KiB**;
- secondary buffer: **2 MiB**;
- secondary chunk size: **64 KiB**;
- primary ring dword capacity minus one: **8,191**;
- secondary dword capacity: **524,288**.

The platform ring shims validate physical-address translation, ring initialization, read-pointer writeback setup, and system-command GPU identifier ordering. The observed ring-initialization exponent is **12**; an initial test assertion expecting 11 failed closed at the platform boundary and was corrected to the exact generated-code value rather than relaxed.

The imported function named `KiApcNormalRoutineNop` by the generated import table is modeled only for the exact 19-word descriptor shape reached here. The shim verifies the known fixed words, eight sealed-image-derived words, descriptor count, and zero tail, and performs no state mutation.

## Original command/state construction and graphics workers

Checkpoint 018 continues beyond ring setup through exact game-side code:

- `sub_820C5F98`, `sub_820C5EE8`, and `sub_820C73F0` complete on the fresh-ring path;
- `sub_820BEAC8` consumes the sealed count 32 and allocates 672-byte and 512-byte command/state blocks;
- `sub_820D7708` allocates 200 bytes and derives exactly **two** graphics-worker classes from flags `0x0C000000`;
- exact thread wrappers create two records for worker routine `0x820D7578` with 64 KiB stacks and priority 17;
- the bounded scheduler records those workers as runnable but deliberately does **not** execute their asynchronous routines or pretend concurrent GPU-worker progress occurred;
- `sub_820BF930` allocates an 8 KiB command/state workspace and constructs its initial packet/state table through exact `sub_820BF5E0` and `sub_820BF8D0`;
- `sub_820D7920` installs deterministic baseline state and reaches `sub_820CBBF0`.

The new boundary test checks the two worker handles, worker count, ring pointers/capacities, command/state allocation pointers, and deterministic state values before accepting the stop.

## Provenance

`runtime018/verify_provenance.py` verifies **99 exact local generated function bodies** byte-for-byte against the sealed 17-translation-unit ReXGlue corpus. It additionally verifies the four inherited original diagnostic artifacts:

- manager insertion slice from `sub_820701D0`;
- complete `sub_820701D0` entry-to-return wrapper;
- `sub_82070AC8` renderer-caller prefix;
- `sub_820A7990` PlatformRenderer prefix through `sub_820BEFD0`.

New exact graphics bodies include `sub_82136728`, `sub_820BEF28`, `sub_820BEF80`, `sub_820CC088`, `sub_820CBFF0`, `sub_820C7548`, `sub_820BEAC8`, `sub_820D7708`, `sub_820BF5E0`, `sub_820BF8D0`, `sub_820BF930`, `sub_820D7920`, `sub_820CC100`, and `sub_820BEFD0`, plus their required exact save/restore helpers.

Sealed-image checks still bind the startup manager constant, state-pool vtable, thread-object token, all 613 lookup keys, PlatformRenderer 58.0f threshold, and the loader import-variable token.

## Verification

ASan/UBSan acceptance completed before the long combined driver reached its execution-window limit. The combined driver was then resumed for Release from the partially compiled clean Release tree; its interrupted compile log is retained explicitly as `compile-release-interrupted.log`, and successful completion is retained as `compile-release-resume.log`.

Both modes pass:

- CTest: **6/6** Release and **6/6** ASan/UBSan;
- update/startup/renderer/graphics boundary suite: **1,139 assertions**;
- renderer/widget regression: **1,922 assertions**, 239 roots, 418 draws, 125 tree visits, 42,499 checked store bytes, in both native and software-FMA variants;
- visibility: **43,528 checks** over 4,352 inputs;
- fixtures: **12,047 checks + 6,000 deterministic mutations** (1,878 restore-only accepts, 4,122 rejects; mutated game state is never executed).

The full original startup result remains 182,963 generated/helper executions, 10,501 indirect dispatches, and 2,670,630 guest-memory operations. The renderer caller result remains 182,986 executions and 2,671,382 guest-memory operations. The PlatformRenderer prefix remains 104 guest-memory operations before `sub_820BEFD0`.

## Next boundary

The next host convergence target is **`sub_820CBBF0`**. The sealed generated body is already identifiable in `pc/generated/default/castle_crashers_recomp.5.cpp`. It begins with a 1,760-byte stack frame, consumes the presentation descriptor, calls `VdQueryVideoMode`, then reaches resource helpers including `sub_820C44A0`, `sub_820C45C0`, `sub_820BE2D8`, `sub_820BE620`, and later state/presentation helpers.

The next turn should recover the exact body and those direct callees, identify which calls create/publish render-target/backbuffer-like state at object offsets 14,824/14,828/14,832, and model only the unavoidable Xbox video/resource contracts. Unknown formats, flags, resource shapes, and platform return values must remain fail-closed.

Checkpoint 011 remains the latest accepted nxdk/xemu execution. Checkpoint 018 is host original-code convergence only, not native PC gameplay, a new xemu run, or a completed graphics-device claim.
