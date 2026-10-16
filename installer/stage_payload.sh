#!/bin/bash
# SPDX-License-Identifier: MIT
# Stage the files the installer carries next to its exe
# (installer/CastleCrashersXInstaller/Payload, git-ignored). None of them is
# game data: the play build of the game, the port's PC texture tool and its
# C++ runtime, ffmpeg, the texture list and the game-file checksums.
#
# usage: installer/stage_payload.sh <play default.xbe> <texture tool exe> <ffmpeg.exe> <textures.txr>
set -euo pipefail
here=$(cd "$(dirname "$0")" && pwd)
repo=$(cd "$here/.." && pwd)
P="$here/CastleCrashersXInstaller/Payload"
xbe=$1; tool=$2; ffmpeg=$3; txr=$4
rm -rf "$P"; mkdir -p "$P/texbake" "$P/ffmpeg"
cp "$xbe" "$P/default.xbe"
cp "$tool" "$P/texbake/ccx-texbake.exe"
for d in msvcp140.dll vcruntime140.dll vcruntime140_1.dll; do cp "/c/Windows/System32/$d" "$P/texbake/"; done
cp "$ffmpeg" "$P/ffmpeg/ffmpeg.exe"
cp "$txr" "$P/textures.txr"
# Checksums of the package files the installer depends on: the code image
# source and every file the texture list points into.
python - "$txr" "$repo/game-data/extracted" > "$P/gamefiles.sha256" <<'EOF'
import hashlib, struct, sys
txr, root = sys.argv[1], sys.argv[2]
d = open(txr, 'rb').read()
assert d[:4] == b'TXR2'
n = struct.unpack_from('<I', d, 4)[0]
p, names = 8, ['default.xex']
for _ in range(n):
    k = struct.unpack_from('<H', d, p)[0]
    names.append(d[p + 2:p + 2 + k].decode())
    p += 2 + k
for name in names:
    print('%s  %s' % (hashlib.sha256(open(root + '/' + name, 'rb').read()).hexdigest(), name))
EOF
ls -la "$P" "$P/texbake" "$P/ffmpeg"
