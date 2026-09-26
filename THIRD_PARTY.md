# Third-party source and data

The native GPU initialization, vertex-attribute binding and shader-loading
sequence are adapted from the supplied nxdk triangle/mesh examples and pbkit API
at commit `58427c078b4ccb0121f359b6b6c536b3b2914976`. The relevant copyright notices
remain in those upstream sources; nxdk's distributed license texts are preserved
under `third-party-notices/`. The sample fragment/vertex interfaces were reduced
to texture/diffuse modulation and explicit screen-space coordinates for this
frozen replay. The backend was first executed in xemu in Checkpoint 005 and is exercised by the current Checkpoint 010 diagnostic; physical Xbox hardware remains untested.

ReXGlue 0.10.0 source commit:
`f5337cdc947ff6d4c4196737e2c807a48f2a1fc2`.
Original upstream sources are part of the user's existing offline BuildKit,
not replaced by a newly fetched main branch. The PC reference still uses the
provided runtime and its Xenos/Vulkan plugin; the independent replay renderer
does not link that plugin or the ReXGlue runtime.

Texture-format interpretation was checked against the actual game's generated
SetTexturing routine and pinned ReXGlue `include/rex/graphics/xenos.h` and
`src/graphics/pipeline/texture/info_formats.cpp`: format 15 is 16-bit 4:4:4:4,
not 8-bit alpha. The game-specific ARGB channel ordering is retained during
normalization and checked with byte-exact conversion fixtures.

The game-specific recompiled functions and captured artwork originate from the
user-supplied Castle Crashers container. This checkpoint does not convey rights
to distribute those assets or the game publicly. No Xbox firmware or account
credentials are included.
