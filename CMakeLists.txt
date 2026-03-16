cmake_minimum_required(VERSION 3.10.0)
project(ldb VERSION 0.1.0 LANGUAGES CXX)

# BUILD DEPENDENCIES
find_package(Boost REQUIRED CONFIG)
find_package(xxHash REQUIRED)

file (GLOB SOURCES "src/*.cpp")

add_executable(ldb ${SOURCES})
target_include_directories(ldb PRIVATE
    "src/"
)
target_link_libraries(ldb PRIVATE 
    xxhash
    Boost::boost
)
