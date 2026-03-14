/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef MEMTABLE_H
#define MEMTABLE_H

#include "binary_tree.h"

/*
 * The memtable struct is used to hold the root nodes for trees of each
 * data type in the database. Each in-memory database has multiple
 * memtables.
 */
struct memtable
{
    struct binary_tree_node *int_tree;    /// Root node of the int tree
    struct binary_tree_node *bool_tree;   /// Root node of the bool tree
    struct binary_tree_node *double_tree; /// Root node of the double tree
    struct binary_tree_node *string_tree; /// Root node of the string tree
};

struct memtable *create_memtable(void);

#endif