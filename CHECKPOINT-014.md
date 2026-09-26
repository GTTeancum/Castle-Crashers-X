# Castle Crashers original-Xbox port — Checkpoint 014

## Result

Checkpoint 014 removes the synthetic `0xDEAD1000` movie-virtual stop from Checkpoint 013 and replaces it with constructor- and image-proven original dispatch. The host diagnostic can now execute a complete active `sub_8209DE50` update wrapper to normal return on bounded synthetic state while retaining fail-closed behavior for unobserved branches.

The strongest synthetic chain now demonstrated is:

```text
sub_8209DE50
  -> sub_82097720        ordered-map hit
  -> sub_820915F0        active timeline update
  -> 0x820772B0          controller vtable +0x0C, statically proven
  -> 0x82088A08          parser vtable +84 decimal, statically proven
  -> 0x8208A228          parser vtable +88 decimal, statically proven
  -> sub_8208AE78        empty child-list cleanup
  -> sub_8209CC98        empty visible-child traversal
  -> sub_82097720        owner-stack lookup on unwind
  -> normal return
```

The timeline advances from `0x40000000` (2.0f) to `0x40011111` for the 1/60-second update, and the wrapper clears the published active-owner global on successful unwind.

This is still a bounded diagnostic, not a claim of full gameplay. The old real startup fixture remains missing live update-manager state at `0x8225E62C`.

## Static virtual provenance

Two constructors resolve the virtual classes without guessing object identity:

- `sub_82075410` stores vtable `0x8203E118` into the enclosing controller object. The sealed image word at `0x8203E124` (`+0x0C`) is `0x820772B0`.
- `sub_82094048` stores vtable `0x8203F510` into the parser object. The sealed image words at decimal offsets `84` and `88` (`0x8203F564` and `0x8203F568`) are `0x82088A08` and `0x8208A228`.

`runtime014/verify_vtable_provenance.py` checks those image words and ties each table back to the exact generated constructor. The test intentionally distinguishes PPC decimal disassembly offsets from hexadecimal notation.

## Original GameManager construction

`0x820772B0` reads the GameManager pointer at `0x8225E61C`. Instead of hand-authoring that object, Checkpoint 014 imports and executes the exact original `sub_820A1AC0` constructor on the synthetic diagnostic object. Its three immutable float loads are mapped from the sealed image values (`0.0f`, `1.0f`, `5.0f`). The constructor's timebase calls use the existing Xbox-scaled monotonic platform shim.

This gives `0x820772B0` genuine constructor state while keeping the diagnostic separate from the real captured startup fixture.

## Expanded original-code closure

The provenance suite now verifies **22 exact generated bodies** against the sealed generated PC source. Checkpoint 014 adds the original initialization helpers, timer wrappers, GameManager/controller predicate, parser virtuals, and empty-list cleanup needed to close the tested update frame. Unsupported direct-call branches remain explicit hard boundaries and never return fake success.

The initialization side is also stronger: the inactive owner path executes `sub_82094420`, no-resize `sub_820936B0`, `sub_82094530`, `sub_82082390`, the timer wrappers, and the observed empty-parser `sub_8208AB98` path to normal return. Its test reports `funcs=19` and a real inserted key.

## Real captured boundary

The real Checkpoint 011 startup fixture still reports:

```text
root=4012a260 head=405efa20 vtable=8204043c update=8209de50
boundary=memory@8225e62c
```

That remains a truthful boundary: the render-oriented 011 capture did not include the live update-manager global/tree. Checkpoint 014 does not inject the synthetic manager into the real fixture. The next real-data step is still a new capture of `0x8225E62C` and its reachable update state, but the formerly unknown controller and parser virtual targets no longer need to be guessed.

## Verification

Optimized Release and ASan/UBSan Debug both pass all **6/6 CTest targets**. The boundary suite passes **119 assertions** and reports `full_synthetic_update=ok`. Existing regressions remain unchanged:

- renderer: **1,922 assertions**, 239 roots, 418 draws, 125 tree visits, 42,499 checked store bytes, in both native-FMA and software-FMA variants;
- visibility: **43,528 checks** over 4,352 inputs;
- fixtures: **12,047 checks** plus 6,000 deterministic mutations (1,878 restore-only accepts, 4,122 rejects; mutated game state is never executed).

All 17 sealed generated translation units remain unchanged. The standalone checkpoint still excludes the full extracted game/LIVE payload and external ReXGlue/nxdk tool trees. Therefore Checkpoint 011 remains the latest accepted nxdk/xemu target execution; Checkpoint 014 is a host original-code convergence checkpoint.
