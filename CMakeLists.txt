# superman_returns - ReXGlue Recompiled Project
#
# SDK boilerplate lives in generated/rexglue.cmake.

cmake_minimum_required(VERSION 3.25)
project(superman_returns LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(generated/rexglue.cmake)

# Sources
set(SUPERMANRETURNS_SOURCES
    src/main.cpp
    src/game_menu.cpp
    src/crash_handler.cpp
    src/disc_setup.cpp
    src/xma_guard.cpp
    src/audio_hooks.cpp
    src/audio_pacing.cpp
    src/audio_diag.cpp
)

if(WIN32)
    add_executable(superman_returns WIN32 ${SUPERMANRETURNS_SOURCES})
else()
    add_executable(superman_returns ${SUPERMANRETURNS_SOURCES})
endif()

rexglue_setup_target(superman_returns GPU_PLUGINS xenos)

# Linker map: turns crash-report offsets (superman_returns.exe+0x...) into
# recompiled function names.
if(WIN32)
    target_link_options(superman_returns PRIVATE "LINKER:/MAP:${CMAKE_BINARY_DIR}/superman_returns.map")
endif()
