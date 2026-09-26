# Castle Crashers — Checkpoint 011

**Original widget-container rendering and original visibility accessors on nxdk/xemu. Not a live Xbox game/update/input loop.**

Read `CHECKPOINT-011.md` and `build-status011.json` for the measured scope and hashes. The active target is `nxdk-widget011`. Historical module numbers identify shared source, not independent current deliverables. The compiled base full-game policy remains in `port009/` and `pc/src/full_game009.cpp`.

## Prepared offline layout

```text
work/
  CastleCrashers-Checkpoint-011/
  buildkit/sources/nxdk/
  tools/llvm/LLVM-20.1.8-Linux-X64/
  tools/rexglue/linux-amd64/
  tools/host/bin/                     # built Bison/flex
  tools/xemu/squashfs-root/usr/bin/xemu
```

The already supplied BuildKit provides the exact source/tool packages. `tools/restore_buildkit.py` reconstructs the numbered volumes; `tools/prepare004.sh` prepares the host tools. `env.sh` locates sibling directories, with `LLVM_ROOT`, `REXSDK_ROOT`, and `NXDK_DIR` overrides. Linux development headers/libraries, Git, Make, CMake, Ninja and Python are still required. Emulator capture additionally needs Xvfb/X11, Pillow, NumPy, FFmpeg and software-capable OpenGL. No package installer or network download runs in the diagnostic build script.

## Build and host-test

```bash
bash build_widget011.sh
```

This verifies original-code provenance, reconverts the three raw captures, builds/test Debug ASan/UBSan and optimized Release with system/software FMA variants, compares twelve preview images across all four variants, exercises malformed fixtures/visibility semantics, runs memory/mode/contract guards, then links and reads back the native ISO. The telemetry unit tests deliberately use the packaged accepted evidence, not a newly booted emulator.

Outputs:

```text
nxdk-widget011/bin/default.xbe
nxdk-widget011/CastleCrashers-Widget011.iso
nxdk-widget011/main.map
logs/checkpoint011/build-final/
```

The input format is still CCST008, now accepting the observed `8209CD08` and `8209DF48` roots alongside the supported older roots. Unknown flags remain invalid; the absent-counter flag is restricted to no-draw owner/container calls. The setter/getter are callable test entries, not accepted arbitrary fixture roots. Maps remain bounded to 64 regions and 256 KiB workspace backing. Arbitrary mutated serialized memory is parsed/restored only, not executed as game code.

**Do not apply a blanket string replacement to checkpoint numbers:** `010` also occurs inside valid GPU constants. The unchanged native backend and dedicated regression tests protect the blend/write-mask contract.

## New bounded xemu run

Use the existing private BIOS/MCPX. A fresh sparse test disk can be made with:

```bash
python3 tools/xemu005/make_test_disk.py /path/to/new-test-hdd.raw
```

The generator refuses overwrite. No firmware/dashboard is generated. Start a display and use a fresh log directory:

```bash
source env.sh
Xvfb :98 -screen 0 800x600x24 -ac -nolisten tcp &
xpid=$!
trap 'kill "$xpid" 2>/dev/null || true' EXIT
python3 tools/xemu011/run_diagnostic.py \
  --xemu "$CC_BASE/tools/xemu/squashfs-root/usr/bin/xemu" \
  --bios /path/to/BIOS/xbox-4627_debug.bin \
  --mcpx /path/to/MCPX/mcpx_1.0.bin \
  --hdd /path/to/new-test-hdd.raw \
  --iso "$PWD/nxdk-widget011/CastleCrashers-Widget011.iso" \
  --map "$PWD/nxdk-widget011/main.map" \
  --output "$PWD/logs/checkpoint011/new-xemu-run" \
  --display :98 --seconds 240 --interval 0.5 --video
python3 tools/accept_widget011.py \
  --run logs/checkpoint011/new-xemu-run \
  --reference logs/checkpoint011/build-final \
  --images screenshots011-new \
  --iso nxdk-widget011/CastleCrashers-Widget011.iso \
  --output logs/checkpoint011/new-accepted.json
```

**Both telemetry and visual acceptance are required.** The harness checks 64 MiB, all nine phases, exact geometry, original visibility changes, resident restore counts, control masks, mode policy and both unload recoveries. The second command checks the actually executed ISO hash and all six visual states. A blank boot screen cannot substitute for a hidden title snapshot. No guest memory is changed by the external harness; the program itself calls its original visibility setter.

`tools/xemu011/dump_debug.py` is a separate investigation-only readback harness used during the failed first visual attempt. It pauses the VM and reads this diagnostic's own Scene/texture/vertex/command buffers. Its structure-size assumptions are specific to the accompanying nxdk ABI. It is not the normal acceptance launcher.

## PC reference

The exact PC capture binary and Xenos plugin are under `pc/build011/`. Regenerate `castle-crashers-port/extracted/` from the original LIVE container before launching the PC reference; complete game files are not duplicated here.

```bash
source env.sh
cmake -S pc -B pc/build011 -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_CXX_COMPILER="$LLVM_ROOT/bin/clang++" \
  -Drexglue_DIR="$REXSDK_ROOT/lib/cmake/rexglue" \
  -DCC_RENDER_CAPTURE=ON -DCC_SCENE_TRACE008=ON
cmake --build pc/build011 -j4
CC_DISPLAY=:99 bash run_pc.sh --gpu_plugin=xenos \
  --vulkan_require_geometry_shader=false \
  --vulkan_require_fill_mode_non_solid=false \
  --mnk_mode=true --license_mask=0 \
  --video_mode_width=640 --video_mode_height=480 \
  --window_width=640 --window_height=480
```

The launch needs an existing X display. Override `VK_ICD_FILENAMES` for a different available driver; the scratch default is `/usr/lib/chromium/vk_swiftshader_icd.json`. The launcher now defaults to `build011`. Capturing is opt-in, and the packaged passive hooks retain the original function calls. `pc_session011.py` refuses to overwrite the saved session; use a fresh worktree for a new recording. The exact launch environment, inputs and captured root paths are logged.

## What remains

The next observed outer rendering caller is `820759A8`. The neighboring widget update slot is `8209DE50`; its call chain includes `820915F0` and `8209CC98`. Those are static observations, not code advertised as ported. Original resource construction, live update/timeline/controller state, additional shaders/masks/render targets, audio, saves, campaign and physical hardware remain unverified.

This private checkpoint contains game-derived code and captured artwork, not an asset-free public release. Preserve third-party notices. Firmware/MCPX/EEPROM/HDD, user profiles, full game/tool distributions and build caches are excluded. Failed attempts are labelled and retained; only the final fixed ISO has complete visual acceptance.
