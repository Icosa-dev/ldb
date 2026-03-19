/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "../src/Table.h"

#include <string>

#include <gtest/gtest.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

template <typename T>
struct ValueGenerator
{
    static T GetSampleA() { return T(); } // Default
    static T GetSampleB() { return T(); } // Needs specialization
};

template <>
struct ValueGenerator<int>
{
    static int GetSampleA() { return 100; }
    static int GetSampleB() { return 200; }
};

template <>
struct ValueGenerator<LDB::Uuid>
{
    static LDB::Uuid GetSampleA() { return boost::uuids::random_generator()(); }
    static LDB::Uuid GetSampleB() { return boost::uuids::random_generator()(); }
};

template <typename T>
class LDBTableTest : public ::testing::Test
{
protected:
    void SetUp() override {}
};

using LDBTestTypes = ::testing::Types<
    LDB::Ascii, LDB::BigInt, bool, LDB::Date, double,
    float, LDB::InetIpv4, LDB::InetIpv6, int,
    LDB::SmallInt, LDB::Text, LDB::Time, LDB::Timestamp,
    LDB::TinyInt, LDB::Uuid>;
TYPED_TEST_SUITE(LDBTableTest, LDBTestTypes);

TYPED_TEST(LDBTableTest, FullLifeCycle)
{
    using T = TypeParam;
    int key = 999;
    LDB::Type typeEnum = this->GetLdbType();

    // TODO: make value generator
    T initialValue = ValueGenerator<T>::GetSampleA();
    testTable.Create<T>(key, initialValue, typeEnum);

    EXPECT_EQ(testTable.Read<T>(key, enum), initialValue);

    T newValue = ValueGenerator<T>::GetSampleB();
    testTable.Update<T>(key, newValue, typeEnum);

    EXPECT_EQ(testTable.Read<T>(key, typeEnum), newValue);
    EXPECT_NE(testTable.Read<T>(key, typeEnum), initialValue);

    testTable.Delete(key, typeEnum);

    EXPECT_ANY_THROW(testTable.Read<T>(key, typeEnum));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}