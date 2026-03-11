/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef MEMTABLE_H
#define MEMTABLE_H

#include <stdbool.h>

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