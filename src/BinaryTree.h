/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

template <typename T>
struct Node
{
    int key;
    T value;
    Node *left, *right;

    Node(int key, T value) : key(key), value(value),
                             left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree
{
private:
    Node<T> *root;

    void Clear(Node<T> *node)
    {
        if (node)
        {
            Clear(node->left);
            Clear(node->right);
            delete node;
        }
    }

    Node<T> *DeleteRecursive(Node<T> *current, int key)
    {
        if (!current)
            return nullptr;

        if (key < current->key)
            current->left = DeleteRecursive(current->left, key);
        else if (key > current->key)
            current->right = DeleteRecursive(current->right, key);
        else
        {
            if (!current->left)
            {
                Node<T> *temp = current->right;
                delete current;
                return temp;
            }
            if (!current->right)
            {
                Node<T> *temp = current->left;
                delete current;
                return temp;
            }

            Node<T> *successor = FindMin(current->right);
            current->key = successor->key;
            current->value = successor->value;
            current->right = DeleteRecursive(current->right, successor->key);
        }

        return current;
    }

    Node<T> *FindMin(Node<T> *node)
    {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    Node<T> *InsertRecursive(Node<T> *node, int key, T value)
    {
        if (node == nullptr)
            return new Node<T>(key, value);

        if (key < node->key)
            node->left = InsertRecursive(node->left, key, value);
        else
            node->right = InsertRecursive(node->right, key, value);

        return node;
    }

    Node<T> *GetNodeRecursive(Node<T> *node, int key)
    {
        if (!node)
            return nullptr;
        if (node->key == key)
            return node;

        if (key < node->key)
            return GetNodeRecursive(node->left, key);
        else
            return GetNodeRecursive(node->right, key);
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree()
    {
        Clear(root);
    }

    inline void InsertNode(int key, T value)
    {
        root = InsertRecursive(root, key, value);
    }

    inline void DeleteNode(int key)
    {
        root = DeleteRecursive(root, key);
    }

    inline Node<T> *GetNode(int key)
    {
        return GetNodeRecursive(root, key);
    }
};
