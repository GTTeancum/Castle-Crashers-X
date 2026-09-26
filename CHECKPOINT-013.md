# Castle Crashers original-Xbox port — Checkpoint 013

## Result

Checkpoint 013 pushes the original update path two functions beyond Checkpoint 012. The portable runtime now executes unchanged generated bodies for **`sub_82097720`** (the ordered-map lookup used by the update owner stack) and **`sub_820915F0`** (the large timeline/update owner routine), in addition to the unchanged `sub_8209CC98` and `sub_8209DE50` path already established.

The strongest bounded chain now demonstrated is:

```text
sub_8209DE50
  -> sub_82097720  [real ordered-map hit, no allocator/insertion helper]
  -> sub_820915F0 [real active-owner timeline increment]
  -> movie-object vtable slot +12
  -> explicit dispatch failure because the real movie object/vtable is not in the old render capture
```

This deliberately stops at the first scene-specific virtual target rather than inventing an object identity or success stub. Checkpoint 011 is still the latest genuine Xbox/xemu execution because the restored workspace does not include the prepared nxdk tree.

## New unchanged original bodies

| Symbol | Generated body bytes | SHA-256 |
|---|---:|---|
| `sub_82097720` | 4,387 | `ce3714837a3b40d5fc404a45242c342b65d5a1875946eadc2a079068188487d2` |
| `sub_820915F0` | 20,449 | `1b2e8d2e8e8bb1d35d72f14e5cb08b89ee1dedcf8625489f06383868bf3d044d` |

Together with the five exact 012 bodies, seven imported originals pass byte-for-byte provenance checks against the sealed generated PC source. All 17 generated translation units remain unchanged from the Checkpoint 011 seal.

## Ordered-map hit path

`sub_82097720` is an ordered-tree lookup. Its missing-key branch leads into insertion/allocation helpers that are not yet supported. The new bounded test constructs a valid tree containing the requested widget key, so the unchanged original function follows only its genuine lookup path and returns the existing node payload address (`0x00061110` in the synthetic fixture). None of the insertion helpers is called.

Those insertion helpers remain explicit `Error::unsupported` boundaries. They never return fake success.

## Timeline/update owner entry

With a valid map hit, the unchanged `sub_8209DE50` wrapper stores the returned owner-stack entry, publishes the owner timeline identifier to `0x822666DC`, and enters the unchanged `sub_820915F0` body.

The active-owner synthetic path starts its timeline float at `0x40000000` (2.0f). After a 1/60-second update, the original body stores `0x40011111`, then loads the movie object, its vtable, and slot `+12`. The test deliberately places an unknown target (`0xDEAD1000`) there; the runtime reports an explicit dispatch failure at that exact address. This verifies the original mutation and dispatch path without pretending to know the real class.

The initialization path is also entered and now reaches the next real helper **`sub_82094420`**. That helper remains a hard boundary in this checkpoint because the actual startup capture is already on the active-owner path (`owner+10345 == 1`), making live active-path evidence the higher-value next step.

## Real startup capture

The real Checkpoint 011 startup fixture still reports:

```text
root=4012a260 head=405efa20 vtable=8204043c update=8209de50
boundary=memory@8225e62c
```

That is expected: the 011 fixture was captured from rendering, so the global live update-manager pointer at `0x8225E62C` was never observed. Checkpoint 013 does not fill that hole with synthetic state when running the real fixture. Synthetic objects exist only in isolated contract tests.

## PC trace prepared for the real missing state

The opt-in one-shot PC tracer from 012 remains the intended bridge across this boundary. A capture-enabled PC reference build can set `CC_UPDATE_CAPTURE=1` and consume `capture-update-next` on the next real `sub_8209DE50` invocation. Because the tracer starts before the wrapper, it records the manager lookup, owner state, nested `sub_820915F0` loads/stores, and indirect targets while still executing the original generated code exactly once.

It was not run here because the standalone checkpoint excludes the full extracted game/assets and external ReXGlue/build-kit dependencies. The next capture specifically needs the real `0x8225E62C` manager tree, `owner+0` movie object, and movie vtable slot `+12` target.

## Verification

ASan/UBSan Debug and optimized Release both pass all five CTest targets. The 013 boundary suite passes **92 assertions**. The prior rendering regression remains unchanged at **1,922 assertions per native/software-FMA variant**, 239 roots, 418 draws, 125 tree visits and 42,499 checked store bytes. Visibility testing remains 43,528 checks over 4,352 inputs. Fixture validation remains 12,047 checks per build plus 6,000 deterministic mutations.

`nxdk-update013/` is prepared to run a 7/7 synthetic chain self-test and the 7/7 captured boundary self-test before the existing 011 native renderer regression. A new XBE/ISO cannot be truthfully claimed until the exact prepared nxdk tree is restored. `CC_REQUIRE_TARGET=1 ./build_update013.sh` makes that absence fatal.

The full-game policy remains preserved. Live Xbox input/menu/gameplay, original resource construction, audio, saves, complete RAM fit and physical hardware are not verified by this checkpoint.
