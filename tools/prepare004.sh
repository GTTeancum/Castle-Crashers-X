#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
base=$(realpath ..)
python3 - "$base" <<'PY'
import zipfile,sys
from pathlib import Path
b=Path(sys.argv[1]);z=zipfile.ZipFile(b/'buildkit/downloads/rexglue-sdk-0.10.0-linux-amd64.zip');z.extractall(b/'tools/rexglue')
PY
chmod +x ../tools/rexglue/linux-amd64/bin/rexglue
 tar -xJf ../buildkit/downloads/LLVM-20.1.8-Linux-X64.tar.xz -C ../tools/llvm
 tar -xJf ../buildkit/downloads/bison-3.8.2.tar.xz -C ../tools/build-src
 tar -xzf ../buildkit/downloads/flex-2.6.4.tar.gz -C ../tools/build-src
prefix="$base/tools/host"
(cd ../tools/build-src/bison-3.8.2 && ./configure --prefix="$prefix" && make -j4 && make install)
(cd ../tools/build-src/flex-2.6.4 && ./configure --prefix="$prefix" && make -j4 && make install)
echo 'PREPARE004 PASSED'
