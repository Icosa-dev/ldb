cmake_minimum_required(VERSION 3.10.0)
project(ldb VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/CPM.cmake)
CPMAddPackage("gh:boostorg/multiprecision#Boost_1_89_0")
CPMAddPackage("gh:Cyan4973/xxHash#v0.8.3")

add_compile_options(-Wall -Wextra)

file (GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(ldb ${SOURCES})
target_include_directories(ldb PRIVATE
    "src/"
)
target_link_libraries(ldb PRIVATE 
    xxhash
    Boost::multiprecision
)

add_subdirectory(
    "test/"
)