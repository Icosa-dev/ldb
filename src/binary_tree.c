/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "binary_tree.h"

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Allocate memory for a new binary tree node
 * @param key Value for `binary_tree_node.key` in the new node
 * @param data_ptr Value for `binary_tree_node.data_ptr` in the new node
 * @return Pointer to the memory allocated to the new binary tree node
 */
struct binary_tree_node *create_binary_tree_node(int key, void *data_ptr)
{
    struct binary_tree_node *new_node = 
        (struct binary_tree_node *)malloc(sizeof(struct binary_tree_node));
    new_node->key = key;
    new_node->data_ptr = data_ptr;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

/**
 * @brief Insert a new node into the binary tree or overwrites
 * an existing one with the same key.
 * @param root_ptr Pointer to the root node of the binary tree
 * @param key The key of the new node to be inserted
 * @param data_ptr Pointer to the data the node will store
 */
void binary_tree_insert(struct binary_tree_node **root_ptr, int key, 
    void *data_ptr)
{
    struct binary_tree_node **walker = root_ptr;

    while (*walker != NULL)
    {
        if (key == (*walker)->key)
        {
            (*walker)->data_ptr = data_ptr;
            return;
        }

        if (key < (*walker)->key)
            walker = &((*walker)->left);
        else
            walker = &((*walker)->right);
    }

    *walker = create_binary_tree_node(key, data_ptr);
}

static struct binary_tree_node *get_min_node(struct binary_tree_node *node)
{
    struct binary_tree_node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

static struct binary_tree_node *delete_recursive(struct binary_tree_node *root, 
    int key)
{
    if (root == NULL)
        return NULL;

    if (key < root->key)
        root->left = delete_recursive(root->left, key);
    else if (key > root->key)
        root->right = delete_recursive(root->right, key);
    else
    {
        struct binary_tree_node *temp;
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        struct binary_tree_node *successor = get_min_node(root->right);

        root->key = successor->key;
        root->data_ptr = successor->data_ptr;

        root->right = delete_recursive(root->right, successor->key);
    }

    return root;
}

/**
 * @brief Delete a node from the binary tree
 * @param root_ptr Pointer to the root node
 * @param key Key of the node to be delete
 */
void binary_tree_delete(struct binary_tree_node **root_ptr, int key)
{
    if (root_ptr == NULL || *root_ptr == NULL)
        return;
    *root_ptr = delete_recursive(*root_ptr, key);
}

/**
 * @brief Search the binary tree for a node with a specific key
 * @param root Root node of the binary tree
 * @param key Key of the node to find
 * @return Pointer to the node if found or NULL if not
 */
struct binary_tree_node *binary_tree_search(struct binary_tree_node *root, 
    int key)
{
    struct binary_tree_node *current = root;

    while (current != NULL)
    {
        if (key == current->key)
            return current;

        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    return NULL;
}

/**
 * @brief Free every node of a binary tree
 * @param root_ptr Pointer to the root node of the binary tree
 */
void free_binary_tree(struct binary_tree_node **root_ptr)
{
    if (root_ptr == NULL || *root_ptr == NULL)
        return;
    free_binary_tree(&(*root_ptr)->left);
    free_binary_tree(&(*root_ptr)->right);
    free(*root_ptr);
    *root_ptr = NULL;
}