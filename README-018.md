# Castle Crashers Checkpoint 018

Start with `CHECKPOINT-018.md`. Reproduce host acceptance with:

```bash
./build_update018.sh
```

No downloads are performed. The script verifies 99 exact local generated bodies, four inherited original diagnostic artifacts, sealed constants/tables/import-token provenance, capture-source integrity, and the generated-source seal before building Release and ASan/UBSan variants with Clang.

Checkpoint 018 continues exact original graphics initialization from `sub_820BEFD0` through lower-object allocation, Xbox engine setup, the default 32 KiB / 2 MiB command-ring configuration, command/state allocation, two bounded graphics-worker creations, `sub_820BF930`, and `sub_820D7920`.

The next honest host boundary is `sub_820CBBF0`. The outer renderer's device pointer remains unpublished, so no completed Direct3D/Xenos device, render target, backbuffer, native gameplay, or new xemu acceptance is claimed. Checkpoint 011 remains the latest accepted nxdk/xemu execution.
