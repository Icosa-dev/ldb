#include "binary_tree.h"

#include <stddef.h>
#include <stdbool.h>

void binary_tree_insert(
    struct binary_tree_node **root,
    void *data)
{
    struct binary_tree_node *new_node = (struct binary_tree_node *)malloc(sizeof(struct binary_tree_node));
    if (*root == NULL)
    {
        *root = new_node;
        return;
    }

    struct binary_tree_node *temp, *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = *root;

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

void binary_tree_delete(
    struct binary_tree_node **root,
    void *data,
    int (*cmp)(void *a, void *b))
{
    if (*root == NULL)
        return;

    if ((*root)->left == NULL && (*root)->right == NULL)
    {
        if (cmp((*root)->left, data) == 0)
        {
            free(*root);
            *root = NULL;
            return;
        }
        else
            return;
    }

    struct binary_tree_node *temp, *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = *root;
    struct binary_tree_node *key_node = NULL;

    while (front != rear)
    {
        temp = queue[++front];

        if (temp->data == data)
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

    if (key_node != NULL)
    {
        struct binary_tree_node *deepest_node = get_deepest_rightmost_node(*root);
        key_node->data = deepest_node->data;
        delete_deepest_rightmost_node(*root, deepest_node);
    }
}

struct binary_tree_node *binary_tree_search(
    struct binary_tree_node *root,
    void *data,
    int (*cmp)(void *a, void *b))
{
    if (root == NULL)
        return NULL;

    struct binary_tree_node *temp, *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear)
    {
        temp = queue[++front];

        if (cmp(temp->data, data))
            return temp;
        if (temp->left != NULL)
            queue[++rear] = temp->left;
        if (temp->right != NULL)
            queue[++rear] = temp->right;
    }

    return NULL;
}
