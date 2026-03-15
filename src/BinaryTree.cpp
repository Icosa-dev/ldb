/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "BinaryTree.h"

#include <memory>

template <typename T>
Node<T>::Node(int key, T value) {}

template <typename T>
std::unique_ptr<Node<T>> BinaryTree<T>::delete_recursive(
    std::unique_ptr<Node<T>> current, int key)
{
    if (!current)
        return nullptr;

    if (key < current->key)
        current->left = delete_recursive(std::move(current->left), key);
    else if (key < current->key)
        current->right = delete_recursive(std::move(current->right), key);
    else
    {
        if (!current->left)
            return std::move(current->right);
        if (!current->right)
            return std::move(current->left);

        Node<T> *successor = find_min(current->right.get());
        current->key = successor->key;
        current->value = successor->value;
        current->right = delete_recursive(
            std::move(current->right), successor->key);
    }
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
std::unique_ptr<Node<T>> BinaryTree<T>::insert_recursive(
    std::unique_ptr<Node<T>> node, int key, T value)
{
    if (node == nullptr)
        return std::make_unique<Node<T>>(key, value);

    if (value < node->data)
        node->left = insert_recursive(node->left, key);
    else
        node->right = insert_recursive(node->right, key);

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