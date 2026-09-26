# Checkpoint 016 worklog

- Resumed from Checkpoint 015's exact manager/update closure.
- Proved `sub_820701D0` is on the genuine startup chain and replaced the isolated manager-only view with an original function-entry prefix.
- Added exact startup helper bodies needed before and after manager publication, preserving hard failures for unobserved branches.
- Added a narrowly validated `%i` formatting shim and single-threaded 28-byte critical-section initializer for the startup proof.
- Executed the real prefix through manager publication and then closed exact `sub_8208CFA0`, including 10,500 original 248-byte subobject initializations and 10,501 indirect virtual dispatches.
- Bound the state-pool virtual slot in the sealed image to exact `sub_820867B8`.
- Increased finite diagnostic limits only where measured original behavior exceeded the previous caps: 250,000 functions, 20,000 dispatches, and a maximum 20,000,000 memory-operation budget. The acceptance test uses a 12,000,000 operation budget.
- Extended the deterministic allocator fixture to 16 MiB so the original bulk allocations fit without replacing them with host containers.
- Published the state-pool object at original global `0x8225E608` and verified its original top-level layout/pointer table.
- Closed exact `sub_8209F7E8` system/region construction and its exact helper graph.
- Added narrow platform fixtures for the observed Xbox config query, `XGetGameRegion` (`0x101`), and `XNotifyPositionUI`; unknown shapes remain unsupported.
- Extended the original startup prefix through label `0x82070694`, publishing system state at `0x8225E63C`.
- Increased update/startup boundary coverage from 167 to 407 assertions.
- Reworked provenance verification to validate every exact local `runtime016/generated` body actually included: 68 exact bodies, plus the manager slice and startup-prefix slice.
- Preserved the Checkpoint 011 real capture unchanged and fail-closed at `memory@0x8225E62C`.
- Identified the next unsupported real startup boundary as thread creation/platform scheduling beginning at `sub_820B5D60`; did not stub those operations to fake further progress.
- Release and ASan/UBSan both pass all 6/6 CTest targets plus renderer, visibility, widget, and fixture regressions.
- Checkpoint 011 remains the latest native nxdk/xemu acceptance; 016 is host diagnostic scope.
