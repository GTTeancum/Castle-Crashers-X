# Checkpoint 012 reproduction

Checkpoint 012 is a cumulative private development checkpoint. It adds original update-walker/wrapper execution and a passive PC update tracer on top of Checkpoint 011.

## Host verification

Run:

```bash
./build_update012.sh
```

The script uses the prepared LLVM from `env.sh` when present and otherwise falls back to `clang++` on `PATH`. It runs exact-body provenance, sealed-generated-source verification, ASan/UBSan and Release CTests, the new update-boundary tests, and the existing widget/visibility/fixture regressions.

If the exact prepared nxdk tree exists at `NXDK_DIR`, the script also prepares `nxdk-update012/bin` and builds the native target. To require a native target build rather than permit a host-only checkpoint:

```bash
CC_REQUIRE_TARGET=1 ./build_update012.sh
```

## One-shot live update capture

A PC build used for the next capture must be configured with both `CC_RENDER_CAPTURE=ON` and `CC_SCENE_TRACE008=ON`. At runtime use the existing `CC_RENDER_CAPTURE_DIR` and additionally set:

```text
CC_UPDATE_CAPTURE=1
```

When the desired scene is live, create an empty file named:

```text
capture-update-next
```

inside the capture root. The marker is consumed once. The next original `sub_8209DE50` invocation receives a dedicated `update-NNNNNN` trace. The hook always calls the original generated function exactly once; it does not repair or inject guest state.

## Important status distinction

Host acceptance is complete for the bounded 012 slice. A new 012 XBE/xemu acceptance is **not** included. The last verified native target remains Checkpoint 011.
