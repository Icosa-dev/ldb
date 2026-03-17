/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <memory>

template <typename T>
class Node
{
public:
    int key;
    T value;
    std::unique_ptr<Node<T>> left, right;

    Node(int key, T value) : key(key), value(value) {}
};

template <typename T>
class BinaryTree
{
private:
    std::unique_ptr<Node<T>> root;

    /*
     * "Use source files for implementation" they said.
     * Oh but except for templates no those all have to be
     * implemented in the header.
     * I love this language. Oh and btw
     *
     * TODO: Write documentation for class methods.
     */
    std::unique_ptr<Node<T>> DeleteRecursive(
        std::unique_ptr<Node<T>> current, int key)
    {
        if (!current)
            return nullptr;

        if (key < current->key)
            current->left = DeleteRecursive(std::move(current->left), key);
        else if (key > current->key)
            current->right = DeleteRecursive(std::move(current->right), key);
        else
        {
            if (!current->left)
                return std::move(current->right);
            if (!current->right)
                return std::move(current->left);

            Node<T> *successor = FindMin(current->right.get());
            current->key = successor->key;
            current->value = successor->value;
            current->right = DeleteRecursive(
                std::move(current->right), successor->key);
        }
    }

    Node<T> *FindMin(Node<T> *node)
    {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    bool SearchRecursive(Node<T> *current, int key)
    {
        if (current == nullptr)
            return false;
        if (current->data == key)
            return true;
        return SearchRecursive(current->left, key) ||
               SearchRecursive(current->right, key);
    }

    std::unique_ptr<Node<T>> InsertRecursive(std::unique_ptr<Node<T>> node,
                                             int key, T value)
    {
        if (node == nullptr)
            return std::make_unique<Node<T>>(key, value);

        if (value < node->data)
            node->left = InsertRecursive(node->left, key);
        else
            node->right = InsertRecursive(node->right, key);

        return node;
    }

public:
    BinaryTree() : root(nullptr) {}

    void InsertNode(int key, T value)
    {
        root = InsertRecursive(root, key, value);
    }

    void DeleteNode(int key)
    {
        root = DeleteRecursive(root, key);
    }

    bool Search(int key)
    {
        return SearchRecursive(root, value);
    }
};
