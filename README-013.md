# Checkpoint 013 reproduction

Run the complete host acceptance with:

```bash
./build_update013.sh
```

The script performs exact-body provenance and sealed-generated-source checks, ASan/UBSan and Release builds, the 013 update/timeline boundary suite, and the retained widget/visibility/fixture regressions. It uses the prepared LLVM from `env.sh` when available and falls back to `clang++` on `PATH`.

If the pinned prepared nxdk tree is available at `NXDK_DIR`, the same script prepares and builds `nxdk-update013`. To require a native build:

```bash
CC_REQUIRE_TARGET=1 ./build_update013.sh
```

`nxdk-update013` is source-prepared to run both the synthetic map/timeline chain self-test and the real captured-startup boundary test before the existing Checkpoint 011 renderer regression.

For the next live PC evidence, configure the PC reference with `CC_RENDER_CAPTURE=ON` and `CC_SCENE_TRACE008=ON`, set `CC_RENDER_CAPTURE_DIR` and `CC_UPDATE_CAPTURE=1`, then create `capture-update-next` inside the capture root while the desired scene is live. The next real `sub_8209DE50` call is traced without replacing its execution.
