#!/bin/bash
# SPDX-License-Identifier: MIT
# Build the installer's small ffmpeg (XMA1/XMA2 decoders, WAV demuxer, PCM
# output, resampler; ~1.7 MB, static) from the official 8.1.1 source, the
# same version as the full build its output was compared with (differences
# of at most 1 LSB on ~0.04% of samples: no SIMD paths).
# Source: https://ffmpeg.org/releases/ffmpeg-8.1.1.tar.xz (downloaded into
# installer/third_party/ffmpeg/build, git-ignored). Needs MSYS2 CLANG64.
# Output: installer/third_party/ffmpeg/ffmpeg.exe (+ LICENSE.txt).
set -euo pipefail
here=$(cd "$(dirname "$0")/.." && pwd)
D="$here/installer/third_party/ffmpeg"
B="$D/build"
mkdir -p "$B"
cd "$B"
[ -f ffmpeg-8.1.1.tar.xz ] || curl -sSfL -o ffmpeg-8.1.1.tar.xz https://ffmpeg.org/releases/ffmpeg-8.1.1.tar.xz
[ -d ffmpeg-8.1.1 ] || tar -xJf ffmpeg-8.1.1.tar.xz
MSYSTEM=CLANG64 /c/msys64/usr/bin/bash -l -c "cd '$B/ffmpeg-8.1.1' && ./configure --cc=clang --cxx=clang++ \
  --target-os=mingw32 --arch=x86_64 --disable-everything --disable-autodetect --disable-x86asm \
  --disable-network --disable-doc --disable-ffplay --disable-ffprobe --disable-avdevice --disable-swscale \
  --enable-swresample --enable-decoder=xma1,xma2 --enable-demuxer=wav,xwma --enable-muxer=pcm_s16le \
  --enable-encoder=pcm_s16le --enable-protocol=file,pipe --enable-filter=aresample,aformat,anull,abuffer,abuffersink \
  --extra-ldflags=-static --pkg-config-flags=--static > ../configure.log 2>&1 && make -j\$(nproc) ffmpeg.exe > ../make.log 2>&1"
cp "$B/ffmpeg-8.1.1/ffmpeg.exe" "$D/ffmpeg.exe"
cp "$B/ffmpeg-8.1.1/COPYING.LGPLv2.1" "$D/LICENSE.txt"
ls -la "$D/ffmpeg.exe"
