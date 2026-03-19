#pragma once

#include <string>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/uuid/uuid.hpp>

namespace LDB
{
    /*
     * Types are derived from Apache Cassandra's types. However a few
     * types are excluded, to be possibly added in a later version.
     *
     * Excluded types (not including types that already exist
     * in C++ as is such as `double` or `float`):
     *
     * blob: arbitrary bytes
     * counter: 64-bit signed counter column
     * decimal: variable-precission decimal
     * duration: 3 variable-precission signed integers
     * varchar: arbitrary-precission character
     * varint: arbitrary-precission int
     * vector: "fixed length non-null, flattened array of float values"
     */
    using Ascii = std::string;
    using BigInt = int64_t;
    using Date = uint32_t;
    using InetIpv4 = uint32_t;
    using InetIpv6 = boost::multiprecision::uint128_t;
    using SmallInt = int16_t;
    using Text = std::string; /* FIX: This needs to encode UTF-8 */
    using Time = int64_t;
    using Timestamp = int64_t;
    using TinyInt = int8_t;
    using Uuid = boost::uuids::uuid;
};