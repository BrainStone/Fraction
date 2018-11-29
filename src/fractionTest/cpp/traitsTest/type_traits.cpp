//
// Copyright (c) 2018 Yannick Schinko
// Licensed under the MIT License. See LICENSE file in the project root for full license information.
//
#include <gtest/gtest.h>

#include "defines.hpp"

#define TEST_CASE_NAME type_traitsTest

TEST( TEST_CASE_NAME, is_fraction ) {
	EXPECT_TRUE( is_fraction<fraction_t>::value );
	EXPECT_TRUE( is_fraction<ufraction_t>::value );

	EXPECT_FALSE( is_fraction<void>::value );
	EXPECT_FALSE( is_fraction<std::string>::value );


	EXPECT_TRUE( is_fraction_v<fraction_t> );
	EXPECT_TRUE( is_fraction_v<ufraction_t> );

	EXPECT_FALSE( is_fraction_v<void> );
	EXPECT_FALSE( is_fraction_v<std::string> );
}

TEST( TEST_CASE_NAME, is_floating_point ) {
	EXPECT_TRUE( std::is_floating_point<fraction_t>::value );
	EXPECT_TRUE( std::is_floating_point<ufraction_t>::value );
}

TEST( TEST_CASE_NAME, is_integral ) {
	EXPECT_FALSE( std::is_integral<fraction_t>::value );
	EXPECT_FALSE( std::is_integral<ufraction_t>::value );
}

TEST( TEST_CASE_NAME, is_arithmetic ) {
	EXPECT_TRUE( std::is_arithmetic<fraction_t>::value );
	EXPECT_TRUE( std::is_arithmetic<ufraction_t>::value );
}

TEST( TEST_CASE_NAME, is_signed ) {
	EXPECT_TRUE( std::is_signed<fraction_t>::value );
	EXPECT_FALSE( std::is_signed<ufraction_t>::value );
}

TEST( TEST_CASE_NAME, is_unsigned ) {
	EXPECT_FALSE( std::is_unsigned<fraction_t>::value );
	EXPECT_TRUE( std::is_unsigned<ufraction_t>::value );
}

TEST( TEST_CASE_NAME, common_type ) {
	constexpr bool signed_fraction { std::is_same<fraction_t, std::common_type<fraction_t, fraction32_t>::type>::value };
	constexpr bool unsigned_fraction { std::is_same<ufraction_t, std::common_type<ufraction_t, ufraction32_t>::type>::value };

	EXPECT_TRUE( signed_fraction );
	EXPECT_TRUE( unsigned_fraction );
}
