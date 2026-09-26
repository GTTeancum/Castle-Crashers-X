# Castle Crashers original-Xbox port — Checkpoint 015

## Result

Checkpoint 015 removes the remaining hand-built update-manager tree from the bounded synthetic update path. The manager published at `0x8225E62C` is now allocated, initialized, populated, and later traversed by translated original game code.

The newly recovered writer is inside `sub_820701D0`. For diagnostic execution, this checkpoint exposes the exact translated instruction slice beginning at original address `0x82070434` and ending immediately before `0x820704C4`. This is deliberately described as a **mid-function diagnostic entry**, not as a recovered original function boundary.

The demonstrated synthetic chain is now:

```text
sub_820701D0 @ 0x82070434   diagnostic mid-function entry
  -> sub_820B5EB8          allocator-index lookup
  -> sub_8209BDD8          original allocation path
  -> sub_82097650          ordered-map construction
  -> sub_82097720          original key=0 insertion/lookup
  -> ordered-map insertion closure
  -> store manager pointer at 0x8225E62C

sub_8209DE50
  -> sub_82097720          insert/find active widget context
  -> sub_820915F0          active timeline update
  -> 0x820772B0            controller virtual, constructor/image proven
  -> 0x82088A08            parser virtual, constructor/image proven
  -> 0x8208A228            parser virtual, constructor/image proven
  -> sub_8208AE78          empty child-list cleanup
  -> sub_8209CC98          empty visible-child traversal
  -> sub_82097720          restore key=0 root context on unwind
  -> normal return
```

This closes an important structural gap in Checkpoint 014: the full synthetic update no longer receives a test-authored manager sentinel/tree. Original code creates the manager and its red-black-tree state, inserts the root context, inserts the active widget context, and restores the root context during unwind.

This remains a bounded host diagnostic, not a claim of full live gameplay. The old real startup capture still stops truthfully at missing live state for `0x8225E62C`.

## Original manager construction

The recovered slice allocates a 140-byte manager object and initializes the fields used by the update wrapper. In the deterministic diagnostic allocator fixture the original code produces:

```text
manager global       0x00071010
map sentinel         0x000710B0
root node            0x00071140
root context value   0x00071150
nested sentinel      0x00071170
```

The manager initializer also reads an immutable float at `0x820146A0`. `runtime015/verify_provenance.py` now checks the sealed mapped image directly and requires the original bits `0x3F666666` (`0.9f`). No test-side substitute for that constant is accepted.

The initial map entry uses key `0`. A second test then drives the exact ordered-map insertion closure with key `0x00040000`; it returns value storage `0x000711B0` after **42 generated function executions** and **494 memory operations**. This verifies that the initializer's one-node tree is not merely shaped correctly for one lookup: it can be extended by the same original insertion machinery used by the active update path.

## Full bounded update result

The full synthetic active update now starts from the manager produced by the original initializer slice. It reports:

```text
active_chain result=ok@00000000 funcs=58 dispatches=3
synthetic_chain manager=00071010 root_value=00071150 timeline_result=ok timeline_bits=40011111
```

The wrapper inserts the active widget context, advances the timeline from `0x40000000` (2.0f) to `0x40011111` for the 1/60-second update, executes the three previously proven virtual dispatches, and unwinds back to the original key-0 context. Manager depth returns to zero and `manager+88` again points to the root context value `0x00071150`.

The standalone manager-initializer diagnostic reports **48 generated function executions** and **583 memory operations** before publishing `0x00071010` at `0x8225E62C`.

## Provenance and fail-closed behavior

Checkpoint 015 verifies **35 exact generated function bodies** byte-for-byte against the sealed ReXGlue-generated PC sources, plus the one exact mid-function manager slice described above. The slice verifier checks both its source range and the translated store that targets `0x8225E62C`.

Unsupported branches remain explicit hard boundaries. No unknown allocator, tree, parser, renderer, or game branch is converted into a fake success return. The old real fixture is also kept isolated from the synthetic allocator/manager fixture.

All 17 sealed generated translation units remain unchanged.

## Real captured boundary

The existing Checkpoint 011 startup fixture still reports:

```text
root=4012a260 head=405efa20 vtable=8204043c update=8209de50
boundary=memory@8225e62c
```

Checkpoint 015 intentionally does **not** inject the synthetic manager into this real captured fixture. A new live capture that contains `0x8225E62C` and its reachable manager/allocator state is still required to convert this host proof into a real-state continuation. The currently packaged checkpoint does not include the full original LIVE/game payload needed to recreate that capture from scratch.

## Verification

Optimized Release and ASan/UBSan Debug both pass all **6/6 CTest targets**. The update-boundary suite passes **167 assertions**. Existing regressions also remain clean in both configurations:

- renderer: **1,922 assertions**, 239 roots, 418 draws, 125 tree visits, 42,499 checked store bytes, in both native-FMA and software-FMA variants;
- visibility: **43,528 checks** over 4,352 inputs;
- fixtures: **12,047 checks** plus 6,000 deterministic mutations (1,878 restore-only accepts, 4,122 rejects; mutated game state is never executed).

The generated runtime sources require Clang rotate builtins; `build_update015.sh` therefore selects Clang explicitly instead of allowing CMake to fall back to GCC.

Checkpoint 011 remains the latest accepted nxdk/xemu target execution. Checkpoint 015 is a host original-code manager/update convergence checkpoint and does not claim a new native Xbox build or live gameplay milestone.
