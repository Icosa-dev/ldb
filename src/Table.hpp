/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <string>

#include "BinaryTree.hpp"
#include "Types.hpp"

class Table
{
private:
    BinaryTree<LDB::Ascii> asciiTree;
    BinaryTree<LDB::BigInt> bigintTree;
    BinaryTree<bool> booleanTree;
    BinaryTree<LDB::Date> dateTree;
    BinaryTree<double> doubleTree;
    BinaryTree<float> floatTree;
    BinaryTree<LDB::InetIpv4> inetIpv4Tree;
    BinaryTree<LDB::InetIpv4> inetIpv6Tree;
    BinaryTree<int32_t> integerTree;
    BinaryTree<LDB::SmallInt> smallintTree;
    BinaryTree<LDB::Text> textTree;
    BinaryTree<LDB::Time> timeTree;
    BinaryTree<LDB::Timestamp> timestampTree;
    BinaryTree<LDB::TinyInt> tinyintTree;
    BinaryTree<LDB::Uuid> uuidTree;

    template <typename T>
    BinaryTree<T> GetCurrentType(TypeCode type);

public:
    Table();

    /* CRUD operations on table */
    template <typename T>
    void Create(int key, T value, TypeCode type);

    template <typename T>
    T Read(int key, TypeCode);

    template <typename T>
    void Update(int key, T value, TypeCode type);

    template <typename T>
    void Delete(int key, TypeCode type);
};