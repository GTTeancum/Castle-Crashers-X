XBE_TITLE = CastleCrashersX Checkpoint 022
GEN_XISO = CastleCrashersX-Checkpoint022.iso
SRCS = \
  $(CURDIR)/xbox_shims.cpp \
  $(CURDIR)/xbox_audio.cpp \
  $(CURDIR)/xbox_render.cpp \
  $(CURDIR)/xbox_input.cpp \
  $(CURDIR)/xbox_perf.cpp \
  $(CURDIR)/../runtime007/numeric/fused.cpp \
  $(CURDIR)/../runtime007/numeric/target_fma.cpp \
  $(CURDIR)/../runtime021/update_boundary_tests.cpp \
  $(CURDIR)/../runtime021/bridge.cpp \
  $(CURDIR)/../runtime021/guest_window.cpp \
  $(CURDIR)/../runtime021/selftest.cpp \
  $(CURDIR)/../runtime011/selftest.cpp \
  $(CURDIR)/../runtime008/fixtures.cpp \
  $(CURDIR)/../runtime008/selftest.cpp \
  $(CURDIR)/../runtime010/selftest.cpp \
  $(CURDIR)/../runtime006/bridge.cpp \
  $(CURDIR)/../xbox-runtime/guest_memory.cpp
NXDK_DIR ?= $(CURDIR)/../../buildkit/sources/nxdk
CXXFLAGS += -std=c++20 -O2 -march=pentium3 -fomit-frame-pointer -fno-exceptions -fno-rtti -ffp-contract=off -fno-fast-math
CXXFLAGS += -DCC_XBOX_DRIVER
# Play build: no verification counters (~16% faster; CHECKs report, not stop)
CXXFLAGS += -DCC_FAST
# Build variants below change CXXFLAGS; make does not track flag changes, so
# touch runtime021/bridge.cpp and nxdk-checkpoint022/*.cpp before and after
# a variant build (tools/build_checkpoint022_nxdk.sh does not).
# Input script variant that selects Quit on the main menu: make SCRIPT=quit
ifeq ($(SCRIPT),quit)
CXXFLAGS += -DCC_SCRIPT_QUIT
endif
# Bisect switches: make BINDEXACT=1 (run the exact per-sprite bind),
# CULLEXACT=1 (exact sprite cull), NOFMAFAST=1 (software fma only)
ifneq ($(BINDEXACT),)
CXXFLAGS += -DCC_BIND_EXACT_BUILD
endif
ifneq ($(CULLEXACT),)
CXXFLAGS += -DCC_CULL_EXACT_BUILD
endif
# Benchmark build: make BENCH=1 (fixed game clock, no frame pacing,
# per-window averages on screen; see runtime021/bodies.inc CC_BENCH)
# Direct level load after character select (diagnostic): make LEVEL=13
ifneq ($(LEVEL),)
CXXFLAGS += -DCC_DIRECT_LEVEL=$(LEVEL)
endif
# Four scripted players (join, pick knights, fight in a loop): make FOURP=1
ifneq ($(FOURP),)
CXXFLAGS += -DCC_SCRIPT_4P
endif
# Hot-code grouping (.text$hot; hung the console at boot, off by default): make HOT=1
ifneq ($(HOT),)
CXXFLAGS += -DCC_HOT_CODE
endif
# Guest memory through the 64 KiB page table instead of the flat guest
# window (verification build; see runtime021/guest_window.h): make PAGETABLE=1
ifneq ($(PAGETABLE),)
CXXFLAGS += -DCC_PAGE_TABLE
endif
# Flat window offset mask (keeps stray guest addresses out of kernel memory;
# runtime021/guest_window.h). Default: stores only (loads skip it; a stray
# write still cannot reach kernel memory). Console 4P level 13: the full
# mask cost ~4% of update time (18.4 vs 17.6 ms median), so loads go
# without. make WINDOWMASK=all masks loads too; make NOWINDOWMASK=1 drops
# it (a stray guest address can then reach kernel memory). Touch
# runtime021/bridge.cpp, guest_window.cpp and update_boundary_tests.cpp.
WINDOWMASK ?= stores
ifneq ($(NOWINDOWMASK),)
CXXFLAGS += -DCC_WINDOW_NOMASK
endif
ifeq ($(WINDOWMASK),stores)
CXXFLAGS += -DCC_WINDOW_MASK_STORES
endif
# Flat window: commit the 360 command ring in full instead of sharing one
# 256 KiB block between its pages (runtime021/guest_window.h): make NORINGALIAS=1
# (only runtime021/update_boundary_tests.cpp reads it; touch it)
ifneq ($(NORINGALIAS),)
CXXFLAGS += -DCC_NO_RING_ALIAS
endif
# Flat window: back the hottest guest regions with 4 MiB pages (page
# directory entries over contiguous memory, 4 KiB pages for any region where
# a step fails; MEM lines on the debug channel say which path is active):
# make LARGEPAGES=1 (stack/TLS/game heap and the game data image),
# LARGEPAGES=heap or LARGEPAGES=image for one of them (only
# runtime021/update_boundary_tests.cpp reads it; touch it). Unmapped gaps
# inside those 4 MiB pages read as zeros instead of stopping a stray access
# (runtime021/guest_window.h).
ifeq ($(LARGEPAGES),1)
CXXFLAGS += -DCC_LARGE_PAGES=3
else ifeq ($(LARGEPAGES),heap)
CXXFLAGS += -DCC_LARGE_PAGES=1
else ifeq ($(LARGEPAGES),image)
CXXFLAGS += -DCC_LARGE_PAGES=2
endif
# Texture pack read-ahead buffer in KiB (runtime021/bodies.inc,
# cc_bake_fetch; default 512, 0 = off): make BAKERA=256 (touch
# runtime021/bridge.cpp). It pays off with a pack laid out in first-use
# order (tools/texbake_order.py); discdata copies TEXPACK as texbake.pak.
ifneq ($(BAKERA),)
CXXFLAGS += -DCC_BAKE_READAHEAD_KB=$(BAKERA)
endif
TEXPACK ?= $(CURDIR)/../game-data/converted/texbake.pak
# Console census of slow-path memory pages (page-table builds only):
# make PAGETABLE=1 SLOWSTATS=1
ifneq ($(SLOWSTATS),)
CXXFLAGS += -DCC_SLOW_STATS
endif
# Console op census: make OPSTATS=1
ifneq ($(OPSTATS),)
CXXFLAGS += -DCC_OP_STATS
endif
ifneq ($(BENCH),)
CXXFLAGS += -DCC_BENCH
endif
# Script locals from the activation slab instead of the game heap (not
# exact: heap placement changes; see runtime021/as_native.inc): make ASSLAB=1
ifneq ($(ASSLAB),)
CXXFLAGS += -DCC_AS_SLAB_BUILD
endif
ifneq ($(SPRITEEXACT),)
CXXFLAGS += -DCC_SPRITE_EXACT_BUILD
endif
ifneq ($(WALKEXACT),)
CXXFLAGS += -DCC_WALK_EXACT_BUILD
endif
# Sprite leaf bisect: SPRITEUNFUSED=1 (general leaf path), SPRITERING=1
# (native quads through the guest vertex ring and sub_820C1980, unbatched)
ifneq ($(SPRITEUNFUSED),)
CXXFLAGS += -DCC_SPRITE_UNFUSED_BUILD
endif
ifneq ($(SPRITERING),)
CXXFLAGS += -DCC_SPRITE_RING_BUILD
endif
# Frame end waits for the GPU to finish the frame before presenting (the
# CPU and GPU then never overlap): make XRSERIAL=1 (bisect only)
ifneq ($(XRSERIAL),)
CXXFLAGS += -DCC_XR_SERIAL
endif
# Draw walk bisect: WALKVCALL=1 (every method through cc_vcall, no visibility
# chains), WALKNOINHERIT=1 (the visibility query for every child),
# WALKNOPREFETCH=1 (no next-sibling prefetch)
ifneq ($(WALKVCALL),)
CXXFLAGS += -DCC_WALK_VCALL_BUILD
endif
ifneq ($(WALKNOINHERIT),)
CXXFLAGS += -DCC_WALK_NOINHERIT_BUILD
endif
ifneq ($(WALKNOPREFETCH),)
CXXFLAGS += -DCC_WALK_NOPREFETCH_BUILD
endif
# Effect-quad colour as before its fix (read at +20 of 32-byte vertices): COLOUR20=1
ifneq ($(COLOUR20),)
CXXFLAGS += -DCC_COLOUR20_BUILD
endif
# Text bisect: GLYPHEXACT=1 (recompiled glyph rectangle, renderer slot 112)
ifneq ($(GLYPHEXACT),)
CXXFLAGS += -DCC_GLYPH_EXACT_BUILD
endif
# TEXTEXACT=1 (recompiled glyph loop sub_820A9E98 and string measure sub_820A9D78)
ifneq ($(TEXTEXACT),)
CXXFLAGS += -DCC_TEXT_EXACT_BUILD
endif
# Depth set bisect: DEPTHEXACT=1 (recompiled sub_820878E0)
ifneq ($(DEPTHEXACT),)
CXXFLAGS += -DCC_DEPTH_EXACT_BUILD
endif
# Timeline seek bisect: SEEKEXACT=1 (recompiled sub_82087F70, runtime021/seek.inc)
ifneq ($(SEEKEXACT),)
CXXFLAGS += -DCC_SEEK_EXACT_BUILD
endif
ifneq ($(NOFMAFAST),)
CXXFLAGS += -DCC_NO_FMA_FAST
endif
# Pentium III performance counters, a PMC line per second next to PERF
# (xbox_perf.cpp): make PMC=1
ifneq ($(PMC),)
CXXFLAGS += -DCC_PMC
endif
# On-screen sampling profiler: make PROFILE=1
ifneq ($(PROFILE),)
CXXFLAGS += -DCC_XBOX_PROFILE
SRCS += $(CURDIR)/xbox_profile.cpp
endif
# The boundary harness keeps its guest stack/TLS arenas as C++ stack
# arrays (up to 64 KiB each); give the XBE a 1 MiB thread stack.
LDFLAGS += -stack:0x100000
# Linker map (symbol addresses) for the console profiler
# (tools/xbox_console.py profile, tools/xbox_symbolize.py).
LDFLAGS += -map:$(CURDIR)/main.map
# Newer clang defaults the bare i386-pc-win32 triple to an ancient MSVC
# compatibility level where char16_t/char32_t are not keywords; pin a modern
# level so nxdk's libc++ headers compile (build-infrastructure flag only).
CXXFLAGS += -fms-compatibility-version=19.29
CFLAGS += -fms-compatibility-version=19.29
# Controller input (xbox_input.cpp) uses nxdk SDL game controllers.
NXDK_SDL = y
include $(NXDK_DIR)/Makefile

$(CURDIR)/../runtime021/bridge.obj: $(CURDIR)/../runtime021/audio.inc $(CURDIR)/../runtime021/bodies.inc $(CURDIR)/../runtime021/seek.inc $(wildcard $(CURDIR)/../runtime021/as_*.inc) $(CURDIR)/../runtime008/bodies.inc $(CURDIR)/../runtime021/decls.inc $(CURDIR)/../runtime021/dispatch.inc $(wildcard $(CURDIR)/../runtime021/generated/*.inc) $(CURDIR)/../runtime021/cc_log.h $(CURDIR)/../runtime021/guest_window.h
$(CURDIR)/../runtime021/update_boundary_tests.obj: $(CURDIR)/../runtime021/cc_log.h $(CURDIR)/../runtime021/selftest.h $(CURDIR)/../runtime021/guest_window.h
$(CURDIR)/../runtime021/guest_window.obj: $(CURDIR)/../runtime021/cc_log.h $(CURDIR)/../runtime021/guest_window.h

# Disc payload: the boundary chain's inputs live under D:\data on the ISO.
.PHONY: discdata
discdata: $(OUTPUT_DIR)
	@mkdir -p $(OUTPUT_DIR)/data/game-data
	cp -f $(CURDIR)/../renderer011/startup.cct $(OUTPUT_DIR)/data/startup.cct
	cp -f $(CURDIR)/../castle-crashers-port/reference/default.image.bin $(OUTPUT_DIR)/data/default.image.bin
	cp -rf $(CURDIR)/../game-data/extracted/shaders $(OUTPUT_DIR)/data/game-data/
	cp -rf $(CURDIR)/../game-data/extracted/fonts $(OUTPUT_DIR)/data/game-data/Fonts
	# Game session data: paks and levels as shipped, with the port's
	# rewritten files (game-data/converted/data, e.g. the stripped
	# SOUNDS.PAK) replacing their originals, and the converted Xbox ADPCM
	# audio (tools/convert_audio.py) under audio/.
	for d in game levels art bsps; do cp -rf $(CURDIR)/../game-data/extracted/$$d $(OUTPUT_DIR)/data/game-data/; done
	if [ -d $(CURDIR)/../game-data/converted/data ]; then cp -rf $(CURDIR)/../game-data/converted/data/. $(OUTPUT_DIR)/data/game-data/; fi
	@mkdir -p $(OUTPUT_DIR)/data/game-data/audio
	cp -rf $(CURDIR)/../game-data/converted/audio/. $(OUTPUT_DIR)/data/game-data/audio/
	# Pre-rasterized DXT5 textures (runtime021 CC_TEX_BAKE), optional;
	# TEXPACK=<file> picks another pack (e.g. texbake_ordered.pak).
	if [ -f $(TEXPACK) ]; then cp -f $(TEXPACK) $(OUTPUT_DIR)/data/game-data/texbake.pak; fi

$(GEN_XISO): discdata
