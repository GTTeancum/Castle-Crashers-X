# Worklog 012

- Restored the exact sealed Checkpoint 011 archive and verified its existing project state.
- Identified `sub_8209CC98` as the original visibility-gated child update walker and imported its generated body unchanged.
- Added bounded dispatch/preflight coverage and proved the captured startup vtable update slot is `0x8209DE50`.
- Imported unchanged `sub_8209DE50`, `__savegprlr_29`, `__restgprlr_29`, and the genuine no-op `sub_8208C5D8`.
- Kept `sub_82097720` and `sub_820915F0` as explicit diagnostic hard-failure boundaries; no success stubs were introduced.
- Added synthetic branch tests for owner-stack/timeline behavior and a real startup-fixture test. The real fixture now fails specifically at uncaptured manager global `0x8225E62C` after dispatching into `0x8209DE50`.
- Added a source-guarded one-shot PC update tracer beginning at real `sub_8209DE50`; generated game translation units remain sealed and unchanged.
- Added an Xbox `nxdk-update012` source target that runs the update-boundary self-test before the Checkpoint 011 render regression.
- Tried to restore pinned nxdk revision `58427c078b4ccb0121f359b6b6c536b3b2914976`; this scratch runtime cannot clone/download the archive, so no fresh target result is claimed.
- ASan/UBSan and Release host acceptance pass. Existing widget, visibility, fixture and software-FMA regressions remain passing.
