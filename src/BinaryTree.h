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
    int key;
    T value;
    Node *left;
    Node *right;
};

template <typename T>
class BinaryTree
{
private:
    Node<T> *root;

    Node<T> *delete_recursive(Node<T> *current, int key);
    Node<T> *find_min(Node<T> *node);
    bool search_recursive(Node<T> *current, int key);
    Node<T> *insert_recursive(Node<T> *node, int key, T value);

public:
    BinaryTree() : root(nullptr);

    void insert_node(int key, T value);
    void delete_node(int key);
    bool search(int key);
};
