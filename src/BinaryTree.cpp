/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "BinaryTree.h"

template <typename T>
Node<T> *BinaryTree<T>::delete_recursive(Node<T> *current, T value)
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
bool BinaryTree<T>::search_recursive(Node<T> *current, T value)
{
    if (current == nullptr)
        return false;
    if (current->data == value)
        return true;
    return search_recursive(current->left, value) ||
           search_recursive(current->right, value);
}

template <typename T>
Node<T> *BinaryTree<T>::insert_recursive(Node<T> *node, T value)
{
    if (node == nullptr)
        return new Node<T>(value);

    if (value < node->data)
        node->left = insert_recursive(node->left, value);
    else
        node->right = insert_recursive(node->right, value);

    return node;
}

template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <typename T>
void BinaryTree<T>::insert_node(T value)
{
    root = insert_recursive(root, value);
}

template <typename T>
void BinaryTree<T>::delete_node(T value)
{
    root = delete_recursive(root, value);
}

template <typename T>
bool BinaryTree<T>::search(T value)
{
    return search_recursive(root, value);
}