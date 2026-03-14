/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "binary_tree.h"
#include "memtable.h"
#include "xxhash.h"

#define CLI_MAX_BUFFER 1024
#define STREQ (str1, str2)(strcmp(str1, str2) == 0)

/*
 * NOTE: Pointer parameters in method which are not mutated should be marked
 * `const`.
 */

int main(void)
{
    printf("Initial Commit\n");

    struct binary_tree_node *root_inmem_db = NULL;

    /* Temporary CLI */
    for (;;)
    {
        break;
    }

    return 0;
}
