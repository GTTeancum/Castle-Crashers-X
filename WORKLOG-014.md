# Checkpoint 014 worklog

- Recovered and SHA-verified Checkpoint 013.
- Repaired the clean-package seal verifier so it selects the newest numbered `CHECKSUMS-NNN.sha256` instead of requiring a missing generic checksum filename.
- Re-established the complete Release baseline before modifications.
- Statically proved the controller vtable from `sub_82075410`: `0x8203E118`, slot `+0x0C -> 0x820772B0`.
- Statically proved the parser vtable from `sub_82094048`: `0x8203F510`, decimal slots `84 -> 0x82088A08` and `88 -> 0x8208A228`.
- Added image/constructor provenance checks for those virtual targets.
- Imported the exact original GameManager constructor `sub_820A1AC0` and initialize synthetic diagnostic GameManager state through that constructor rather than hand-authored fields.
- Imported exact parser virtual bodies `sub_82088A08`, `sub_8208A228` and exact cleanup `sub_8208AE78`.
- Kept non-exercised dependencies as fail-closed hard boundaries.
- Closed the bounded active update wrapper: `sub_8209DE50` now returns normally with `funcs=17`, `dispatches=3`, timeline `0x40011111`, and correct active-global cleanup.
- The real old capture continues to stop at missing live manager global `0x8225E62C`; synthetic state is never substituted into that fixture.
- Release and ASan/UBSan acceptance plus renderer, visibility, and fixture regressions all pass.
