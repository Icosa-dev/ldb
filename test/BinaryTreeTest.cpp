/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "../src/BinaryTree.h"

#include <gtest/gtest.h>

template <typename T>
static void InsertTestValues(BinaryTree<T> &binaryTree)
{
    binaryTree.InsertNode(1, 5);
    binaryTree.InsertNode(2, 3);
    binaryTree.InsertNode(6, 2);
    binaryTree.InsertNode(7, 10);
}

TEST(LDBBinaryTreeTest, InsertAndRetrieve)
{
    // Initialize test binary tree
    BinaryTree<int> binaryTree = BinaryTree<int>();

    // Insert test values into tree
    InsertTestValues<int>(binaryTree);

    // Retrieve the values from each
    EXPECT_EQ(binaryTree.GetNode(1)->value, 5);
    EXPECT_EQ(binaryTree.GetNode(2)->value, 3);
    EXPECT_EQ(binaryTree.GetNode(6)->value, 2);
    EXPECT_EQ(binaryTree.GetNode(7)->value, 10);
}

TEST(LDBBinaryTreeTest, InsertAndDelete)
{
    // Initialize test binary tree
    BinaryTree<int> binaryTree = BinaryTree<int>();

    // Insert test values into tree
    InsertTestValues<int>(binaryTree);

    // Delete node 6. GetNode should return nullptr
    binaryTree.DeleteNode(6);
    EXPECT_EQ(binaryTree.GetNode(6), nullptr);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
