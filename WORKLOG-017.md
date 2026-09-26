# Checkpoint 017 worklog

- Resumed from Checkpoint 016 at Xbox worker creation `sub_820B5D60`.
- Extracted and provenance-verified the exact thread wrapper closure.
- Added a bounded scheduler record for the only observed five-worker lifecycle: suspended create, priority -1, affinities 2/4/8/16/32, then resume.
- Preserved the exact startup thunk (`0x820B79B8`), worker routine (`0x820B0E80`), parameters 0..4, and sealed thread-object type token (`0x0001001B`).
- Deliberately did not execute the infinite worker loop or generalize the scheduler beyond observed call shapes.
- Replaced the Checkpoint 016 mid-function startup stop with the complete original `sub_820701D0` body through its epilogue.
- Verified five published worker handles and the final `sub_8209D688` lookup state, including all 613 table entries.
- Extended boundary assertions from 407 to 1,036 at full-startup closure, then to 1,078 after renderer-entry coverage.
- Returned into original caller `sub_82070AC8` and closed its observed initialization path through renderer publication.
- Added exact `__savegprlr_18`, `__restgprlr_18`, `sub_8209A728`, `sub_8209B458`, and `sub_820A7668`; unobserved branches referenced by `sub_8209A728` remain hard boundaries.
- Verified the original 30,216-byte renderer object is published at `0x8225E628`; deterministic fixture address is `0x00501060`.
- Added a provenance-checked `sub_820A7990` prefix and narrowly validated `XGetVideoMode` fixture for 640×480/60 Hz.
- Executed original PlatformRenderer initialization through presentation-parameter construction and stopped immediately before `sub_820BEFD0`.
- Bound the original 58.0f refresh threshold at `0x82042678` to the sealed mapped image.
- Provenance now covers 80 exact local generated bodies plus manager, complete-startup, renderer-caller, and PlatformRenderer diagnostic artifacts.
- Release and ASan/UBSan both pass all 6/6 CTest targets; renderer, visibility, and fixture totals remain unchanged.
- Preserved the Checkpoint 011 real capture unchanged and fail-closed at `memory@0x8225E62C`.
- Checkpoint 011 remains the latest native nxdk/xemu acceptance; 017 remains host convergence scope.
