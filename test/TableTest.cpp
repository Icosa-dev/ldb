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

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}