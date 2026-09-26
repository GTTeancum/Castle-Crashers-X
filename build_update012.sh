#!/usr/bin/env bash
# Checkpoint 012 host/update-boundary build. No downloads are attempted.
# A native XBE/XISO is built only when the exact prepared nxdk tree is present.
set -euo pipefail
cd "$(dirname "$0")"
source ./env.sh
if [[ -n "${CXX:-}" ]]; then
  CXX="$CXX"
elif [[ -x "$LLVM_ROOT/bin/clang++" ]]; then
  CXX="$LLVM_ROOT/bin/clang++"
elif command -v clang++ >/dev/null 2>&1; then
  CXX="$(command -v clang++)"
else
  echo "No clang++ found; generated PPC scalar runtime requires Clang builtins." >&2
  exit 3
fi
logs=logs/checkpoint012/build-final
mkdir -p "$logs" host-bin012

python runtime012/verify_provenance.py > "$logs/update-provenance.log"
python runtime012/verify_update_capture_source.py > "$logs/update-capture-source.log"
python runtime012/verify_generated_seal.py > "$logs/generated-seal.log"

for mode in asan release; do
  if [[ $mode == asan ]]; then cmode=Debug; sanitize=ON; else cmode=Release; sanitize=OFF; fi
  build="renderer012/build-$mode"
  cmake -S renderer012 -B "$build" -G Ninja \
    -DCMAKE_CXX_COMPILER="$CXX" -DCMAKE_BUILD_TYPE="$cmode" \
    -DCC_SANITIZERS="$sanitize" > "$logs/configure-$mode.log" 2>&1
  cmake --build "$build" -j4 > "$logs/compile-$mode.log" 2>&1
  ASAN_OPTIONS=detect_leaks=1 ctest --test-dir "$build" --output-on-failure > "$logs/ctest-$mode.log" 2>&1
  "$build/cc_update_boundary_tests" renderer011/startup.cct > "$logs/update-boundary-$mode.log" 2>&1
  "$build/cc_visibility_tests" > "$logs/visibility-$mode.log" 2>&1
  for variant in native soft; do
    if [[ $variant == native ]]; then testexe=cc_widget_tests; else testexe=cc_widget_tests_soft; fi
    "$build/$testexe" renderer011/{startup,menu,book}.cct > "$logs/widget-$mode-$variant.log" 2>&1
  done
  "$build/cc_fixture_tests" renderer011/{startup,menu,book}.cct > "$logs/fixture-$mode.log" 2>&1
done

for exe in cc_update_boundary_tests cc_visibility_tests cc_widget_tests cc_widget_tests_soft cc_fixture_tests; do
  cp -f "renderer012/build-release/$exe" "host-bin012/$exe"
done

# Native target build is intentionally conditional. Host acceptance must never be
# mislabeled as target acceptance when the prepared nxdk dependency is absent.
if [[ -f "$NXDK_DIR/Makefile" ]]; then
  ./nxdk-update012/prepare_bin.sh > "$logs/native-prepare.log" 2>&1
  make -C nxdk-update012 NXDK_DIR="$NXDK_DIR" -j4 > "$logs/native-build.log" 2>&1
  printf 'BUILT\n' > "$logs/native-status.txt"
else
  printf 'SKIPPED: prepared nxdk tree not present at %s\n' "$NXDK_DIR" > "$logs/native-status.txt"
  if [[ "${CC_REQUIRE_TARGET:-0}" == 1 ]]; then
    cat "$logs/native-status.txt" >&2
    exit 4
  fi
fi

echo 'UPDATE012 HOST ACCEPTANCE PASSED. See native-status.txt for native target status.'
