# Castle Crashers original-Xbox port — Checkpoint 017

## Result

Checkpoint 017 closes the complete translated `sub_820701D0` startup initializer, crosses its five-worker Xbox thread setup with a bounded scheduler model, returns to the real caller `sub_82070AC8`, constructs and publishes the 30,216-byte renderer object, and enters the original `PlatformRenderer::Init` candidate at `0x820A7990`.

The current honest host boundary is now the first graphics-device helper, `sub_820BEFD0`. Checkpoint 017 does **not** report a Direct3D device as successfully created and does not replace that call with a fake success.

Measured deterministic runs:

```text
startup_full:
  result              ok
  generated/helpers   182963
  indirect dispatches 10501
  memory operations   2670630
  range               820701D0..return

renderer_caller_prefix:
  result              ok
  generated/helpers   182986
  indirect dispatches 10501
  memory operations   2671382
  range               82070AC8..before 820A7990
  renderer global     [8225E628] = 00501060

platform_init_prefix:
  result              ok
  generated/helpers   2
  memory operations   104
  range               820A7990..before 820BEFD0
  prepared mode       640x480 at 60 Hz fixture
```

The deterministic guest addresses above belong only to the bounded host allocator fixture. They are not claimed as addresses from a live Xbox run.

## Complete original startup closure

The prior diagnostic stop inside `sub_820701D0` has been removed. The exact generated body now executes from the real entry through its original epilogue and restores the caller stack/LR.

After the Checkpoint 016 system/region state, original startup creates five worker slots. The observed call contract is preserved exactly:

- `ExCreateThread` receives startup thunk `0x820B79B8`, worker routine `0x820B0E80`, parameter `0..4`, and suspended-create flag `1`;
- the original wrappers then set base priority `-1`;
- affinity masks are `2, 4, 8, 16, 32`;
- each handle is resumed once.

The host model records only this finite observable lifecycle. It deliberately does **not** execute `sub_820B0E80`, which is an intentional worker loop. Unexpected handle, priority, affinity, type-token, or resume shapes fail closed.

The final startup table constructor also completes. Its state at `0x8225E610` contains 613 entries, and acceptance checks every entry against the sealed source table `0x82229938 + index*40` for keys `0..612`.

## Return to the real caller and renderer construction

With startup returning normally, Checkpoint 017 continues in original `sub_82070AC8`. On the observed `r3=0` initialization path it:

1. executes the original second-stage initialization pass;
2. sets the original small-state enable byte;
3. allocates 30,216 bytes through the existing process allocator path;
4. executes exact `sub_820A7668` to construct the renderer object;
5. publishes it at guest global `0x8225E628`;
6. prepares `r1+112` as the argument for `sub_820A7990`.

Unobserved branches in the large `sub_8209A728` helper remain explicit hard boundaries. They are compiled but are not silently treated as successful.

## PlatformRenderer::Init entry

The exact prefix of `sub_820A7990` now executes. A narrowly validated `XGetVideoMode` host boundary supplies the deterministic standard test mode used by this proof: 640×480, 60.0 Hz, with no HD/widescreen/interlace feature flags asserted.

The original game code consumes that descriptor, writes renderer feature bytes, constructs its presentation parameters, and reaches the first graphics-device helper with the original register contract:

```text
r3 = 0
r4 = 1
r5 = 0
r6 = 0
r7 = pointer to presentation parameters
r8 = renderer + 4
presentation width  = 640
presentation height = 480
next call            = sub_820BEFD0
```

The sealed mapped image contains the original 58.0f refresh comparison constant at `0x82042678`; provenance checks bind that constant to the tested 60 Hz path.

## Provenance

`runtime017/verify_provenance.py` verifies **80 exact local generated function bodies** byte-for-byte against the 17 sealed ReXGlue translation units. It separately verifies these original diagnostic artifacts:

- `sub_820701D0 @ 0x82070434..0x820704C4` manager slice;
- complete `sub_820701D0` wrapper, entry through original return;
- `sub_82070AC8` entry through immediately before `0x820A7990`;
- `sub_820A7990` entry through immediately before `0x820BEFD0`.

The verifier also binds the manager `0.9f` constant, the 10,500-object state-pool virtual slot, the Xbox thread-object type token, all 613 lookup keys, and the PlatformRenderer 58.0f refresh threshold to the sealed mapped image. The 17 generated translation units remain unchanged.

## Verification

Release and ASan/UBSan both pass all **6/6 CTest targets**. Regression totals are:

- update/startup/renderer-boundary suite: **1,078 assertions**;
- renderer/widget regression: **1,922 assertions**, 239 roots, 418 draws, 125 tree visits, 42,499 checked store bytes;
- visibility: **43,528 checks** over 4,352 inputs;
- fixtures: **12,047 checks** plus 6,000 deterministic mutations (1,878 restore-only accepts, 4,122 rejects; mutated game state is never executed).

The old real Checkpoint 011 capture remains unchanged and still fails truthfully at `memory@0x8225E62C`; this checkpoint does not synthesize missing RAM into that capture.

## Next boundary

The next host convergence target is `sub_820BEFD0`, the first graphics-device helper reached by original `PlatformRenderer::Init`. Its translated body begins by allocating/initializing the lower-level graphics state and then enters Xbox GPU/device support routines. The next step should model or replace that boundary based on its observed state contract, not return unconditional success.

Checkpoint 011 remains the latest accepted nxdk/xemu execution. Checkpoint 017 is a host original-startup/renderer convergence checkpoint, not a new native Xbox or live-gameplay claim.
