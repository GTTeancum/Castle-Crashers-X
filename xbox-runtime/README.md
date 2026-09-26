> Checkpoint 010 update: the shared address map now supports 64 regions. Its metadata is 1,028 bytes on nxdk/i386 and 1,544 bytes on the tested 64-bit host. The 32-region measurements below describe the original Checkpoint 003 version. Backing memory is additional.

# Original-Xbox guest-memory prototype — checkpoint 003

This is a small runtime component, **not a replacement ReXGlue runtime and not a
running Xbox version of Castle Crashers**. It is not currently installed in the
PC executable's normal memory path.

## Implemented contract

`AddressSpace` maps at most 32 non-overlapping, sorted 32-bit guest ranges to
caller-owned host buffers. Separate guest ranges can intentionally alias the
same host buffer. Transfers support adjacent guest ranges even when their host
buffers are not contiguous. Endian helpers accept 1, 2, 4 or 8 bytes. A whole
request is checked before copying, so permission/unmapped/wrap failures do not
partly change a destination. `contiguous` rejects a request crossing regions.

The metadata requires 776 bytes on the tested Linux x86-64 host and **516 bytes
under nxdk's 32-bit ABI**, enforced by compile-time assertions in the Xbox probe.
Backing storage is additional. This says nothing about game memory residency.

Buffers passed to read/write must not overlap mapped host spans (the same
restriction as `memcpy`). Mapping setup must finish before concurrent access;
backing storage lifetime and synchronization belong to the caller. This component
does not implement an allocator, page faults, MMIO, a kernel, function dispatch,
a complete PowerPC context, SIMD adaptation or a renderer. An explicit region
lookup per access has not been benchmarked on Xbox and is not an established
final fast path.

## One original generated function, not a replacement implementation

`leaf_820b20c8.generated.inc` is the exact `sub_820B20C8` body from the checked-in
PC-generated sources. Its source is the user's original **40-byte / 10-instruction**
PowerPC function at `0x820B20C8`. The wrapper supplies only the registers this leaf
uses and replaces its memory macros with the bounded bridge. It saves `r4` on the
guest stack, reads four bytes and returns a byte-reordered word. We are not
claiming that this small routine establishes a complete graphics boundary.

`verify_leaf.py` checks both the generated body and the corresponding original
PowerPC bytes against recorded SHA-256 hashes. It requires the original image
from the intake reproduction. The host self-test compares 4,096 deterministic
inputs to an independent bit-reordering expression and checks the saved stack
value. The same self-test is linked into the nxdk diagnostic, **but has not been
executed there**. The adapter has explicit error returns for the tested stack
preflight failures; it does not pretend an unmapped access succeeded.

## Actual tests

The debug host build passed AddressSanitizer and UndefinedBehaviorSanitizer with
40,072 assertions, 10,000 deterministic memory-model trials, and 4,096 original
leaf inputs. A separate optimized Release build passed the same tests. The six
existing PC switch-repair tests also still pass.

```sh
# From the checkpoint root after restoring dependencies and extracting the game:
bash build_runtime003.sh
# Independent byte-level provenance check:
python3 xbox-runtime/verify_leaf.py
```

The CMake sanitizer option is `CC_SANITIZERS` (default ON). The target build uses
nxdk and keeps `-Werror` on our source objects rather than applying it to every
upstream nxdk translation unit. The target object files are Intel i386 COFF.

The bridge/adapter/test code has SPDX MIT notices; the included generated game
body retains its separate, user-game-derived provenance. Do not describe the
original game function as independently authored MIT code.
