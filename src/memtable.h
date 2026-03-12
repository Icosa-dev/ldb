/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef MEMTABLE_H
#define MEMTABLE_H

#include <stdbool.h>

/**
 * @brief Holds multiple data types in binary trees
 *
 * The purpose of the memtable is to serve as a way
 * to manage binary trees of different data types
 * as one. Each memtable also has a key and is
 * stored in a binary tree which represents each
 * database.
 */
struct memtable
{
    int key;
    struct binary_tree_node *int_tree,
        *bool_tree,
        *double_tree,
        *string_tree;
};

struct memtable *create_memtable(int key);

#endif