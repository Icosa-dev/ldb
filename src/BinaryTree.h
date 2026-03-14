/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

template <typename T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;
};

template <typename T>
class BinaryTree
{
private:
    Node<T> *root;

    Node<T> *delete_recursive(Node<T> *current, T value);
    Node<T> *find_min(Node<T> *node);
    bool search_recursive(Node<T> *current, T value);
    Node<T> *insert_recursive(Node<T> *node, T value);

public:
    BinaryTree() : root(nullptr);

    void insert_node(T value);
    void delete_node(T value);
    bool search(T value);
};
