# Castle Crashers Checkpoint 017

Start with `CHECKPOINT-017.md`. Reproduce host acceptance with:

```bash
./build_update017.sh
```

No downloads are performed. The script verifies 80 exact local generated bodies, four original diagnostic artifacts, sealed constants/table provenance, capture-source integrity, and the generated-source seal before building optimized Release and ASan/UBSan variants with Clang.

Checkpoint 017 closes the complete original `sub_820701D0` startup initializer, records the exact five-worker create/priority/affinity/resume lifecycle without running the infinite worker loop, verifies all 613 final lookup entries, returns to `sub_82070AC8`, constructs the 30,216-byte renderer object, publishes it at `0x8225E628`, and executes the original `PlatformRenderer::Init` prefix through its video-mode/presentation setup.

The next honest host boundary is `sub_820BEFD0`, the first graphics-device helper. No Direct3D-device success is fabricated. The old Checkpoint 011 real capture remains fail-closed at uncaptured global `0x8225E62C`, and Checkpoint 011 remains the latest accepted native nxdk/xemu execution.
