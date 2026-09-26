#!/usr/bin/env bash
# Checkpoint 017 host startup/PlatformRenderer convergence build. No downloads are attempted.
set -euo pipefail
cd "$(dirname "$0")"
source ./env.sh
if [[ -n "${CXX:-}" ]]; then CXX="$CXX";
elif [[ -x "$LLVM_ROOT/bin/clang++" ]]; then CXX="$LLVM_ROOT/bin/clang++";
elif command -v clang++ >/dev/null 2>&1; then CXX="$(command -v clang++)";
else echo "No clang++ found; generated PPC scalar runtime requires Clang builtins." >&2; exit 3; fi
logs=logs/checkpoint017/build-final
mkdir -p "$logs" host-bin017
python runtime017/verify_provenance.py > "$logs/update-provenance.log"
python runtime017/verify_vtable_provenance.py > "$logs/vtable-provenance.log"
python runtime017/verify_update_capture_source.py > "$logs/update-capture-source.log"
python runtime017/verify_generated_seal.py > "$logs/generated-seal.log"
for mode in asan release; do
  if [[ $mode == asan ]]; then cmode=Debug; sanitize=ON; else cmode=Release; sanitize=OFF; fi
  build="renderer017/build-$mode"
  cmake -S renderer017 -B "$build" -G Ninja -DCMAKE_CXX_COMPILER="$CXX" -DCMAKE_BUILD_TYPE="$cmode" -DCC_SANITIZERS="$sanitize" > "$logs/configure-$mode.log" 2>&1
  cmake --build "$build" -j4 > "$logs/compile-$mode.log" 2>&1
  ASAN_OPTIONS=detect_leaks=0 ctest --test-dir "$build" --output-on-failure > "$logs/ctest-$mode.log" 2>&1
  ASAN_OPTIONS=detect_leaks=0 "$build/cc_update_boundary_tests" renderer011/startup.cct castle-crashers-port/reference/default.image.bin > "$logs/update-boundary-$mode.log" 2>&1
  ASAN_OPTIONS=detect_leaks=0 "$build/cc_visibility_tests" > "$logs/visibility-$mode.log" 2>&1
  for variant in native soft; do
    [[ $variant == native ]] && testexe=cc_widget_tests || testexe=cc_widget_tests_soft
    ASAN_OPTIONS=detect_leaks=0 "$build/$testexe" renderer011/{startup,menu,book}.cct > "$logs/widget-$mode-$variant.log" 2>&1
  done
  ASAN_OPTIONS=detect_leaks=0 "$build/cc_fixture_tests" renderer011/{startup,menu,book}.cct > "$logs/fixture-$mode.log" 2>&1
done
for exe in cc_update_boundary_tests cc_visibility_tests cc_widget_tests cc_widget_tests_soft cc_fixture_tests; do
  cp -f "renderer017/build-release/$exe" "host-bin017/$exe"
done
printf 'NOT UPDATED: Checkpoint 017 closes the original startup initializer, models the observed five-worker lifecycle, publishes the renderer object, and executes PlatformRenderer::Init up to the first graphics-device helper at 0x820BEFD0. Checkpoint 011 remains the latest accepted nxdk/xemu target.\n' > "$logs/native-status.txt"
if [[ "${CC_REQUIRE_TARGET:-0}" == 1 ]]; then cat "$logs/native-status.txt" >&2; exit 4; fi
echo 'UPDATE017 HOST ACCEPTANCE PASSED through PlatformRenderer::Init prefix. Checkpoint 011 remains latest native target acceptance.'
