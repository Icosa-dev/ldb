include(../cmake/CPM.cmake)
CPMAddPackage("gh:google/googletest#v1.17.0")
CPMAddPackage("gh:boostorg/boost#boost-1.90.0")

enable_testing()

# DRY does not apply here and should. I'm not totally sure how to
# use CMake properly but there *has* to be a better way that this.
add_executable(
    BinaryTreeTest
    BinaryTreeTest.cpp
)
target_link_libraries(
    BinaryTreeTest
    GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(BinaryTreeTest)
