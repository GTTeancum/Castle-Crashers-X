#!/usr/bin/env bash
export CC_WORK="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
export CC_BASE="$(cd "$CC_WORK/.." && pwd)"
export LLVM_ROOT="${LLVM_ROOT:-$CC_BASE/tools/llvm/LLVM-20.1.8-Linux-X64}"
export REXSDK_ROOT="${REXSDK_ROOT:-$CC_BASE/tools/rexglue/linux-amd64}"
export NXDK_DIR="${NXDK_DIR:-$CC_BASE/buildkit/sources/nxdk}"
export PATH="$CC_BASE/tools/host/bin:$LLVM_ROOT/bin:$NXDK_DIR/bin:$REXSDK_ROOT/bin:$PATH"
export LD_LIBRARY_PATH="$REXSDK_ROOT/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
