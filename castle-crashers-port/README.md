> This directory retains intake-stage tools and documentation. Its stage-specific
> status is not the overall port status. Read the root `CHECKPOINT.md` for checkpoint 003.

# Castle Crashers → original Xbox: intake 001

**Status: the supplied LIVE package has been extracted and audited. A new asset-probing component builds and passes host tests. Castle Crashers has NOT been recompiled, booted, or rendered.**

Target route: ReXGlue PC correctness reference, then a game-specific nxdk runtime/custom renderer, with xemu testing after the toolchain is available.

## This archive contains

- `tools/extract_stfs.py`: read-only single-hash-copy STFS extraction, block/hash-tree verification, safe output paths and file SHA-256 inventory.
- `tools/unpack_xex.py`: AES/normal-LZX XEX unpacking through a libarchive CAB adapter; produces the mapped **PowerPC** image, not a PC executable.
- `tools/analyze_xex.py`: header, PE section, import, selected diagnostic-string and .pdata candidate inventory.
- `tools/audit_assets.py`: independent Python ZIP/CRC and cooked-Flash structural scanner.
- `asset_core/`: tested C++20 stored-ZIP/CRC/COK6/tag reader, host CLI and malformed-input tests.
- `castle_crashers.toml`: minimum ReXGlue configuration. Syntax parsed locally; **not tested by ReXGlue**.
- `reports/` and `logs/`: observed results, not projected performance.
- `build/asset_reader.i386.obj`: actual freestanding Pentium III-targeted i386 COFF compilation of the asset core. It is an unlinked object, **not an XBE**, and is not an nxdk build.

The compact archive deliberately excludes the supplied game container, extracted assets, decoded executable image, firmware, complete external SDKs, and large host build products. Recreate the game-derived working files from your original container.

## Reproduce the completed work

Tested on Linux x86-64 with Clang 17.0.0, CMake, Ninja, Python, `cryptography`, and system `libarchive` with CAB/LZX support. The core needs no STL, exceptions, RTTI, or heap allocator; the **host CLI** does use STL and filesystem I/O. The CLI reads one entire PAK at a time and is not an optimized Xbox streaming implementation.

From the project root:

```bash
./tools/reproduce.sh '/path/to/Castle Crashers'
```

Individual host build/test:

```bash
cmake -S . -B build/host -G Ninja \
  -DCMAKE_CXX_COMPILER=clang++ -DCC_SANITIZERS=ON \
  -DCMAKE_BUILD_TYPE=Debug
cmake --build build/host
ctest --test-dir build/host --output-on-failure
build/host/cc_asset_probe extracted > reports/cpp_asset_probe.json
python3 tools/compare_audits.py
```

Python dependency: `cryptography`. `libarchive` is a native library, not a Python package. The STFS extractor, asset audit and binary analyzer otherwise use the Python standard library. The two optional audio probes used the installed FFmpeg/ffprobe tools; they are not required by the reproduction script.

## Observed validation

- 708 extracted files, 8 directories; input and every file SHA-256 recorded.
- All 35,571 STFS data-block hashes match. Populated hash tables validate to the descriptor. Microsoft RSA authenticity **not checked**.
- All 14 XEX compressed-block hashes match; 90 LZX frames unpack to 2,949,120 bytes and a mapped PE signature. XEX per-page security-descriptor hashes **not validated**.
- All 198 PAKs and 523 ZIP members are readable; all member CRCs match.
- All 122 COK6 Flash-6 payloads pass the structural tag walk, including sprite timelines.
- Independent Python and C++ results agree on every counted tag and record type.
- 157 assertions and 10,000 deterministic malformed-input probes pass with AddressSanitizer and UndefinedBehaviorSanitizer. This is a smoke test, not a proof of parser security or support for arbitrary packages.
- The C++ core compiles with `--target=i386-pc-win32 -march=pentium3 -ffreestanding -fno-exceptions -fno-rtti -std=c++20`. The inspected object has no undefined symbols. Linking, nxdk ABI integration, boot and GPU output are **untested**.
- Two XMA2 samples probe and decode without reported errors; one music sample was limited to one second and the shorter sound effect ended naturally. The other audio files were not decoded in this pass.

## Scope and limitations

The ZIP reader intentionally supports only the observed classic single-disk ZIP format with stored entries and flags zero. The COK6 reader handles the observed wrapper's big-endian payload length/offset and uncompressed Flash-6 header. It bounds-checks and counts tags but does **not** implement shapes, ActionScript, animation, masking, sound, text, texture decoding, or rendering. Tags 142 and 148 remain unidentified. Unknown tags are skipped, not silently treated as implemented.

Embedded SWF length fields and BREC payload lengths differ in 107 records (often padding, but not universally). Use the BREC payload bounds; do not assume that changing a filename to `.swf` produces an unmodified standard Flash movie. The COK6 length/offset interpretation must not be blindly applied to PDAG, GLYP or PIXL.

`.pdata` supplies 2,484 unique, ordered candidate addresses inside `.text`; it is not an exhaustive function inventory or ReXGlue analysis output. No speculative manual overrides are installed. Diagnostic strings give useful starting points but are not recovered debug symbols.

## ReXGlue and next build gate

The container was sufficient for extraction and native-code/asset inspection. Obtaining external build tools failed in this scratch session: direct repository downloads returned `curl: (6) Could not resolve host: github.com`. ReXGlue, nxdk and xemu were not installed or executed. A GitHub connector was suggested but has not been authorized/connected; that is not a completed toolchain installation.

When an appropriate ReXGlue CLI/SDK is available, the prepared command is:

```bash
# NOT executed in this delivery.
rexglue codegen castle_crashers.toml
```

Collect and resolve its actual analysis diagnostics before attempting the PC game link. Preserve exact tool revisions and submodule states. A prebuilt Linux x86-64 CLI plus its matching SDK/dependencies, or complete recursive source with all build prerequisites, is the useful next input. An nxdk checkout must likewise include required submodules/dependencies; an ordinary GitHub source ZIP can omit these.

For the Xbox phase, keep the existing parser/script semantics where feasible, locate native platform-rendering boundaries, and implement a renderer for the observed vector/mixed-bitmap content. First build/boot a known nxdk sample to qualify the environment. Only then treat failures as game-port issues. No game-specific renderer, graphics output, XBE, xemu boot, gameplay result, or original-hardware performance is claimed here.

See `reports/INTAKE_REPORT.md` for the measured summary and `SOURCES.md` for format references. Tools are under the accompanying MIT license; this does not license Castle Crashers, third-party tools, firmware, trademarks, or game content.
