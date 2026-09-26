# Checkpoint 015 worklog

- Resumed from the sealed Checkpoint 014 host-update baseline without weakening fail-closed behavior.
- Located the concrete original writer of update-manager global `0x8225E62C` inside `sub_820701D0`.
- Isolated the exact translated instruction slice `0x82070434..0x820704C4` as a diagnostic mid-function entry; did not mislabel it as an original function boundary.
- Imported the exact original allocator and ordered-map closure needed by that slice: `sub_820B5EB8`, `sub_8209BDD8`, `sub_8209BF18`, `sub_82097650`, `sub_82097720`, `sub_82097AC8`, `sub_820986F0`, `sub_82099680`, `sub_82099968`, `sub_82099A80`, `sub_820744C8`, `sub_82075098`, and the required save/restore helpers.
- Added a bounded deterministic allocator fixture so original code allocates and constructs the 140-byte manager instead of tests hand-authoring its tree.
- Bound the manager float initializer at `0x820146A0` to the sealed mapped image value `0x3F666666` (`0.9f`).
- Verified original manager construction produces global `0x71010`, sentinel `0x710B0`, root `0x71140`, root-context value `0x71150`, and nested sentinel `0x71170` in the deterministic fixture.
- Drove a second exact map insertion with key `0x40000`; it completes with 42 generated function executions and 494 memory operations.
- Reworked the full synthetic `sub_8209DE50` test to consume the manager created by original code. The path now completes with 58 generated function executions and three original virtual dispatches, then restores the key-0 root context on unwind.
- Increased update-boundary coverage from 119 to 167 assertions.
- Preserved the real Checkpoint 011 capture unchanged and fail-closed at missing `0x8225E62C`; synthetic manager state is never substituted into it.
- Fixed the Checkpoint 015 build to select Clang explicitly because the generated scalar runtime uses Clang rotate builtins and does not compile unmodified under GCC.
- Release and ASan/UBSan both pass all 6/6 CTest targets plus renderer, visibility, widget, and fixture regressions.
- Checkpoint 011 remains the latest native nxdk/xemu acceptance; 015 is host diagnostic scope.
