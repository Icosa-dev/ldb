/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <cstdint>
#include <string>

namespace LDB
{
    // Integer types
    using Integer = int32_t;
    using BigInt = int64_t;
    using SmallInt = int16_t;
    using TinyInt = int8_t;

    // Floating-point types
    using Double = double;
    using Float = float;

    // Text types
    using Char = char;
    using String = std::string;

    // Others
    using Boolean = bool;
}