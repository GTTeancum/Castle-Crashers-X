# Castle Crashers Checkpoint 016

Start with `CHECKPOINT-016.md`. Reproduce host acceptance with:

```bash
./build_update016.sh
```

No downloads are performed. The script verifies 68 exact local generated bodies, both diagnostic `sub_820701D0` slices, sealed constants/vtable provenance, capture-source integrity, and the generated-source seal before building Release and ASan/UBSan variants with Clang.

The key result is that the real original startup function now runs from its genuine entry through `0x82070694`. It constructs the update manager, the 10,500-subobject state pool, and the region/system state using translated original code. The next unsupported startup boundary is real thread creation/platform scheduling at `sub_820B5D60`; Checkpoint 016 stops there rather than faking thread success.

The old real Checkpoint 011 capture remains fail-closed at uncaptured live global `0x8225E62C`, and Checkpoint 011 remains the latest accepted native nxdk/xemu execution.
