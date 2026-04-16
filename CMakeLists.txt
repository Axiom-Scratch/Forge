cmake_minimum_required(VERSION 3.20)
project(Axiom)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Sources
file(GLOB_RECURSE SRC_FILES
    src/*.cpp
)

add_executable(Axiom ${SRC_FILES})

target_include_directories(Axiom PRIVATE
    src
)

# Warnings
if (MSVC)
    target_compile_options(Axiom PRIVATE /W4)
else()
    target_compile_options(Axiom PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Debug / Release flags
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Build type: Debug")
else()
    message(STATUS "Build type: Release")
endif()