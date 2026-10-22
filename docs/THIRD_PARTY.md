# Third-party software and credits

## The game

Castle Crashers is developed by The Behemoth; its Xbox 360 Live Arcade edition
is published by Microsoft Game Studios. This repository and its releases contain
no game assets: the installer converts the user's own Xbox LIVE package. The
recompiled code in `runtime021/generated` is translated from that game's
executable for this port only.

## Tools and libraries

| Component | Version | Use | Licence |
| --- | --- | --- | --- |
| ReXGlue SDK | 0.10.0 (`f5337cdc947ff6d4c4196737e2c807a48f2a1fc2`) | Xbox 360 static recompilation | `third-party-notices/rexglue-LICENSE` |
| nxdk | `58427c078b4ccb0121f359b6b6c536b3b2914976` | Original Xbox toolchain, pbkit GPU setup (adapted from its triangle/mesh samples) | `third-party-notices/nxdk-*.txt` |
| FFmpeg | static build from `tools/build_ffmpeg_xma.sh` | Installer audio conversion (XMA2 to Xbox ADPCM) | shipped as `Payload/ffmpeg/LICENSE.txt` |
| LLVM | 20.1.8 | Compiler for host tools | Apache-2.0 with LLVM exceptions |

Texture-format handling was checked against ReXGlue's
`include/rex/graphics/xenos.h` and `src/graphics/pipeline/texture/info_formats.cpp`.
