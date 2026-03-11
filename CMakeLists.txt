cmake_minimum_required(VERSION 3.10.0)
project(ldb VERSION 0.1.0 LANGUAGES C)

include(FetchContent)

FetchContent_Declare(
    xxhash
    GIT https://github.com/Cyan4973/xxHash
    GIT_TAG v0.8.3
)

FetchContent_GetProperties(xxhash)
if (NOT xxhash_POPULATED)
    FetchContent_Populate(xxhash)
    add_subdirectory(${xxhash_SOURCE_DIR}/cmake_unofficial ${xxhash_BINARY_DIR})
endif ()

include_directories(
    "src/"
)

file (GLOB SOURCES "src/*.c")

add_executable(ldb ${SOURCES})
target_link_libraries(ldb PRIVATE xxhash)