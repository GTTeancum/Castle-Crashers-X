# castle_crashers - ReXGlue Recompiled Project
#
# SDK boilerplate lives in generated/rexglue.cmake.

cmake_minimum_required(VERSION 3.25)
project(castle_crashers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(generated/rexglue.cmake)
find_package(Python3 REQUIRED COMPONENTS Interpreter)
add_custom_command(TARGET castle_crashers_codegen POST_BUILD
  COMMAND "${Python3_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/tools/repair_switch.py"
  COMMAND "${Python3_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/../tools/install_trace008_headers.py"
  COMMENT "Repairing verified computed-CTR switch and installing opt-in trace macros")

# Sources
option(CC_RENDER_CAPTURE "Build Linux-only passive draw capture hooks" OFF)
set(CASTLECRASHERS_SOURCES
    src/main.cpp
    src/full_game009.cpp
)

if(WIN32)
    add_executable(castle_crashers WIN32 ${CASTLECRASHERS_SOURCES})
else()
    add_executable(castle_crashers ${CASTLECRASHERS_SOURCES})
endif()

rexglue_setup_target(castle_crashers GPU_PLUGINS xenos)

if(CC_RENDER_CAPTURE)
  if(NOT CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(FATAL_ERROR "Capture 004 requires Linux /proc/self/mem")
  endif()
  target_sources(castle_crashers PRIVATE src/render_capture004.cpp)
endif()

option(CC_SCENE_TRACE008 "Trace original scene subtree memory/calls" OFF)
if(CC_SCENE_TRACE008)
  if(NOT CC_RENDER_CAPTURE)
    message(FATAL_ERROR "CC_SCENE_TRACE008 requires CC_RENDER_CAPTURE")
  endif()
  target_compile_definitions(castle_crashers PRIVATE CC_SCENE_TRACE008=1)
  target_compile_definitions(castle_crashers_recomp PRIVATE CC_SCENE_TRACE008=1)
endif()
