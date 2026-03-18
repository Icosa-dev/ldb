include(../cmake/CPM.cmake)
CPMAddPackage("gh:google/googletest#v1.17.0")

enable_testing()

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