#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct binary_tree_node
{
    void *data;
    struct binary_tree_node *left, *right;
};

void binary_tree_insert(
    struct binary_tree_node **root,
    void *data);

void binary_tree_delete(
    struct binary_tree_node **root,
    void *data,
    int (*cmp)(void *a, void *b));

struct binary_tree_node *binary_tree_search(
    struct binary_tree_node *root,
    void *data,
    int (*cmp)(void *a, void *b));

#endif