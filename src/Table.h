/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <string>

#include "BinaryTree.h"
#include "Types.h"

class Table
{
private:
    BinaryTree<LDB::Ascii> asciiTree;
    BinaryTree<LDB::BigInt> bigIntTree;
    BinaryTree<bool> booleanTree;
    BinaryTree<LDB::Date> dateTree;
    BinaryTree<double> doubleTree;
    BinaryTree<float> floatTree;
    BinaryTree<LDB::InetIpv4> inetIpv4Tree;
    BinaryTree<LDB::InetIpv4> inetIpv6Tree;
    BinaryTree<int32_t> integerTree;
    BinaryTree<LDB::SmallInt> smallIntTree;
    BinaryTree<LDB::Text> textTree;
    BinaryTree<LDB::Time> timeTree;
    BinaryTree<LDB::Timestamp> timestampTree;
    BinaryTree<LDB::TinyInt> tinyIntTree;
    BinaryTree<LDB::Uuid> uuidTree;

    template <typename T>
    BinaryTree<T> &GetTree()
    {
        if constexpr (std::is_same_v<T, LDB::Ascii>)
            return asciiTree;
        else if constexpr (std::is_same_v<T, LDB::BigInt>)
            return bigIntTree;
        else if constexpr (std::is_same_v<T, bool>)
            return booleanTree;
        else if constexpr (std::is_same_v<T, LDB::Date>)
            return dateTree;
        else if constexpr (std::is_same_v<T, double>)
            return doubleTree;
        else if constexpr (std::is_same_v<T, float>)
            return floatTree;
        else if constexpr (std::is_same_v<T, LDB::InetIpv4>)
            return inetIpv4Tree;
        else if constexpr (std::is_same_v<T, LDB::InetIpv6>)
            return inetIpv6Tree;
        else if constexpr (std::is_same_v<T, int32_t>)
            return integerTree;
        else if constexpr (std::is_same_v<T, LDB::SmallInt>)
            return smallIntTree;
        else if constexpr (std::is_same_v<T, LDB::Text>)
            return textTree;
        else if constexpr (std::is_same_v<T, LDB::Time>)
            return timeTree;
        else if constexpr (std::is_same_v<T, LDB::Timestamp>)
            return timestampTree;
        else if constexpr (std::is_same_v<T, LDB::TinyInt>)
            return tinyIntTree;
        else if constexpr (std::is_same_v<T, LDB::Uuid>)
            return uuidTree;
        else
            static_assert(false, "Unsupported type for Table");
    }

public:
    Table() {}

    /* CRUD operations on table */
    template <typename T>
    void Create(int key, T value)
    {
        auto& currentTree = GetCurrentTree<T>();

        if (!currentTree.Search(key))
            currentTree.InsertNode(key, value);
    }

    template <typename T>
    T Read(int key)
    {
        auto& currentTree = GetCurrentTree<T>()

        return currentTree.GetNode(key)->value;
    }

    template <typename T>
    void Update(int key, T value)
    {
        auto& currentTree = GetCurrentTree<T>()

        if (currentTree.Search(key))
            currentTree.GetNode(key)->value = value;
    }

    template <typename T>
    void Delete(int key)
    {
        auto& currentTree = GetCurrentTree<T>()

        currentTree.DeleteNode(key);
    }
};