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

    Node(int key, T value) : key(key), value(value);
};

template <typename T>
class BinaryTree
{
private:
    std::unique_ptr<Node<T>> root;

    std::unique_ptr<Node<T>> delete_recursive(
        std::unique_ptr<Node<T>> current, int key);

    Node<T> *find_min(Node<T> *node);

    bool search_recursive(Node<T> *current, int key);

    std::unique_ptr<Node<T>> insert_recursive(std::unique_ptr<Node<T>> node,
                                              int key, T value);

public:
    BinaryTree() : root(nullptr);

    void insert_node(int key, T value);

    void delete_node(int key);

    bool search(int key);
};
