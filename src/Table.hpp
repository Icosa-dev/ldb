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
    BinaryTree<ldb::ascii> ascii_tree;
    BinaryTree<ldb::bigint> bigint_tree;
    BinaryTree<bool> boolean_tree;
    BinaryTree<ldb::date> date_tree;
    BinaryTree<double> double_tree;
    BinaryTree<float> float_tree;
    BinaryTree<ldb::inet_ipv4> inet_ipv4_tree;
    BinaryTree<ldb::inet_ipv6> inet_ipv6_tree;
    BinaryTree<int32_t> integer_tree;
    BinaryTree<ldb::smallint> smallint_tree;
    BinaryTree<ldb::text> text_tree;
    BinaryTree<ldb::time> time_tree;
    BinaryTree<ldb::timestamp> timestamp_tree;
    BinaryTree<ldb::tinyint> tinyint_tree;
    BinaryTree<ldb::uuid> uuid_tree;

public:
    Table();
};