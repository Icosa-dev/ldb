cmake_minimum_required(VERSION 3.10.0)
project(ldb VERSION 0.1.0 LANGUAGES CXX)

# BUILD DEPENDENCIES
find_package(Boost CONFIG REQUIRED)
find_package(xxHash CONFIG REQUIRED)

add_compile_options(-Wall -Wextra)

file (GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(ldb ${SOURCES})
target_include_directories(ldb PRIVATE
    "src/"
)
target_link_libraries(ldb PRIVATE 
    xxHash::xxhash
    Boost::boost
)
