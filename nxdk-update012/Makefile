XBE_TITLE = CastleCrashers Update Boundary 012
GEN_XISO = CastleCrashers-Update012.iso
SRCS = $(CURDIR)/../port009/mode.cpp $(CURDIR)/../runtime007/numeric/fused.cpp $(CURDIR)/../runtime007/numeric/target_fma.cpp $(CURDIR)/main.cpp $(CURDIR)/../renderer011/live_frame.cpp $(CURDIR)/../runtime006/bridge.cpp $(CURDIR)/../runtime008/fixtures.cpp $(CURDIR)/../runtime012/bridge.cpp $(CURDIR)/../runtime012/selftest.cpp $(CURDIR)/../runtime011/selftest.cpp $(CURDIR)/../renderer005/stream_loader.cpp $(CURDIR)/../xbox-runtime/guest_memory.cpp
SHADER_OBJS = $(CURDIR)/ps.inl $(CURDIR)/vs.inl
NXDK_DIR ?= $(CURDIR)/../../buildkit/sources/nxdk
CXXFLAGS += -std=c++20 -O2 -fno-exceptions -fno-rtti -fstack-usage -ffp-contract=off -fno-fast-math
LDFLAGS += -map:$(CURDIR)/main.map
include $(NXDK_DIR)/Makefile
$(CURDIR)/main.obj: $(CURDIR)/ps.inl $(CURDIR)/vs.inl $(CURDIR)/backend.inc $(CURDIR)/telemetry.h $(CURDIR)/expected.h
$(CURDIR)/../runtime006/bridge.obj: $(wildcard $(CURDIR)/../runtime006/generated/*.inc) $(CURDIR)/../runtime006/bridge.h
$(SRCS:.cpp=.obj): CXXFLAGS += -Wall -Wextra -Werror

$(CURDIR)/../runtime012/bridge.obj: $(wildcard $(CURDIR)/../runtime008/generated/*.inc) $(CURDIR)/../runtime008/bridge.h $(CURDIR)/../runtime007/float_scope.inc

$(CURDIR)/../runtime012/bridge.obj: $(CURDIR)/../runtime008/bodies.inc $(CURDIR)/../runtime008/dispatch.inc

$(CURDIR)/../port009/mode.obj: $(CURDIR)/../port009/policy.h $(CURDIR)/../port009/mode.h $(wildcard $(CURDIR)/../port009/generated/*.inc)

$(CURDIR)/../runtime012/bridge.obj: $(CURDIR)/../runtime011/bodies.inc $(CURDIR)/../runtime011/dispatch.inc $(wildcard $(CURDIR)/../runtime011/generated/*.inc)

$(CURDIR)/../runtime012/bridge.obj: $(CURDIR)/../runtime011/bodies.inc $(CURDIR)/../runtime011/decls.inc $(CURDIR)/../runtime011/dispatch.inc $(wildcard $(CURDIR)/../runtime011/generated/*.inc) $(CURDIR)/../runtime010/bodies.inc $(CURDIR)/../runtime010/dispatch.inc $(wildcard $(CURDIR)/../runtime010/generated/*.inc)

$(CURDIR)/../runtime012/bridge.obj: $(CURDIR)/../runtime012/bodies.inc $(CURDIR)/../runtime012/decls.inc $(CURDIR)/../runtime012/dispatch.inc $(wildcard $(CURDIR)/../runtime012/generated/*.inc)
