/*
 * Copyright (c) 2026 LJC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include "../src/Types.h"

template <typename T>
struct SampleGenerator
{
    static T GetSampleA() { return T(); }
    static T GetSampleB() { return T(); }
};

#define DEFINE_SAMPLE_GENERATOR(type, sampleA, sampleB)     \
template <>                                                 \
struct SampleGenerator<type>                                \
{                                                           \
    static type GetSampleA() { return sampleA; }            \
    static type GetSampleB() { return sampleB; }            \
}

// There is probably a way to generate sample generators for
// similar types. Maybe change this later accordingly.
DEFINE_SAMPLE_GENERATOR(LDB::Integer, 1, 2);
DEFINE_SAMPLE_GENERATOR(LDB::BigInt, 1, 2);
DEFINE_SAMPLE_GENERATOR(LDB::SmallInt, 1, 2);
DEFINE_SAMPLE_GENERATOR(LDB::TinyInt, 1, 2);

DEFINE_SAMPLE_GENERATOR(LDB::Double, 1.2, 2.2);
DEFINE_SAMPLE_GENERATOR(LDB::Float, 1.2f, 2.2f);

DEFINE_SAMPLE_GENERATOR(LDB::Char, 'a', 'b');
DEFINE_SAMPLE_GENERATOR(LDB::String, "ALFA", "BRAVO");

DEFINE_SAMPLE_GENERATOR(LDB::Boolean, true, false);
