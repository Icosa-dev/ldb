/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <gtest/gtest.h>
#include <stdexcept>

#include "../src/Table.h"
#include "../src/Types.h"
#include "SampleGenerator.h"

template <typename T>
class TableTest : public testing::Test
{};

using LDBTypes = ::testing::Types<
    LDB::Integer,
    LDB::BigInt,
    LDB::SmallInt,
    LDB::TinyInt,
    LDB::Double,
    LDB::Float,
    LDB::Char,
    LDB::String,
    LDB::Boolean
>;

TYPED_TEST_SUITE(TableTest, LDBTypes);

TYPED_TEST(TableTest, CRUD_FullLifeCycle)
{
    auto a = SampleGenerator<TypeParam>::GetSampleA();
    auto b = SampleGenerator<TypeParam>::GetSampleB();
    uint32_t key = 999;
    EXPECT_NE(a, b);

    Table table = Table();
    table.Activate();
    EXPECT_EQ(table.IsActive(), true);

    table.Create(key, a);
    EXPECT_EQ(table.Read<TypeParam>(key), a);

    table.Update(key, b);
    EXPECT_EQ(table.Read<TypeParam>(key), b);
    EXPECT_NE(table.Read<TypeParam>(key), a);

    table.Delete<TypeParam>(key);
    EXPECT_THROW(table.Read<TypeParam>(key), std::runtime_error);

    table.Deactivate();

    EXPECT_EQ(table.IsActive(), false);
    EXPECT_THROW(table.Create(key, a), std::runtime_error);
    EXPECT_THROW(table.Update(key, a), std::runtime_error);
    EXPECT_THROW(table.Delete<TypeParam>(key), std::runtime_error);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
