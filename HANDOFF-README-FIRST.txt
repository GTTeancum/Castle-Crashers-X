Castle Crashers X — FULL SOURCE HANDOFF — WIP 021 @ sub_820A85E8

Purpose
-------
This is a source-focused, directly usable continuation snapshot for the Xbox 360 -> original Xbox Castle Crashers port. It reconstructs sealed Checkpoint 020 and applies the complete self-contained WIP 021 overlay through the renderer vtable boundary at 0x820A85E8.

Authoritative status
--------------------
Read CastleCrashers-PROJECT_STATUS.md first. The latest sealed checkpoint remains Checkpoint 020. WIP 021 is intentionally unsealed.

Current boundary
----------------
sub_820A85E8 @ 0x820A85E8
Observed dispatch state: lr=0x820A7BC8, r1=0x0003ED30, r3=renderer=0x00501060.
Focused measurement: 964 generated/helper executions, 21,113 guest-memory operations, 3,974 assertions.
Release CTest at source handoff creation: 6/6 passed in the prior verified WIP 021 build.

Resume
------
Use Clang, not GCC. The generated corpus intentionally depends on the project’s Clang behavior.
Recover exact sub_820A85E8 from pc/generated/default/castle_crashers_recomp.4.cpp, add it without semantic edits, execute only the observed branch, and stop at the first next genuine boundary.

Included
--------
- complete recovered project/source history from sealed Checkpoint 020
- pc/generated ReXGlue source corpus and reference image needed for provenance/recovery
- runtime revisions through runtime021, including all exact generated bodies currently accepted
- renderer revisions through renderer021
- build scripts, tests, provenance/seal validators, manifests/checkpoint/worklog documentation
- nxdk/Xbox source and .ccr/.cct game-data build inputs
- current WIP 021 85e8 acceptance/provenance logs
- authoritative PROJECT_STATUS

Intentionally excluded
----------------------
- Linux XEMU/AppImage, BIOS, MCPX, EEPROM and other emulator runtime material
- XEMU automation/capture directories and historical XEMU capture logs
- host build output binaries/object trees
- old diagnostic ISO/XBE/EXE outputs

The source evidence and current port state are preserved; these exclusions are reproducible/runtime baggage, not current source.
