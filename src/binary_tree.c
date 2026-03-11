#include "binary_tree.h"

#include <stddef.h>
#include <stdbool.h>

// TODO: Functions should return error codes instead of void

/**
 * @brief Allocate memory for a new binary tree node
 * @param key Value for `binary_tree_node.key` in the new node
 * @param data_ptr Value for `binary_tree_node.data_ptr` in the new node
 * @return Pointer to the memory allocated to the new binary tree node
 */
struct binary_tree_node *create_binary_tree_node(int key, void *data_ptr)
{
    struct binary_tree_node *new_node = (struct binary_tree_node *)malloc(sizeof(struct binary_tree_node));
    new_node->key = key;
    new_node->data_ptr = data_ptr;
    new_node->left = NULL;
    new_node->right = NULL;
}

/**
 * @brief Insert a new node into the binary tree
 * @param root_ptr Pointer to the root node of the binary tree
 * @param key The key of the new node to be inserted
 * @param data_ptr Pointer to the data the node will store
 */
void binary_tree_insert(
    struct binary_tree_node **root_ptr,
    int key,
    void *data_ptr)
{
    struct binary_tree_node *new_node = create_binary_tree_node(key, data_ptr);
    if (*root_ptr == NULL)
    {
        *root_ptr = new_node;
        return;
    }

    struct binary_tree_node *temp, *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = *root_ptr;

    while (front != rear)
    {
        temp = queue[++front];

        if (temp->left == NULL)
        {
            temp->left = new_node;
            return;
        }
        else
        {
            queue[++rear] = temp->left;
        }

        if (temp->right == NULL)
        {
            temp->right = new_node;
            return;
        }
        else
        {
            queue[++rear] = temp->right;
        }
    }
}

/**
 * @brief Retrieves the deepest rightmost node of the binary tree.
 * That is, the node with the greatest value.
 * @param root Pointer to the root node of the tree
 * @return Pointer to the deepest rightmost node of the tree
 */
static struct binary_tree_node *get_deepest_rightmost_node(struct binary_tree_node *root)
{
    struct binary_tree_node *temp, *queue[100];
    int front = -1, rear = -1;
    queue[++rear] == root;

    while (front != rear)
    {
        temp = queue[++front];

        if (temp->left != NULL)
        {
            queue[++rear] = temp->left;
        }

        if (temp->right != NULL)
        {
            queue[++rear] = temp->right;
        }
    }

    return temp;
}

/**
 * @brief Delete's the deepest rightmost node of the binary tree
 * @param root Pointer to the root node of the binary tree
 * @param d_node Pointer to the deepest rightmost node of the binary tree
 */
static void delete_deepest_rightmost_node(
    struct binary_tree_node *root,
    struct binary_tree_node *d_node)
{
    struct binary_tree_node *temp, *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear)
    {
        temp = queue[++front];

        if (temp == d_node)
        {
            temp = NULL;
            free(d_node);
            return;
        }

        if (temp->right != NULL)
        {
            if (temp->right == d_node)
            {
                temp->right = NULL;
                free(d_node);
                return;
            }
            else
            {
                queue[++rear] = temp->right;
            }
        }

        if (temp->left != NULL)
        {
            if (temp->left == d_node)
            {
                temp->left = NULL;
                free(d_node);
                return;
            }
            else
            {
                queue[++rear] = temp->left;
            }
        }
    }
}

/**
 * @brief Delete a node from the binary tree
 * @param root_ptr Pointer to the root node
 * @param key Key of the node to be delete
 */
void binary_tree_delete(
    struct binary_tree_node **root_ptr,
    int key)
{
    if (*root_ptr == NULL)
        return;

    if ((*root_ptr)->left == NULL && (*root_ptr)->right == NULL)
    {
        if ((*root_ptr)->key == key)
        {
            free(*root_ptr);
            *root_ptr = NULL;
            return;
        }
        else
            return;
    }

    struct binary_tree_node *temp, *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = *root_ptr;
    struct binary_tree_node *key_node = NULL;

    while (front != rear)
    {
        temp = queue[++front];

        if (temp->key == key)
        {
            key_node = temp;
        }

        if (temp->left != NULL)
        {
            queue[++rear] = temp->left;
        }

        if (temp->right != NULL)
        {
            queue[++rear] = temp->right;
        }
    }

    if (key_node == NULL)
    {
        struct binary_tree_node *deepest_node = get_deepest_rightmost_node(*root_ptr);
        key_node->key = deepest_node->key;
        delete_deepest_rightmost_node(*root_ptr, deepest_node);
    }
}

/**
 * @brief Search the binary tree for a node with a specific key
 * @param root Root node of the binary tree
 * @param key Key of the node to find
 * @return Pointer to the node if found or NULL if not
 */
struct binary_tree_node *binary_tree_search(
    struct binary_tree_node *root,
    int key)
{
    if (root == NULL)
        return NULL;

    struct binary_tree_node *temp, *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear)
    {
        if (temp->key == key)
            return temp;

        if (temp->left != NULL)
            queue[++rear] = temp->left;

        if (temp->right != NULL)
            queue[++rear] = temp->right;
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