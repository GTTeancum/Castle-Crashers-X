# Checkpoint 011 work log

## Starting state
- Continued from the actual uploaded Checkpoint 010 archive (SHA-256 `99b052c48cf27827727df301d3d5f349588eeac3637817a39a750ea6f3c1712a`).
- Complete BuildKit restored and all source snapshots checked by the supplied helper.
- Existing build/screenshot claims remain historical until retested.

## Current investigation
- Original `sub_8209DF48` calls owner `sub_82091248`, maintains owner-stack/global state, then invokes child-list traversal `sub_8209CD08`.
- `sub_8209CD08` dispatches visibility and rendering through child vtables; actual targets still need capture.
- Goal: execute these original paths through the native renderer, retain coherent captured root state, and verify exact results and failure handling on host and xemu.
- No claim of live game update/input or original resource creation.

## Host and native bridge validation

Added original `8209CD08`, `8209DF48`, `8209CE40`, and `8209CE48` bodies without modifying generated code. Captured three actual PC frames (animated-title snapshot 724, book 1697, menu 3040). Host comparisons cover 239 root cases, 418 quads, 125 recursive visits and 42,499 non-stack store bytes. The whole first widget container is retained; diagnostic visibility changes call the original setter/getter. Other menu/book text roots still restore snapshots. No live update/gameplay loop.

Initial target run passed geometry, original visibility changes, 15 control cases per scene and memory recovery, but FAILED visual acceptance. A read-only target-memory diagnostic confirmed that all staged book textures, vertices and commands matched the host. Inspection then identified an implementation mistake in checkpoint cloning: broad string replacement of `010` with `011` had changed two hex literals in the copied native backend (blend selector and colour write mask). Restored the backend byte-for-byte from 010 and added six dedicated regression methods that reject this mutation. The incorrect source, initial telemetry, memory readback and failed visual comparison are retained. They are not a successful renderer acceptance.

The new provenance checker initially misclassified the next caller instruction as a direct branch. Actual word `4e800421` and generated code show `bctrl`; the checker now pins the indirect call site and the observed container virtual slot. This was a checker error, not a change to original game instructions.

The fixed native executable is being tested separately. Exact target and visual acceptance records, not an exit code or prior screenshot, determine delivery status. No new source/tool/firmware uploads are needed.

## Final acceptance

The fixed ISO passed all nine phases and all six visual states. Final xemu run: 45.338 seconds, 180 diagnostic frames, 21,440 exact quad comparisons, six original visibility changes and three resident restores. Both completed scene unloads recovered the exact starting page count. The source/native combined rebuild passed and retained the accepted hashes. Game/emulator/display processes are stopped. This is captured-state rendering, not live gameplay.

## Delivery-source validation

The first curated copy omitted the reference-preview directory because its name resembled a build cache. The relocated visual checker correctly refused the missing input. The copy filter now preserves evidence under `logs/checkpoint011/build-final`, and relocated full acceptance passes. This was packaging, not a game-code/target failure. A fresh relocated sanitizer host build is also being verified before the final archive.
