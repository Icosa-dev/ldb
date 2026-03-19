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
    BinaryTree<LDB::SmallInt> smallntTree;
    BinaryTree<LDB::Text> textTree;
    BinaryTree<LDB::Time> timeTree;
    BinaryTree<LDB::Timestamp> timestampTree;
    BinaryTree<LDB::TinyInt> tinyIntTree;
    BinaryTree<LDB::Uuid> uuidTree;

    template <typename T>
    BinaryTree<T> GetCurrentTree(TypeCode type)
    {
        switch (type)
        {
        case ASCII:
            return asciiTree;
        case BIGINT:
            return bigintTree;
        case BOOLEAN:
            return booleanTree;
        case DATE:
            return dateTree;
        case DOUBLE:
            return doubleTree;
        case FLOAT:
            return floatTree;
        case INET_IPV4:
            return inetIpv4Tree;
        case INET_IPV6:
            return inetIpv6Tree;
        case INTEGER:
            return integerTree;
        case SMALLINT:
            return smallIntTree;
        case TEXT:
            return textTree;
        case TIME:
            return timeTree;
        case TIMESTAMP:
            return timestampTree;
        case TINYINT:
            return tinyIntTree;
        case UUID:
            return uuidTree;
        default:
            return nullptr;
        }
    }

public:
    Table() {}

    /* CRUD operations on table */
    template <typename T>
    void Create(int key, T value, TypeCode type)
    {
        BinaryTree<T> currentTree = GetCurrentTree<T>(type);

        if (!currentTree.Search(key))
            currentTree.InsertNode(key, value)
    }

    template <typename T>
    T Read(int key, TypeCode)
    {
        BinaryTree<T> currentTree = GetCurrentTree<T>(type);

        return currentTree.GetNode(key)->value;
    }

    template <typename T>
    void Update(int key, T value, TypeCode type)
    {
        BinaryTree<T> currentTree = GetCurrentTree<T>(type);

        if (currentTree.Search(key))
            currentTree.GetNode(key)->value = value;
    }

    template <typename T>
    void Delete(int key, TypeCode type)
    {
        BinaryTree<T> currentTree = GetCurrentTree<T>(type);

        currentTree.DeleteNode(key);
    }
};