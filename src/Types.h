#pragma once

#include <climits>
#include <cstdint>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/uuid/uuid.hpp>

// Macro to generate struct wrapper for type. This is used because 
// many data types for the database are the same underlying type but
// are stored in seperate trees and therefore the compiler
// must be able to figure out each type from each other via 
// std::is_same_v
#define GENERATE_STRONG_TYPE(typeName, underlyingType)              \
struct typeName                                                     \
{                                                                   \
    underlyingType data;                                            \
    explicit typeName(underlyingType val) : data(std::move(val)) {} \
                                                                    \
    bool operator==(const typeName& other) const                    \
    {                                                               \
        return data == other.data;                                  \
    }                                                               \
};

/* Im not sure if you can hide these structs in any way other than
 * just marking them with _ to show PLEASE DO NOT USE THESE OUTSIDE
 * OF THIS FILE.
 */
GENERATE_STRONG_TYPE(_Text, std::string);
GENERATE_STRONG_TYPE(_Date, uint32_t);
GENERATE_STRONG_TYPE(_InetIpv4, uint32_t);
GENERATE_STRONG_TYPE(_Time, int64_t);
GENERATE_STRONG_TYPE(_Timestamp, int64_t);

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
     * varchar: arbitrary-precission character (NOTE this is an alias to text)
     * varint: arbitrary-precission int
     * vector: "fixed length non-null, flattened array of float values"
     */
    using Ascii = std::string;
    using BigInt = int64_t;
    using Date = struct _Date;
    using InetIpv4 = struct _InetIpv4;
    using InetIpv6 = boost::multiprecision::uint128_t;
    using SmallInt = int16_t;
    using Text = struct _Text; 
    using Time = struct _Time;
    using Timestamp = struct _Timestamp;
    using TinyInt = int8_t;
    using Uuid = boost::uuids::uuid;
};
