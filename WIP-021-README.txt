Castle Crashers WIP 021 — UNSEALED focused Xbox-only continuation

Base: sealed Checkpoint 020 (SHA-256 d61b2ed0329abaed1a5dbe9661227e279f6864ee4af8508face7c07289e411eb)

This overlay is self-contained relative to Checkpoint 020: it carries the WIP 021 runtime006 compatibility support, renderer021 CMake driver, and the complete current runtime021 tree. It is not Checkpoint 021 acceptance. The diagnostic ReXGlue harness is recovery/verification tooling only; the project deliverable remains the Xbox XBE/ISO.

Focused state in this revision:
- Reproduced the prior CF858 handoff exactly before editing: unsupported@821368C0, 851 generated/helper executions, 19,157 guest-memory operations, and 3,978 assertions.
- Confirmed exact sub_820CF858 remains 5,859 bytes, SHA-256 ad4094e5aa8c81a8abb8b143c8e39a4c3278ccffc6853a78a9a2f658028c5a83.
- Confirmed exact sub_820CF9D0 remains 10,770 bytes, SHA-256 2a44d5bcbbedae513828fd3bfff38825c5fec561aa1dd558d637fef286fb6852.
- Confirmed exact sub_820CF728 remains SHA-256 8bb7efc53f4e5fdf60d6827b1166defdf7294b45fa1d4729c83976d8c6395718.
- Recovered exact sub_821368C0 byte-for-byte from sealed pc/generated/default/castle_crashers_recomp.11.cpp: 659 bytes, SHA-256 3f548f0368b98565f5d7a2d09f7f2fb8cd77f51d9744a904e4f9b7c14108f48d.
- On the observed loader state, 0x8200068C resolves to 0x02500004 and the service object at 0x02500004 is null. Exact sub_821368C0 therefore returns r3=0 without an indirect dispatch.
- Exact sub_820CF858 consequently skips sub_820CD258, completes normally, and exact sub_820C13B8 fully unwinds back into the live PlatformRenderer::Init frame.
- Added a provenance-checked diagnostic continuation slice of original sub_820A7990 from 0x820A7B34 through the first later indirect call at lr=0x820A7BC8. The executed instruction fragment is byte-for-byte from the sealed generated source; wrapper scaffolding is not claimed as an original function body.
- That original caller continuation executes the first suffix sub_820C2C98, exact sub_820C13B8, the second sub_820C2C98, then resolves renderer vtable slot +28 to 0x820A85E8.
- New exact boundary: indirect dispatch to sub_820A85E8 at 0x820A85E8, lr=0x820A7BC8, r1=0x0003ED30, r3=renderer=0x00501060, r6/ctr=0x820A85E8, r7=480, r8=640, r9=0x82042048.
- Focused optimized Release result: dispatch@820A85E8, 964 generated/helper executions, 21,113 guest-memory operations.
- Focused Release update_boundary passes 3,974 assertions.
- Complete Release CTest passes 6/6, including visibility, update provenance, vtable provenance, capture-source verification, and generated-seal verification.
- Local provenance is now 338 exact generated bodies plus the four inherited original diagnostic artifacts and the separately verified PlatformRenderer post-graphics continuation slice.
- Second exact suffix setter advances durable device+48 write pointer to 0x0201F73C; device+52=0x0202F37C, device+56=0x0202F2DC, device+14928=0x0201F380 remain bound. Post-restore device+14916=0x0202F40C and device+14932=0x54 are also acceptance-bound.
- Renderer durable presentation fields before the new vtable call are renderer+28720=640 and renderer+28724=480.
- All prior VdPersistDisplay, MmFreePhysicalMemory, second VdRetrainEDRAM, CF9D0, ring/resource/tile/HSIO invariants remain intact. Transient stack words reused by the later second setter are no longer treated as durable evidence.
- sub_820CD258 remains fail-closed and was not reached because sub_821368C0 returned zero on this observed path.
- XEMU was not re-run for this increment: the reusable runnable ISO is still the older retained Widget011 diagnostic artifact, not a fresh nxdk/Xbox build containing WIP 021.
- Sanitizer re-validation and the full inherited renderer/widget/fixture sealing matrix remain pending. Checkpoint 020 remains the latest sealed checkpoint.

Next focused action: recover exact sub_820A85E8 from the sealed ReXGlue corpus and execute only its observed path from the live PlatformRenderer frame/vtable call. Stop at the first next genuine boundary; do not broaden prior platform contracts. Prefer an actual XEMU run once a fresh nxdk XBE/ISO containing current WIP logic exists.
