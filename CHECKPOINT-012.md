# Castle Crashers original-Xbox port — Checkpoint 012

## Result

Checkpoint 012 moves the Xbox-side boundary from **render-only widget dispatch** into the beginning of the **real original update path** without inventing game state. The unchanged generated `sub_8209CC98` child-update walker and unchanged `sub_8209DE50` widget update wrapper now execute in the portable runtime. The prior Checkpoint 011 rendering regression remains intact.

On the real captured startup fixture, `sub_8209CC98` follows the captured child vtable update slot to `0x8209DE50`. The wrapper then stops at an exact missing read of **`0x8225E62C`**, the live update-manager global that was never present in the render-only 011 capture. This is a more precise boundary than the previous unknown/unported update dispatch, and it deliberately does **not** synthesize the missing manager.

This checkpoint is **not Xbox gameplay**. No fresh XBE or xemu run is claimed here. Checkpoint 011 remains the latest genuine original-Xbox/xemu target evidence because the standalone restored checkpoint lacks the prepared nxdk tree and this scratch runtime cannot fetch it.

## Original code added unchanged

Five generated bodies are imported with exact-source provenance checks:

| Symbol | Generated body bytes | SHA-256 |
|---|---:|---|
| `__savegprlr_29` | 342 | `fa21b0c03f2eb05342ebfbbec2487ac4fd8d1d62ad51a57af91179d736ef1454` |
| `__restgprlr_29` | 375 | `9f85104a5bf50cabd67f5d1914296c9de3f31c2068ed13e7d7d01b28fa9a5e94` |
| `sub_8208C5D8` | 74 | `b5c4c96430191a6dc962dcc9918138d71d0f2486ab66c596ea78cee662faafb5` |
| `sub_8209CC98` | 1,792 | `28d200bf565ff0ce5a73982fbad34ddb368b95a1d6f2cf32bb8529c0e17bd016` |
| `sub_8209DE50` | 4,074 | `ccf8e40e99c1ea313255fc49721f6fb442b59259ef882d677e89786d80f4abb6` |

The sealed 17 `pc/generated/default/castle_crashers_recomp.*.cpp` translation units still match Checkpoint 011 byte-for-byte. The new PC tracing hook is outside generated game code.

## Verified update behavior

`sub_8209CC98` honors the original visibility gate, walks the original linked child list, and dispatches each child through vtable slot `+8`. Tests cover hidden/null lists, a synthetic two-child recursive update, cycle rejection before original execution, ABI restoration, and the real startup snapshot.

`sub_8209DE50` is exercised on bounded synthetic states along both important branches. One branch reaches the original owner-stack lookup `sub_82097720`; the other copies owner timeline state to global `0x822666DC` and reaches `sub_820915F0`. Those two large dependencies are **explicit hard-failure boundaries** in this diagnostic runtime. They are not success stubs and must be replaced by real supported behavior before gameplay acceptance.

The actual startup fixture reports:

```text
root=4012a260 head=405efa20 vtable=8204043c update=8209de50
boundary=memory@8225e62c
```

That missing address is useful evidence: it proves the old render capture did not include the live update-manager object and identifies the next state that must be observed rather than guessed.

## Passive PC update tracer

The PC reference now has an opt-in, one-shot update tracer. With a capture-enabled traced build, set `CC_UPDATE_CAPTURE=1` and create `capture-update-next` under the existing capture root. The next real `sub_8209DE50` invocation is traced through nested original generated code, including loads/stores, direct functions and indirect dispatches, while the original function still executes exactly once.

The tracer was source-verified in this checkpoint but **not executed** because the restored checkpoint intentionally excludes the full extracted game/assets and external ReXGlue SDK/build kit. It is designed to capture the missing `0x8225E62C` manager state, owner state such as the uncaptured owner vtable, and the actually used `sub_820915F0` indirect-call closure.

## Host acceptance

Both ASan/UBSan Debug and optimized Release pass all five CTest targets. The new update-boundary suite passes **56 assertions**. The unchanged 011 render regression still passes **1,922 assertions per native/software-FMA variant**, covering 239 roots, 418 draws, 125 tree visits and 42,499 checked store bytes. Visibility tests pass 43,528 checks over 4,352 inputs. Fixture validation passes 12,047 checks per build plus 6,000 deterministic mutations (1,878 structurally accepted/restored; 4,122 rejected; mutated game state is never executed).

## Native target status

`nxdk-update012/` is prepared to execute the captured update-boundary self-test before the existing 011 native render regression. A fresh target build was not performed because the exact nxdk/build-kit tree is absent from this restored checkpoint. The pinned nxdk revision remains `58427c078b4ccb0121f359b6b6c536b3b2914976`; public repository access was verified, but archive/clone retrieval from this scratch runtime is blocked.

`build_update012.sh` therefore reports native target state separately instead of treating host acceptance as Xbox acceptance. Setting `CC_REQUIRE_TARGET=1` makes a missing target toolchain fatal.

## Next engineering boundary

The next useful move is a fresh live PC update capture, not a broad import of the static call graph. `sub_820915F0` is large and has many virtual/platform-dependent paths; importing its entire theoretical transitive closure would recreate exactly the unsupported-stub problem this port is avoiding. A real trace will identify the bounded objects, virtual slots, resources and helper calls Castle Crashers actually uses on the startup/menu/game path, after which that observed closure can be ported and tested toward the first controllable knight.

The compiled full-game policy remains preserved. Audio, saves, original resource construction, live Xbox menu/input/gameplay, full-game RAM fit and physical hardware remain outside this checkpoint.
