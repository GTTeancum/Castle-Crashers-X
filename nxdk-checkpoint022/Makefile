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
CXXFLAGS += -std=c++20 -O2 -march=pentium3 -fno-exceptions -fno-rtti -ffp-contract=off -fno-fast-math
CXXFLAGS += -DCC_XBOX_DRIVER
# Play build: no verification counters (~16% faster; CHECKs report, not stop)
CXXFLAGS += -DCC_FAST
# Input script variant that selects Quit on the main menu: make SCRIPT=quit
ifeq ($(SCRIPT),quit)
CXXFLAGS += -DCC_SCRIPT_QUIT
endif
# On-screen sampling profiler: make PROFILE=1
ifneq ($(PROFILE),)
CXXFLAGS += -DCC_XBOX_PROFILE
SRCS += $(CURDIR)/xbox_profile.cpp
endif
# The boundary harness keeps its guest stack/TLS arenas as C++ stack
# arrays (up to 64 KiB each); give the XBE a 1 MiB thread stack.
LDFLAGS += -stack:0x100000
# Newer clang defaults the bare i386-pc-win32 triple to an ancient MSVC
# compatibility level where char16_t/char32_t are not keywords; pin a modern
# level so nxdk's libc++ headers compile (build-infrastructure flag only).
CXXFLAGS += -fms-compatibility-version=19.29
CFLAGS += -fms-compatibility-version=19.29
# Controller input (xbox_input.cpp) uses nxdk SDL game controllers.
NXDK_SDL = y
include $(NXDK_DIR)/Makefile

$(CURDIR)/../runtime021/bridge.obj: $(CURDIR)/../runtime021/audio.inc $(CURDIR)/../runtime021/bodies.inc $(CURDIR)/../runtime021/decls.inc $(CURDIR)/../runtime021/dispatch.inc $(wildcard $(CURDIR)/../runtime021/generated/*.inc) $(CURDIR)/../runtime021/cc_log.h
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
