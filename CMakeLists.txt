# CMake
cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 23)

# Project properties
project(Revenant VERSION 0.1.0.0)

message("CMAKE_PROJECT_VERSION = ${CMAKE_PROJECT_VERSION}")

# ScriptHookV
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/ScriptHookV/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/ScriptHookV/lib)

# Add source files
message(STATUS "Building Revenant...")
include_directories(src lib)
file(GLOB_RECURSE SRC_MAIN
        src/*.cpp
        src/GTA/*.cpp
        src/GTA/entities/*.cpp
        src/GTA/entities/peds/*.cpp
        src/GTA/vehicles/*.cpp
        src/GTA.UI/.cpp
        src/Controllers/*.cpp
        lib/Memory/*.cpp
        lib/*.cpp)

# Build
add_library(Revenant SHARED "${SRC_MAIN}")
target_link_libraries(Revenant ScriptHookV)

# Force include common.hpp
target_precompile_headers(Revenant PRIVATE src/revenant_pch.h)

# Set extension to .asi
set_target_properties(Revenant PROPERTIES SUFFIX ".asi")