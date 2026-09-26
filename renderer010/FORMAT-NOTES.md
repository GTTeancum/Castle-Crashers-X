# Captured owner fixture contract (Checkpoint 010)

These files retain the `CCST008` layout. They describe captured state, not original game assets or a save format. The raw PC captures remain the source of truth.

Each 48-byte case header is followed by two 544-byte scalar contexts, sorted region descriptors, before/after/write-mask bytes and expected 176-byte draw records. The latter contain the original 96 emitted vertex bytes, not fallback geometry. The map capacity is now 64 regions and the workspace capacity remains 256 KiB per owner/scratch instance.

Header flags at case offset 40: bit zero means **output counter not observed**. It is accepted only for an owner entry `0x82091248` with no emitted draws and no numeric counter assertion. Serialized zero placeholders do not claim the original counter was zero: the JSON reports `counter_observed: false` and null before/after values. Two actual empty-owner cases never read the global counter, and its page is absent. Tests verify that the page stays unmapped; it is not filled with fabricated memory. Unknown flags are rejected.

The converter may combine ranges across gaps only inside contiguous pages that were actually captured. It refuses to bridge an absent page, even to meet the region count. The book owner's input spans more than 32 discontiguous blocks; the 64-region change retains those real boundaries. Arbitrarily mutated fixture memory is parsed/restored for robustness tests but never executed as generated game code.

`renderer010/live_frame.cpp` retains the first original owner once per scene. It resets entry registers and the caller output cursor each frame, not the owner objects. Detach/reattach edits only the captured owner's child-list pointer. Startup has one root; menu/book retain separate root snapshots for their font/empty-owner calls. None of this executes an original timeline, game update loop or controller-driven state machine.
