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
    BinaryTree<ldb::ascii> asciiTree;
    BinaryTree<ldb::bigint> bigintTree;
    BinaryTree<bool> booleanTree;
    BinaryTree<ldb::date> dateTree;
    BinaryTree<double> doubleTree;
    BinaryTree<float> floatTree;
    BinaryTree<ldb::inet_ipv4> inetIpv4Tree;
    BinaryTree<ldb::inet_ipv6> inetIpv6Tree;
    BinaryTree<int32_t> integerTree;
    BinaryTree<ldb::smallint> smallintTree;
    BinaryTree<ldb::text> textTree;
    BinaryTree<ldb::time> timeTree;
    BinaryTree<ldb::timestamp> timestampTree;
    BinaryTree<ldb::tinyint> tinyintTree;
    BinaryTree<ldb::uuid> uuidTree;

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