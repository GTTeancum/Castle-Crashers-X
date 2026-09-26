# Castle Crashers Checkpoint 015

Start with `CHECKPOINT-015.md`. Reproduce host acceptance with:

```bash
./build_update015.sh
```

No downloads are performed. The script verifies exact generated-body provenance, the original mid-function manager slice, the sealed manager constant, static vtable provenance, capture-source integrity, and the generated-source seal before building Release and ASan/UBSan variants with Clang.

The key new result is that the bounded active `sub_8209DE50` update no longer relies on a hand-built update-manager tree. Exact translated original code allocates the manager, constructs its ordered map, inserts the root context and active widget context, and unwinds normally. The real startup fixture remains fail-closed at uncaptured live global `0x8225E62C`.

Checkpoint 011 remains the latest accepted native nxdk/xemu execution.
