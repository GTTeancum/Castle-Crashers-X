# Castle Crashers Checkpoint 014

Start with `CHECKPOINT-014.md`. Reproduce host acceptance with:

```bash
./build_update014.sh
```

No downloads are performed. The script verifies generated-body provenance, static vtable provenance, capture-source integrity and the generated-source seal before building Release and ASan/UBSan variants.

The key new result is a normal-return bounded active `sub_8209DE50` update frame driven by exact generated original bodies and constructor/image-proven virtual targets. The real startup fixture remains fail-closed at uncaptured live global `0x8225E62C`.
