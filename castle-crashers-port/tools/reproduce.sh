#!/usr/bin/env bash
# Requires Python >=3.10, cryptography, libarchive, CMake, Ninja, Clang++.
set -euo pipefail
if [[ $# != 1 ]]; then echo 'Usage: tools/reproduce.sh /path/to/"Castle Crashers"' >&2; exit 2; fi
root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
input="$(realpath "$1")"
cd "$root"
mkdir -p reports logs extracted reference
python3 tools/extract_stfs.py "$input" --output extracted --manifest reports/container_manifest.json | tee logs/extraction.log
python3 tools/unpack_xex.py extracted/default.xex --output reference/default.image.bin --report reports/xex_unpack.json | tee logs/xex_unpack.log
python3 tools/analyze_xex.py extracted/default.xex reference/default.image.bin --reports reports | tee logs/binary-analysis.log
python3 tools/audit_assets.py extracted --report reports/asset_manifest.json | tee logs/asset-audit-python.log
cmake -S . -B build/host -G Ninja -DCMAKE_CXX_COMPILER=clang++ -DCC_SANITIZERS=ON -DCMAKE_BUILD_TYPE=Debug
cmake --build build/host
build/host/cc_asset_tests | tee logs/tests-host.log
build/host/cc_asset_probe extracted > reports/cpp_asset_probe.json
python3 tools/compare_audits.py
clang++ --target=i386-pc-win32 -march=pentium3 -ffreestanding -fno-exceptions -fno-rtti -std=c++20 -O2 -Wall -Wextra -Werror -c asset_core/asset_reader.cpp -o build/asset_reader.i386.obj
echo 'Asset probe and object compilation completed. No game build or xemu run was performed.'
