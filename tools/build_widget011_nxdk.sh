#!/usr/bin/env bash
# Fresh nxdk build of the Widget011 diagnostic XBE/ISO on this machine's
# local toolchain (C:\nxdk + MSYS2 CLANG64). Run via:
#   MSYSTEM=CLANG64 C:\msys64\usr\bin\bash -l <this script>
set -euo pipefail
export NXDK_DIR=/c/nxdk
# mingw64/bin supplies the libstdc++/libgcc runtime DLLs of the prebuilt
# cxbe.exe / extract-xiso.exe host tools.
export PATH="/c/nxdk/bin:/clang64/bin:/mingw64/bin:/usr/bin:$PATH"
cd /d/Programming/GitHub/Castle-Crashers-X/nxdk-widget011
# The local Windows nxdk checkout carries prebuilt .exe tools; command-line
# variable assignments override the unix-named paths in nxdk's Makefile.
make CXBE=/c/nxdk/tools/cxbe/cxbe.exe \
     EXTRACT_XISO=/c/nxdk/tools/extract-xiso/build/extract-xiso.exe \
     "$@"
