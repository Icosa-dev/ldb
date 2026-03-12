/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <assert.h>

#include "binary_tree.h"

/* NOTE: all the names for things are shit and should be changed */

int main(void)
{
    int root_data = 27;
    printf("Testing create_binary_tree_node()...\n");
    struct binary_tree_node *root = create_binary_tree_node(0, &root_data);

    /*
     * The create_binary_tree_node function should return a
     * node which is not null, has a key equal to 0, a data
     * pointer equal to &root_data, and null left and right
     * nodes.
     */
    assert(root != NULL);
    assert(root->key == 0);
    assert(root->data_ptr == &root_data);
    assert(root->left == NULL);
    assert(root->right == NULL);

    printf("Testing binary_tree_insert()...\n");
    /*
     * Insert nodes with key 1 and 2.
     * Node 1 has data of type int and
     * node 2 has data of type double.
     * Both should work since each node
     * holds a generic void pointer.
     */
    int node1_data = 10;
    binary_tree_insert(&root, 1, &node1_data);
    double node2_data = 2.5;
    binary_tree_insert(&root, 2, &node2_data);

    printf("Testing binary_tree_search()...\n");
    struct binary_tree_node *node1 = binary_tree_search(root, 1);
    struct binary_tree_node *node2 = binary_tree_search(root, 2);
    /*
     * If either is null the search function or a function before
     * has failed.
     */
    assert(node1 != NULL && node2 != NULL);

    int node1_data_from_ptr = *(int *)node1->data_ptr;
    double node2_data_from_ptr = *(double *)node2->data_ptr;

    assert(node1_data == node1_data_from_ptr);
    assert(node2_data == node2_data_from_ptr);

    printf("Testing binary_tree_delete()...\n");
    binary_tree_delete(&root, 1);
    binary_tree_delete(&root, 2);

    printf("Testing binary_tree_search() on non-existant nodes...\n");
    node1 = binary_tree_search(root, 1);
    node2 = binary_tree_search(root, 2);

    assert(node1 == NULL && node2 == NULL);

    printf("Testing free_binary_tree()...\n");
    free_binary_tree(&root);

    assert(root == NULL);

    return 0;
}