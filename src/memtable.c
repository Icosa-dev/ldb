#include "memtable.h"

#include "binary_tree.h"

#include <stdlib.h>

struct memtable *create_memtable(int key)
{
    struct memtable *new_memtable = (struct memtable *)malloc(sizeof(struct memtable));
    new_memtable->key = key;
    // I believe this should work since it would
    // alloc memory for the tables but not give them
    // any data
    new_memtable->int_tree    = create_binary_tree_node(NULL, NULL);
    new_memtable->bool_tree   = create_binary_tree_node(NULL, NULL);
    new_memtable->double_tree = create_binary_tree_node(NULL, NULL);
    new_memtable->string_tree = create_binary_tree_node(NULL, NULL);
}
