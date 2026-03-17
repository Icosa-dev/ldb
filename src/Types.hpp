#pragma once

#include <string>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/uuid/uuid.hpp>

/*
 * Type codes passed to functions which deal with Table objects.
 * NOTE: This feels very hack-y and should be re-implemented. */
enum TypeCode
{
    ASCII,
    BIGINT,
    BOOLEAN,
    DATE,
    DOUBLE,
    FLOAT,
    INET_IPV4,
    INET_IPV6,
    INTEGER,
    SMALLINT,
    TEXT,
    TIME,
    TIMESTAMP,
    TINYINT,
    UUID
};

namespace ldb
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
    typedef std::string ascii;
    typedef int64_t bigint;
    typedef uint32_t date;
    typedef uint32_t inet_ipv4;
    typedef boost::multiprecision::uint128_t inet_ipv6;
    typedef int16_t smallint;
    typedef std::string text; /* FIX: This needs to encode UTF-8 */
    typedef int64_t time;
    typedef int64_t timestamp;
    typedef int8_t tinyint;
    typedef boost::uuids::uuid uuid;
};