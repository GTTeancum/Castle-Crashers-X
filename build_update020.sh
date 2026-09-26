#!/usr/bin/env bash
# Checkpoint 020 host startup/PlatformRenderer convergence build. No downloads are attempted.
set -euo pipefail
cd "$(dirname "$0")"
source ./env.sh
if [[ -n "${CXX:-}" ]]; then CXX="$CXX";
elif [[ -x "$LLVM_ROOT/bin/clang++" ]]; then CXX="$LLVM_ROOT/bin/clang++";
elif command -v clang++ >/dev/null 2>&1; then CXX="$(command -v clang++)";
else echo "No clang++ found; generated PPC scalar runtime requires Clang builtins." >&2; exit 3; fi
logs=logs/checkpoint020/build-final
mkdir -p "$logs" host-bin020
python runtime020/verify_provenance.py > "$logs/update-provenance.log"
python runtime020/verify_vtable_provenance.py > "$logs/vtable-provenance.log"
python runtime020/verify_update_capture_source.py > "$logs/update-capture-source.log"
python runtime020/verify_generated_seal.py > "$logs/generated-seal.log"
for mode in asan release; do
  if [[ $mode == asan ]]; then cmode=Debug; sanitize=ON; else cmode=Release; sanitize=OFF; fi
  build="renderer020/build-$mode"
  rm -rf "$build"
  cmake -S renderer020 -B "$build" -G Ninja -DCMAKE_CXX_COMPILER="$CXX" -DCMAKE_BUILD_TYPE="$cmode" -DCC_SANITIZERS="$sanitize" > "$logs/configure-$mode.log" 2>&1
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
  cp -f "renderer020/build-release/$exe" "host-bin020/$exe"
done
cat > "$logs/native-status.txt" <<'TXT'
Checkpoint 020 has a new native/xemu regression in addition to host convergence. The retained Checkpoint 011 original-Xbox diagnostic ISO was re-executed under the newly supplied Complex 4627 BIOS and byte-identical MCPX using xemu lineage 0.8.136-15-gc231997, with 64 MiB and a sparse FATX HDD in snapshot mode. The 180-frame diagnostic completed and telemetry validation passed. This is a native/original-Xbox diagnostic regression, not live Castle Crashers gameplay and not proof of Xbox 360 Xenos Vd* equivalence. A fresh nxdk XBE rebuild was not performed in this scratch environment because the external nxdk SDK/buildkit tree was absent; the retained built Checkpoint 011 ISO was used. Private firmware/HDD bytes are excluded from the checkpoint; hashes/evidence only are retained.
TXT
if [[ "${CC_REQUIRE_FRESH_NXDK_BUILD:-0}" == 1 ]]; then cat "$logs/native-status.txt" >&2; exit 4; fi
echo 'UPDATE020 ACCEPTANCE PASSED: exact graphics initialization now completes sub_820BEFD0 and original code publishes renderer+4; new native/xemu diagnostic regression is also recorded.'
