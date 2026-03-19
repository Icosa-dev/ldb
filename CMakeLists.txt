cmake_minimum_required(VERSION 3.10.0)
project(
    ldb 
    VERSION 0.1.0
    DESCRIPTION "A minimalist wide-column database management system"
    HOMEPAGE_URL "https://github.com/Icosa-dev/LDB"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

### Package Management
include(cmake/CPM.cmake)
CPMAddPackage("gh:boostorg/boost#boost-1.90.0")
CPMAddPackage("gh:Cyan4973/xxHash#v0.8.3")

add_compile_options(-Wall -Wextra)

file (GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(ldb ${SOURCES})
target_include_directories(ldb PRIVATE
    "src/"
    ${boost_SOURCE_DIR}
)
target_link_libraries(ldb PRIVATE 
    xxhash
    Boost::multiprecision
    Boost::uuid
)

add_subdirectory(
    "test/"
)