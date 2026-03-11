#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct binary_tree_node
{
    int key;
    void *data_ptr;
    struct binary_tree_node *left, *right;
};

struct binary_tree_node *create_binary_tree_node(int key, void *data_ptr);

void binary_tree_insert(
    struct binary_tree_node **root_ptr,
    int key,
    void *data_ptr);

void binary_tree_delete(
    struct binary_tree_node **root_ptr,
    int key);

struct binary_tree_node *binary_tree_search(
    struct binary_tree_node *root,
    int key);

void free_binary_tree(struct binary_tree_node **root_ptr);

#endif