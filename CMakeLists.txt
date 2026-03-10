cmake_minimum_required(VERSION 3.10.0)
project(ldb VERSION 0.1.0 LANGUAGES C)

include_directories(
    "src/"
)

file (GLOB SOURCES "src/*.c")

add_executable(ldb ${SOURCES})