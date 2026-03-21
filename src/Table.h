/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <tuple>
#include <stdexcept>

#include "Types.h"
#include "BinaryTree.h"

class Table
{
private:
    using Trees = std::tuple<
        BinaryTree<LDB::Integer>,
        BinaryTree<LDB::BigInt>,
        BinaryTree<LDB::SmallInt>,
        BinaryTree<LDB::TinyInt>,
        BinaryTree<LDB::Double>,
        BinaryTree<LDB::Float>,
        BinaryTree<LDB::Char>,
        BinaryTree<LDB::String>,
        BinaryTree<LDB::Boolean>
    >;

    Trees trees;
    bool isActive = false; // tables are inactive by default
public:
    Table() {}

    template <typename T>
    void Create(uint32_t key, T value)
    {
        if (!isActive) throw std::runtime_error("Table is inactive");

        BinaryTree<T> &currentTree = std::get<BinaryTree<T>>(trees);

        if (!currentTree.GetNode(key))
            currentTree.InsertNode(key, value);
    }

    template <typename T>
    T Read(uint32_t key)
    {
        BinaryTree<T> &currentTree = std::get<BinaryTree<T>>(trees);
        Node<T> *node = currentTree.GetNode(key);

        if (node) return node->value;
        else throw std::runtime_error("Could not get value from key: " + std::to_string(key));
    }


    template <typename T>
    void Update(uint32_t key, T value)
    {
        if (!isActive) throw std::runtime_error("Table is inactive");

        BinaryTree<T> &currentTree = std::get<BinaryTree<T>>(trees);
        Node<T> *node = currentTree.GetNode(key);

        if (!node) return;
        node->value = value;
    }

    template <typename T>
    void Delete(uint32_t key)
    {
        if (!isActive) throw std::runtime_error("Table is inactive");

        BinaryTree<T> &currentTree = std::get<BinaryTree<T>>(trees);
        
        if (currentTree.GetNode(key))
            currentTree.DeleteNode(key);
    }

    void Activate()
    {
        isActive = true;
    }

    void Deactivate()
    {
        isActive = false;
    }

    bool IsActive()
    {
        return isActive;
    }
};
