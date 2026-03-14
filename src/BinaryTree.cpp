/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "BinaryTree.h"

template <typename T>
Node<T> *BinaryTree<T>::delete_recursive(Node<T> *current, int key)
{
    if (current == nullptr)
        return nullptr;

    if (current->data == value)
    {
        if (current->left == nullptr && current->right == nullptr)
        {
            delete current;
            return nullptr;
        }

        if (current->left == nullptr)
        {
            Node<T> *temp = current->right;
            delete current;
            return temp;
        }

        if (current->right == nullptr)
        {
            Node<T> *temp = current->left;
            delete current;
            return temp;
        }

        Node<T> *successor = find_min(current->right);
        current->data = successor->data;
        current->right = delete_recursive(current->right, successor->data);
    }
    else
    {
        current->left = delete_recursive(current->left, value);
        current->right = delete_recursive(current->right, value);
    }

    return current;
}

template <typename T>
Node<T> *BinaryTree<T>::find_min(Node<T> *node)
{
    while (node->left != nullptr)
        node = node->left;
    return node;
}

template <typename T>
bool BinaryTree<T>::search_recursive(Node<T> *current, int key)
{
    if (current == nullptr)
        return false;
    if (current->data == key)
        return true;
    return search_recursive(current->left, key) ||
           search_recursive(current->right, key);
}

template <typename T>
Node<T> *BinaryTree<T>::insert_recursive(Node<T> *node, int key, T value)
{
    if (node == nullptr)
        return new Node<T>(key, value);

    if (value < node->data)
        node->left = insert_recursive(node->left, value);
    else
        node->right = insert_recursive(node->right, value);

    return node;
}

template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <typename T>
void BinaryTree<T>::insert_node(int key, T value)
{
    root = insert_recursive(root, key, value);
}

template <typename T>
void BinaryTree<T>::delete_node(int key)
{
    root = delete_recursive(root, key);
}

template <typename T>
bool BinaryTree<T>::search(int key)
{
    return search_recursive(root, value);
}