# Castle Crashers original-Xbox port — Checkpoint 019

## Result

Checkpoint 019 closes the observed `sub_820CBBF0` presentation/resource-creation path with exact original/generated game-side code and moves the honest host boundary to **`sub_820CB988`**.

Starting from Checkpoint 018's exact `PlatformRenderer::Init` state, original code now runs through the lower graphics-object setup, command ring, bounded worker records, `sub_820CBBF0`, three resource constructors/binders, presentation notification, and gamma/state-table generation. The outer renderer's `renderer+4` device/output slot is still zero because `sub_820BEFD0` has not yet returned. No completed Direct3D/Xenos device is claimed.

Measured deterministic graphics slice:

```text
entry                    sub_820BEFD0
result                   unsupported@820CB988
generated/helpers        16,132
guest memory operations  184,985
lower graphics object    02000080 (host fixture address)
resource field +14828    02211730
resource field +14832    0233D770
resource field +14824    0233DAD0
renderer+4               00000000 (still unpublished)
```

These addresses are deterministic host-fixture addresses, not addresses observed on hardware or in xemu.

## Presentation and resource contract

The exact `sub_820CBBF0` branch selected by the existing original 640×480 presentation state creates three resource-like objects:

1. `sub_820C44A0` allocates a 52-byte header and then requests **1,228,800 bytes (`0x12C000`)** with flags `0xBC800000`. The size is exactly `640 × 480 × 4`; this checkpoint describes it as framebuffer-sized backing storage without assigning a stronger render-target/backbuffer semantic than the recovered code proves.
2. The first `sub_820C45C0` path allocates a 48-byte surface object and requests **240 tiles** through `sub_820D62F8`.
3. The second `sub_820C45C0` path allocates another 48-byte surface object and requests another **240 tiles**.

The observed format/state constants on those calls are `0x28280106`, `0x18280186`, and `0x2D200196`. The two tiled allocations consume sequential fresh ranges 0..239 and 240..479 in the original allocator's 6,144-tile domain. Acceptance verifies the resulting 480 set bitmap entries and 5,664 remaining tiles.

The three resource pointers are published by original code at graphics-object offsets 14,828, 14,832, and 14,824 only after their corresponding constructors succeed. The first surface is then consumed by exact `sub_820BE2D8`; the second is consumed by exact `sub_820BE620`.

## Platform boundaries kept narrow

The remaining host shims are true Xbox/video boundaries and are deliberately fixture-shaped:

- `VdQueryVideoMode` accepts the exact stack output pointer reached here and reports only the already-established 640×480 / 60 Hz mode fields consumed by this path.
- `VdQueryVideoFlags` is valid only after that mode query and reports no special bit for this standard fixture.
- `VdCallGraphicsNotificationRoutines` accepts exactly the generated type-1 notification whose four 16-bit dimensions are 640, 480, 640, 480.
- `VdGetCurrentDisplayGamma` is single-use and supplies the sRGB/type-1 host fixture used by the exact generated gamma path. This is a platform fixture, not a claim that retail Castle Crashers queried identical gamma values on every Xbox 360 output mode.
- `sub_820D62F8` is modeled only for the two observed fresh 240-tile requests because the exact body relies on PPC atomic/global-lock instructions not represented by the reduced host context. Unexpected request counts or allocator shapes fail closed.

The general graphics allocator is sequence-locked to the **15 exact allocation shapes** reached through this checkpoint. It does not act as a generic Direct3D/Xenos allocator.

## Exact game-side closure after resources

Checkpoint 019 also executes the original resource binding and presentation-finalization chain needed by the taken branch, including exact `sub_820BE2D8`, `sub_820BE248`, `sub_820BE1A8`, `sub_820BE620`, `sub_820D19B8`, `sub_820C9090`, `sub_820BDCA8`, and the required generated gamma/math helpers.

`sub_820CBBF0` returns successfully through its original epilogue. Its caller `sub_820CC100` then advances to `sub_820CB988`.

`sub_820CB988` is a substantially different next boundary: the sealed generated body performs a large GPU-state initialization fanout, including about one hundred indirect setter calls followed by 26 groups of additional state-table work and later renderer-state helpers. Checkpoint 019 stops before pretending those indirect targets are understood.

## Provenance

`runtime019/verify_provenance.py` verifies **143 exact local generated bodies** byte-for-byte against the sealed generated corpus, plus the inherited manager slice, complete startup wrapper, renderer-caller prefix, and PlatformRenderer prefix. The manual tiled allocator and `Vd*` platform fixtures are intentionally not promoted to generated-body provenance.

Sealed-image checks continue to bind the startup manager constant, state-pool vtable, thread-object token, all 613 lookup keys, PlatformRenderer 58.0 Hz threshold, and loader import-variable token.

## Verification

Both host configurations pass:

- CTest: **6/6 Release** and **6/6 ASan/UBSan**;
- boundary/startup/graphics suite: **1,167 assertions**;
- renderer/widget regression: **1,922 assertions**, 239 roots, 418 draws, 125 tree visits, and 42,499 checked store bytes in both native-FMA and software-FMA variants;
- visibility: **43,528 checks** over 4,352 inputs;
- fixtures: **12,047 checks + 6,000 deterministic mutations** (1,878 restore-only accepts and 4,122 rejects; mutated game state is never executed).

The long combined acceptance driver completed all sanitizer acceptance and then hit the command execution window during Release compilation. `compile-release-interrupted.log` preserves that stop; `compile-release-resume.log` records the successful resumed Release build, after which all Release acceptance passed.

## Native/xemu status

This checkpoint reaches the graphics/resource milestone that makes another native/xemu regression useful. A new xemu run was therefore staged as the next validation gate, but **it was not executed in this environment**: the sealed checkpoints intentionally exclude BIOS/MCPX/EEPROM/HDD inputs, those private boot inputs are absent from the current container/Library, and the external nxdk toolchain referenced by `env.sh` is likewise outside the sealed checkpoint.

The retained Checkpoint 011 native diagnostic source/XBE/ISO and xemu scripts remain present. **Checkpoint 011 is still the latest actual nxdk/xemu acceptance.** Checkpoint 019 does not reinterpret host resource convergence as an xemu result.

## Next boundary

Continue host convergence at **`sub_820CB988`**. Recover its exact indirect setter target table from the sealed image/generated call sites, execute only identified targets, and push through the state fanout toward the later platform/EDRAM boundary. In parallel, when the user's external nxdk + BIOS/MCPX/EEPROM boot inputs are available, run the next native/xemu regression without treating it as proof of Xbox 360 Xenos API equivalence.
