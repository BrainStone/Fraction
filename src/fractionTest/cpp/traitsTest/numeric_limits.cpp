//
// Copyright (c) 2018 Yannick Schinko
// Licensed under the MIT License. See LICENSE file in the project root for full license information.
//
#include <gtest/gtest.h>

#include "defines.hpp"

#define TEST_CASE_NAME numeric_limitsTest

TEST( TEST_CASE_NAME, is_specialized ) {
	EXPECT_TRUE( std::numeric_limits<fraction_t>::is_specialized );
	EXPECT_TRUE( std::numeric_limits<ufraction_t>::is_specialized );
	EXPECT_TRUE( std::numeric_limits<fraction32_t>::is_specialized );
	EXPECT_TRUE( std::numeric_limits<ufraction32_t>::is_specialized );
}

TEST( TEST_CASE_NAME, min ) {
	EXPECT_EQ( fraction_t { std::numeric_limits<std::int64_t>::min() }, std::numeric_limits<fraction_t>::min() );
	EXPECT_EQ( ufraction_t { std::numeric_limits<std::uint64_t>::min() }, std::numeric_limits<ufraction_t>::min() );
	EXPECT_EQ( fraction32_t { std::numeric_limits<std::int32_t>::min() }, std::numeric_limits<fraction32_t>::min() );
	EXPECT_EQ( ufraction32_t { std::numeric_limits<std::uint32_t>::min() }, std::numeric_limits<ufraction32_t>::min() );
}

TEST( TEST_CASE_NAME, max ) {
	EXPECT_EQ( fraction_t { std::numeric_limits<std::int64_t>::max() }, std::numeric_limits<fraction_t>::max() );
	EXPECT_EQ( ufraction_t { std::numeric_limits<std::uint64_t>::max() }, std::numeric_limits<ufraction_t>::max() );
	EXPECT_EQ( fraction32_t { std::numeric_limits<std::int32_t>::max() }, std::numeric_limits<fraction32_t>::max() );
	EXPECT_EQ( ufraction32_t { std::numeric_limits<std::uint32_t>::max() }, std::numeric_limits<ufraction32_t>::max() );
}

TEST( TEST_CASE_NAME, lowest ) {
	EXPECT_EQ( std::numeric_limits<fraction_t>::min(), std::numeric_limits<fraction_t>::lowest() );
	EXPECT_EQ( std::numeric_limits<ufraction_t>::min(), std::numeric_limits<ufraction_t>::lowest() );
	EXPECT_EQ( std::numeric_limits<fraction32_t>::min(), std::numeric_limits<fraction32_t>::lowest() );
	EXPECT_EQ( std::numeric_limits<ufraction32_t>::min(), std::numeric_limits<ufraction32_t>::lowest() );
}

TEST( TEST_CASE_NAME, is_signed ) {
	EXPECT_TRUE( std::numeric_limits<fraction_t>::is_signed );
	EXPECT_FALSE( std::numeric_limits<ufraction_t>::is_signed );
	EXPECT_TRUE( std::numeric_limits<fraction32_t>::is_signed );
	EXPECT_FALSE( std::numeric_limits<ufraction32_t>::is_signed );
}

TEST( TEST_CASE_NAME, is_integer ) {
	EXPECT_FALSE( std::numeric_limits<fraction_t>::is_integer );
	EXPECT_FALSE( std::numeric_limits<ufraction_t>::is_integer );
	EXPECT_FALSE( std::numeric_limits<fraction32_t>::is_integer );
	EXPECT_FALSE( std::numeric_limits<ufraction32_t>::is_integer );
}

TEST( TEST_CASE_NAME, is_exact ) {
	EXPECT_TRUE( std::numeric_limits<fraction_t>::is_exact );
	EXPECT_TRUE( std::numeric_limits<ufraction_t>::is_exact );
	EXPECT_TRUE( std::numeric_limits<fraction32_t>::is_exact );
	EXPECT_TRUE( std::numeric_limits<ufraction32_t>::is_exact );
}

TEST( TEST_CASE_NAME, radix ) {
	EXPECT_EQ( 2, std::numeric_limits<fraction_t>::radix );
	EXPECT_EQ( 2, std::numeric_limits<ufraction_t>::radix );
	EXPECT_EQ( 2, std::numeric_limits<fraction32_t>::radix );
	EXPECT_EQ( 2, std::numeric_limits<ufraction32_t>::radix );
}

TEST( TEST_CASE_NAME, epsilon ) {
	EXPECT_EQ( fraction_t ( 1, std::numeric_limits<std::int64_t>::max() ), std::numeric_limits<fraction_t>::epsilon() );
	EXPECT_EQ( ufraction_t ( 1, std::numeric_limits<std::uint64_t>::max() ), std::numeric_limits<ufraction_t>::epsilon() );
	EXPECT_EQ( fraction32_t ( 1, std::numeric_limits<std::int32_t>::max() ), std::numeric_limits<fraction32_t>::epsilon() );
	EXPECT_EQ( ufraction32_t ( 1, std::numeric_limits<std::uint32_t>::max() ), std::numeric_limits<ufraction32_t>::epsilon() );
}

TEST( TEST_CASE_NAME, round_error ) {
	EXPECT_EQ( std::numeric_limits<fraction_t>::epsilon(), std::numeric_limits<fraction_t>::round_error() );
	EXPECT_EQ( std::numeric_limits<ufraction_t>::epsilon(), std::numeric_limits<ufraction_t>::round_error() );
	EXPECT_EQ( std::numeric_limits<fraction32_t>::epsilon(), std::numeric_limits<fraction32_t>::round_error() );
	EXPECT_EQ( std::numeric_limits<ufraction32_t>::epsilon(), std::numeric_limits<ufraction32_t>::round_error() );
}

TEST( TEST_CASE_NAME, has_denorm ) {
	EXPECT_EQ( std::denorm_absent, std::numeric_limits<fraction_t>::has_denorm );
	EXPECT_EQ( std::denorm_absent, std::numeric_limits<ufraction_t>::has_denorm );
	EXPECT_EQ( std::denorm_absent, std::numeric_limits<fraction32_t>::has_denorm );
	EXPECT_EQ( std::denorm_absent, std::numeric_limits<ufraction32_t>::has_denorm );
}

TEST( TEST_CASE_NAME, is_bounded ) {
	EXPECT_TRUE( std::numeric_limits<fraction_t>::is_bounded );
	EXPECT_TRUE( std::numeric_limits<ufraction_t>::is_bounded );
	EXPECT_TRUE( std::numeric_limits<fraction32_t>::is_bounded );
	EXPECT_TRUE( std::numeric_limits<ufraction32_t>::is_bounded );
}

TEST( TEST_CASE_NAME, is_modulo ) {
	EXPECT_EQ( std::numeric_limits<std::int64_t>::is_modulo, std::numeric_limits<fraction_t>::is_modulo );
	EXPECT_EQ( std::numeric_limits<std::uint64_t>::is_modulo, std::numeric_limits<ufraction_t>::is_modulo );
	EXPECT_EQ( std::numeric_limits<std::int32_t>::is_modulo, std::numeric_limits<fraction32_t>::is_modulo );
	EXPECT_EQ( std::numeric_limits<std::uint32_t>::is_modulo, std::numeric_limits<ufraction32_t>::is_modulo );
}

TEST( TEST_CASE_NAME, round_style ) {
	EXPECT_EQ( std::round_to_nearest, std::numeric_limits<fraction_t>::round_style );
	EXPECT_EQ( std::round_to_nearest, std::numeric_limits<ufraction_t>::round_style );
	EXPECT_EQ( std::round_to_nearest, std::numeric_limits<fraction32_t>::round_style );
	EXPECT_EQ( std::round_to_nearest, std::numeric_limits<ufraction32_t>::round_style );
}
