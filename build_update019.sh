#!/usr/bin/env bash
# Checkpoint 019 host startup/PlatformRenderer convergence build. No downloads are attempted.
set -euo pipefail
cd "$(dirname "$0")"
source ./env.sh
if [[ -n "${CXX:-}" ]]; then CXX="$CXX";
elif [[ -x "$LLVM_ROOT/bin/clang++" ]]; then CXX="$LLVM_ROOT/bin/clang++";
elif command -v clang++ >/dev/null 2>&1; then CXX="$(command -v clang++)";
else echo "No clang++ found; generated PPC scalar runtime requires Clang builtins." >&2; exit 3; fi
logs=logs/checkpoint019/build-final
mkdir -p "$logs" host-bin019
python runtime019/verify_provenance.py > "$logs/update-provenance.log"
python runtime019/verify_vtable_provenance.py > "$logs/vtable-provenance.log"
python runtime019/verify_update_capture_source.py > "$logs/update-capture-source.log"
python runtime019/verify_generated_seal.py > "$logs/generated-seal.log"
for mode in asan release; do
  if [[ $mode == asan ]]; then cmode=Debug; sanitize=ON; else cmode=Release; sanitize=OFF; fi
  build="renderer019/build-$mode"
  cmake -S renderer019 -B "$build" -G Ninja -DCMAKE_CXX_COMPILER="$CXX" -DCMAKE_BUILD_TYPE="$cmode" -DCC_SANITIZERS="$sanitize" > "$logs/configure-$mode.log" 2>&1
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
  cp -f "renderer019/build-release/$exe" "host-bin019/$exe"
done
printf 'Checkpoint 019 is host-only progress beyond the native/xemu Checkpoint 011: exact generated code now executes from PlatformRenderer::Init through sub_820BEFD0 and sub_820CBBF0, including the 640x480 presentation/resource chain: one 1,228,800-byte framebuffer backing resource and two tiled presentation surfaces, stopping fail-closed at sub_820CB988 before the large GPU-state fanout and before outer device publication. A new xemu run is technically due at this milestone, but this checkpoint intentionally excludes the required BIOS/MCPX/EEPROM boot inputs and they are not available in the current execution environment. Checkpoint 011 remains the latest accepted nxdk/xemu target.\n' > "$logs/native-status.txt"
if [[ "${CC_REQUIRE_TARGET:-0}" == 1 ]]; then cat "$logs/native-status.txt" >&2; exit 4; fi
echo 'UPDATE019 HOST ACCEPTANCE PASSED through original presentation/resource creation to sub_820CB988. Checkpoint 011 remains latest native target acceptance; no new xemu run is claimed because the external boot inputs are unavailable in this environment.'
