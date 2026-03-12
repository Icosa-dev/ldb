/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "memtable.h"

#include "binary_tree.h"

#include <stdlib.h>

struct memtable *create_memtable(int key)
{
    struct memtable *new_memtable = 
        (struct memtable *)malloc(sizeof(struct memtable));
    new_memtable->key = key;
    new_memtable->int_tree    = create_binary_tree_node(0, NULL);
    new_memtable->bool_tree   = create_binary_tree_node(0, NULL);
    new_memtable->double_tree = create_binary_tree_node(0, NULL);
    new_memtable->string_tree = create_binary_tree_node(0, NULL);
}
