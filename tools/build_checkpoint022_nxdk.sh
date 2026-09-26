#!/usr/bin/env bash
# Fresh nxdk build of the Checkpoint 022 native boundary XBE/ISO. Run via:
#   MSYSTEM=CLANG64 C:\msys64\usr\bin\bash -l <this script>
set -euo pipefail
export NXDK_DIR=/c/nxdk
# mingw64/bin supplies the libstdc++/libgcc runtime DLLs of the prebuilt
# cxbe.exe / extract-xiso.exe host tools.
export PATH="/c/nxdk/bin:/clang64/bin:/mingw64/bin:/usr/bin:$PATH"
cd /d/Programming/GitHub/Castle-Crashers-X/nxdk-checkpoint022
make CXBE=/c/nxdk/tools/cxbe/cxbe.exe \
     EXTRACT_XISO=/c/nxdk/tools/extract-xiso/build/extract-xiso.exe \
     "$@"
