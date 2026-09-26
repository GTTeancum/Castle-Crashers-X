#!/usr/bin/env bash
# Prepared offline dependencies required; no downloads, no emulator invocation.
set -euo pipefail
cd "$(dirname "$0")"
source ./env.sh
CXX="${CXX:-$LLVM_ROOT/bin/clang++}"
logs=logs/checkpoint011/build-final
mkdir -p "$logs"
python tools/verify_widget011.py > "$logs/provenance.json"
for scene in startup menu book; do
 frame="$(cat "renderer011/captures/selected-$scene.txt")"
 python renderer011/compile_widget.py "renderer011/captures/$frame" "renderer011/$scene" > "$logs/convert-$scene.json"
done
for mode in asan release; do
 if [[ $mode == asan ]]; then cmode=Debug; sanitize=ON; else cmode=Release; sanitize=OFF; fi
 build="renderer011/build-$mode"
 cmake -S renderer011 -B "$build" -G Ninja -DCMAKE_CXX_COMPILER="$CXX" -DCMAKE_BUILD_TYPE="$cmode" -DCC_SANITIZERS="$sanitize" > "$logs/configure-$mode.log" 2>&1
 cmake --build "$build" -j4 > "$logs/compile-$mode.log" 2>&1
 ASAN_OPTIONS=detect_leaks=1 ctest --test-dir "$build" --output-on-failure > "$logs/ctest-$mode.log" 2>&1
 "$build/cc_visibility_tests" > "$logs/visibility-$mode.log" 2>&1
 for variant in native soft; do
  if [[ $variant == native ]]; then testexe=cc_widget_tests; preview=cc_scene_preview; else testexe=cc_widget_tests_soft; preview=cc_scene_preview_soft; fi
  "$build/$testexe" renderer011/{startup,menu,book}.cct > "$logs/widget-$mode-$variant.log" 2>&1
  for scene in startup menu book; do
   "$build/$preview" "renderer011/$scene" "$logs/preview-$mode-$variant-$scene" > "$logs/preview-$mode-$variant-$scene.log" 2>&1
  done
 done
 "$build/cc_fixture_tests" renderer011/{startup,menu,book}.cct > "$logs/fixture-$mode.log" 2>&1
done
for scene in startup menu book; do
 for phase in 0 1 2 3; do
  for mode in asan release; do for variant in native soft; do
   cmp "$logs/preview-asan-native-$scene/phase-$phase.ppm" "$logs/preview-$mode-$variant-$scene/phase-$phase.ppm"
  done; done
 done
done
for component in xbox-runtime port009; do
 b="$component/build-widget011"
 cmake -S "$component" -B "$b" -G Ninja -DCMAKE_CXX_COMPILER="$CXX" -DCMAKE_BUILD_TYPE=Debug -DCC_SANITIZERS=ON > "$logs/$component-configure.log" 2>&1
 cmake --build "$b" -j4 > "$logs/$component-build.log" 2>&1
 ctest --test-dir "$b" --output-on-failure > "$logs/$component-tests.log" 2>&1
done
python tools/test_widget011_backend.py > "$logs/backend-contract-tests.log" 2>&1
mkdir -p nxdk-widget011/bin
cp renderer011/{startup,menu,book}.{cct,ccr} nxdk-widget011/bin/
make -C nxdk-widget011 -j4 > "$logs/native-build.log" 2>&1
python tools/audit_widget011.py > "$logs/native-audit.json"
python renderer011/test_converter.py > "$logs/converter011-tests.log" 2>&1
python tools/xemu011/test_helpers.py > "$logs/telemetry-tests.log" 2>&1
python tools/verify_mode009.py > "$logs/mode-provenance.json"
echo 'WIDGET011 BUILD/COMPARISONS PASSED. Target boot acceptance is a separate command.'
