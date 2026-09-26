#!/usr/bin/env bash
# Checkpoint 013 host/timeline-boundary build. No downloads are attempted.
set -euo pipefail
cd "$(dirname "$0")"
source ./env.sh
if [[ -n "${CXX:-}" ]]; then CXX="$CXX";
elif [[ -x "$LLVM_ROOT/bin/clang++" ]]; then CXX="$LLVM_ROOT/bin/clang++";
elif command -v clang++ >/dev/null 2>&1; then CXX="$(command -v clang++)";
else echo "No clang++ found; generated PPC scalar runtime requires Clang builtins." >&2; exit 3; fi
logs=logs/checkpoint013/build-final
mkdir -p "$logs" host-bin013
python runtime013/verify_provenance.py > "$logs/update-provenance.log"
python runtime012/verify_update_capture_source.py > "$logs/update-capture-source.log"
python runtime012/verify_generated_seal.py > "$logs/generated-seal.log"
for mode in asan release; do
  if [[ $mode == asan ]]; then cmode=Debug; sanitize=ON; else cmode=Release; sanitize=OFF; fi
  build="renderer013/build-$mode"
  cmake -S renderer013 -B "$build" -G Ninja -DCMAKE_CXX_COMPILER="$CXX" -DCMAKE_BUILD_TYPE="$cmode" -DCC_SANITIZERS="$sanitize" > "$logs/configure-$mode.log" 2>&1
  cmake --build "$build" -j4 > "$logs/compile-$mode.log" 2>&1
  ASAN_OPTIONS=detect_leaks=1 ctest --test-dir "$build" --output-on-failure > "$logs/ctest-$mode.log" 2>&1
  ASAN_OPTIONS=detect_leaks=1 "$build/cc_update_boundary_tests" renderer011/startup.cct > "$logs/update-boundary-$mode.log" 2>&1
  ASAN_OPTIONS=detect_leaks=1 "$build/cc_visibility_tests" > "$logs/visibility-$mode.log" 2>&1
  for variant in native soft; do
    [[ $variant == native ]] && testexe=cc_widget_tests || testexe=cc_widget_tests_soft
    ASAN_OPTIONS=detect_leaks=1 "$build/$testexe" renderer011/{startup,menu,book}.cct > "$logs/widget-$mode-$variant.log" 2>&1
  done
  ASAN_OPTIONS=detect_leaks=1 "$build/cc_fixture_tests" renderer011/{startup,menu,book}.cct > "$logs/fixture-$mode.log" 2>&1
done
for exe in cc_update_boundary_tests cc_visibility_tests cc_widget_tests cc_widget_tests_soft cc_fixture_tests; do
  cp -f "renderer013/build-release/$exe" "host-bin013/$exe"
done
if [[ -f "$NXDK_DIR/Makefile" ]]; then
  ./nxdk-update013/prepare_bin.sh > "$logs/native-prepare.log" 2>&1
  make -C nxdk-update013 NXDK_DIR="$NXDK_DIR" -j4 > "$logs/native-build.log" 2>&1
  printf 'BUILT\n' > "$logs/native-status.txt"
else
  printf 'SKIPPED: prepared nxdk tree not present at %s\n' "$NXDK_DIR" > "$logs/native-status.txt"
  if [[ "${CC_REQUIRE_TARGET:-0}" == 1 ]]; then cat "$logs/native-status.txt" >&2; exit 4; fi
fi
echo 'UPDATE013 HOST ACCEPTANCE PASSED. See native-status.txt for native target status.'
