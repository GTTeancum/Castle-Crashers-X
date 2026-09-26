# Castle Crashers original-Xbox port — Checkpoint 016

## Result

Checkpoint 016 moves the bounded host proof from the isolated manager writer into the **real original startup function**. The translated `sub_820701D0` now executes from its genuine function entry through original label `0x82070694`, with the diagnostic stop inserted only at that label.

The prefix constructs and publishes the previously missing update manager at `0x8225E62C`, continues through the large state-pool constructor published at `0x8225E608`, and then constructs the system/region state published at `0x8225E63C`.

The measured deterministic run is:

```text
startup_prefix result=ok@00000000
functions=182929
indirect_dispatches=10501
memory_ops=2667232
range=820701D0..82070694
```

This remains a host diagnostic, not a claim that the old Checkpoint 011 live capture has magically acquired missing RAM. That captured fixture is preserved unchanged and still fails truthfully at `memory@0x8225E62C`.

## What original startup now constructs

Starting from a mutable copy of the sealed mapped image plus a deterministic bounded process allocator fixture, the original code reaches and publishes these startup objects:

| Guest global | Purpose in this proof | Deterministic object |
|---|---|---:|
| `0x8225E630` | label/owner state | `0x00071010` |
| `0x8225E604` | small state | `0x00071100` |
| `0x8225E620` | input/state object | `0x00071130` |
| `0x8225E60C` | hash state | `0x000718D0` |
| `0x8225E600` | 14,656-byte pool state | `0x000718F0` |
| `0x8225E62C` | update manager | `0x000758F0` |
| `0x8225E614` | async state | `0x000759C0` |
| `0x8225E634` | event wrapper | `0x000759F0` |
| `0x8225E61C` | game manager | `0x00075DF0` |
| `0x8225E608` | large state pool | `0x00076390` |
| `0x8225E63C` | region/system state | `0x004E0DA0` |

The addresses in the right column belong only to the deterministic host allocator fixture; they are not asserted as addresses from a real Xbox run.

## Large state-pool closure

The major new closure is exact translated `sub_8208CFA0`. Its first large allocation contains **10,500 objects of 248 bytes**. Each object is initialized by exact `sub_820869B0` / `sub_82086BA8` code, including the original virtual call through the sealed table at `0x8203E878 + 0x50`. The sealed image resolves that slot to exact `sub_820867B8`.

The old 10,000-dispatch harness limit was therefore too small for valid original behavior. Checkpoint 016 raises that finite safety limit to 20,000 and the function/memory budgets to finite values large enough for this constructor. The successful prefix uses **10,501 indirect dispatches**, so the new cap still leaves a bounded margin rather than removing the guard.

The state-pool closure also initializes its other original bulk arrays and calls the exact fresh-object cleanup/initialization functions needed on this path. No skipped unknown branch is turned into success; unsupported alternatives remain hard boundaries.

## System/region constructor closure

Exact `sub_8209F7E8`, `sub_8209F9F0`, `sub_8209D2D0`, and their helper closure now run as part of the same startup prefix. The deterministic console-platform fixture supplies a narrowly validated US/NTSC-U region (`0x101`) and exercises the original fallback from the Xbox configuration query.

The resulting original game fields verify as:

```text
system_state+0  = 5
system_state+4  = 2
system_state+8  = 1
system_state+12 = 640
system_state+16 = 480
```

These values demonstrate the original constructor path under the stated deterministic platform fixture; they are not a claim about every region or display mode.

Startup-specific host boundaries remain deliberately narrow: `%i` formatting for the startup label, critical-section initialization for the single-threaded proof, the exact observed Xbox configuration query, `XGetGameRegion`, and `XNotifyPositionUI`. Unknown call shapes fail closed.

## Provenance

`runtime016/verify_provenance.py` now derives the local include list directly from `runtime016/bodies.inc` and verifies **68 exact generated function bodies** byte-for-byte against the 17 sealed ReXGlue translation units.

It separately verifies two diagnostic original slices:

- `sub_820701D0 @ 0x82070434..0x820704C4`: the older manager mid-function slice retained for focused tests;
- `sub_820701D0 entry..0x82070694`: the new startup prefix, with only the wrapper name changed and a diagnostic return appended at the original label.

The verifier also binds the manager's `0.9f` constant at `0x820146A0` and the large-state-pool virtual slot `[0x8203E8C8] = 0x820867B8` to the sealed mapped image. All 17 generated translation units remain unchanged.

## Existing update path remains green

The Checkpoint 015 manager/update closure remains intact:

```text
full synthetic active update: 58 generated executions, 3 original virtual dispatches
manager initializer slice:     48 executions, 583 memory operations
second map insertion:           42 executions, 494 memory operations
```

The full update consumes an original-code-built manager, inserts the active context, advances the timeline, performs the proven virtual calls, and restores the key-0 root context on unwind.

## Verification

Release and ASan/UBSan both pass all **6/6 CTest targets**. Current regression totals are:

- update/startup boundary suite: **407 assertions**;
- renderer/widget regression: **1,922 assertions**, 239 roots, 418 draws, 125 tree visits, 42,499 checked store bytes;
- visibility: **43,528 checks** over 4,352 inputs;
- fixtures: **12,047 checks** plus 6,000 deterministic mutations (1,878 restore-only accepts, 4,122 rejects; mutated game state is never executed).

The generated runtime requires Clang rotate builtins; `build_update016.sh` selects Clang explicitly.

## Next boundary

Immediately after `0x82070694`, original startup allocates a five-slot worker structure, initializes a critical section, and enters the thread/platform wrappers beginning with `sub_820B5D60` (followed by priority, affinity, and resume operations). Checkpoint 016 stops before inventing thread behavior. The next implementation should provide a real bounded thread/scheduling abstraction for those Xbox calls rather than returning synthetic success.

Checkpoint 011 remains the latest accepted nxdk/xemu target execution. Checkpoint 016 is a host original-startup convergence checkpoint and does not claim a new native Xbox build or live gameplay milestone.
