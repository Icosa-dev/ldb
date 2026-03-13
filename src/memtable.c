/**
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "memtable.h"

#include <stdlib.h>

struct memtable *create_memtable(void)
{
    /* NOTE: I think calloc should be used here instead. */
    struct memtable *new_memtable =
        (struct memtable *)malloc(sizeof(struct memtable));
    new_memtable->int_tree = NULL;
    new_memtable->bool_tree = NULL;
    new_memtable->double_tree = NULL;
    new_memtable->string_tree = NULL;

    return new_memtable;
}
