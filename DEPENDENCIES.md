# Pinned dependencies and tested Linux layout

`manifest.json` and `upload-index.json` are the user's verified BuildKit records.
All 13 volume hashes, assembled payload and 36 source snapshots were verified
again for checkpoint 003. No full game or tool-kit re-upload is needed.

The default directory layout used by `env.sh` is:

```text
work/
  project/          # this checkpoint, any basename is acceptable
  buildkit/         # restored 36 source snapshots and downloaded distributions
  tools/
    rexglue/linux-amd64/
    llvm/LLVM-20.1.8-Linux-X64/
    host/           # locally built Bison/flex
```

From the checkpoint root, in a new workspace:

```sh
python3 restore_buildkit.py /path/to/all-13-buildkit-zips --output ../buildkit --checkout
mkdir -p ../tools/rexglue ../tools/llvm ../tools/host ../tools/build-src
unzip ../buildkit/downloads/rexglue-sdk-0.10.0-linux-amd64.zip -d ../tools/rexglue
tar -xJf ../buildkit/downloads/LLVM-20.1.8-Linux-X64.tar.xz -C ../tools/llvm
chmod +x ../tools/rexglue/linux-amd64/bin/rexglue
source env.sh
```

The actual revisions are ReXGlue 0.10.0/source
`f5337cdc947ff6d4c4196737e2c807a48f2a1fc2`, nxdk
`58427c078b4ccb0121f359b6b6c536b3b2914976`, and LLVM 20.1.8. `LLVM_ROOT`,
`REXSDK_ROOT` and `NXDK_DIR` can be set before sourcing `env.sh` for another layout.

Bison 3.8.2 and flex 2.6.4 were built locally from the kit's source archives in
this fresh session. They are placed ahead of system tools on PATH by `env.sh`.
Typical offline preparation, requiring an existing native C/C++ toolchain:

```sh
tar -xJf ../buildkit/downloads/bison-3.8.2.tar.xz -C ../tools/build-src
tar -xzf ../buildkit/downloads/flex-2.6.4.tar.gz -C ../tools/build-src
prefix="$(cd ../tools/host && pwd)"
(cd ../tools/build-src/bison-3.8.2 && ./configure --prefix="$prefix" && make -j2 && make install)
(cd ../tools/build-src/flex-2.6.4 && ./configure --prefix="$prefix" && make -j2 && make install)
```

Linux system development libraries, GNU make, CMake, Ninja, Python, Git, and
other OS facilities remain external dependencies. This is not a self-contained
OS image or a certification that every nxdk target builds offline. The build
logs record the targets and compiler configurations actually exercised.

The PC test used the existing Chromium SwiftShader Vulkan ICD, SDL/X11 on Xvfb,
and a private ALSA null sink. Screen capture/input additionally use Pillow,
`libX11`, `libXtst`, and `xwininfo`; video capture used FFmpeg. These are explicit
properties of scratch, not automatically installed components of this ZIP.
The Linux binaries are not Windows executables.

The kit includes xemu 0.8.136, but no BIOS, MCPX or test HDD. The previous frontend
launch is historical evidence only. Checkpoint 003 did not attempt another
firmware-less boot and makes no new xemu execution claim.
