XBE_TITLE = CastleCrashersX Checkpoint 022
GEN_XISO = CastleCrashersX-Checkpoint022.iso
SRCS = \
  $(CURDIR)/xbox_shims.cpp \
  $(CURDIR)/xbox_audio.cpp \
  $(CURDIR)/xbox_render.cpp \
  $(CURDIR)/xbox_input.cpp \
  $(CURDIR)/../runtime007/numeric/fused.cpp \
  $(CURDIR)/../runtime007/numeric/target_fma.cpp \
  $(CURDIR)/../runtime021/update_boundary_tests.cpp \
  $(CURDIR)/../runtime021/bridge.cpp \
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
# Console census of slow-path memory pages: make SLOWSTATS=1
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
ifneq ($(NOFMAFAST),)
CXXFLAGS += -DCC_NO_FMA_FAST
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

$(CURDIR)/../runtime021/bridge.obj: $(CURDIR)/../runtime021/audio.inc $(CURDIR)/../runtime021/bodies.inc $(wildcard $(CURDIR)/../runtime021/as_*.inc) $(CURDIR)/../runtime008/bodies.inc $(CURDIR)/../runtime021/decls.inc $(CURDIR)/../runtime021/dispatch.inc $(wildcard $(CURDIR)/../runtime021/generated/*.inc) $(CURDIR)/../runtime021/cc_log.h
$(CURDIR)/../runtime021/update_boundary_tests.obj: $(CURDIR)/../runtime021/cc_log.h $(CURDIR)/../runtime021/selftest.h

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
	# Pre-rasterized DXT5 textures (runtime021 CC_TEX_BAKE), optional.
	if [ -f $(CURDIR)/../game-data/converted/texbake.pak ]; then cp -f $(CURDIR)/../game-data/converted/texbake.pak $(OUTPUT_DIR)/data/game-data/; fi

$(GEN_XISO): discdata
