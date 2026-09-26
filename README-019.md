# Castle Crashers Checkpoint 019

Start with `CHECKPOINT-019.md`. Reproduce host acceptance with:

```bash
./build_update019.sh
```

Checkpoint 019 closes the observed original `sub_820CBBF0` presentation/resource chain and stops fail-closed at `sub_820CB988`. Three resource-like pointers are constructed and published by original code, including a 1,228,800-byte framebuffer-sized backing allocation and two sequential 240-tile surface allocations. `renderer+4` is still unpublished, so no completed graphics-device claim is made.

The build verifies 143 exact local generated bodies plus inherited provenance artifacts, then runs Release and ASan/UBSan acceptance and inherited renderer/visibility/fixture regressions.

Checkpoint 011 remains the latest actual nxdk/xemu execution. A new xemu regression is due at this milestone, but the private boot stack and external nxdk toolchain are intentionally absent from the sealed checkpoint and were unavailable in the current environment.
