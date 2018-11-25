//
// Copyright (c) 2018 Yannick Schinko
// Licensed under the MIT License. See LICENSE file in the project root for full license information.
//
#include <gtest/gtest.h>

#include "fraction.hpp"

#define TEST_CASE_NAME ConstexprTest_uint64_t

using fraction_t = fraction<std::uint64_t>;

TEST( TEST_CASE_NAME, reduction ) {
	constexpr fraction_t val1 { 4, 2 };
	constexpr fraction_t val2 { 498, 846 };
	constexpr fraction_t val3 { 343278, 43653465 };
	constexpr fraction_t val4 { 0, 123 };

	EXPECT_EQ( 2, val1.getNumerator() );
	EXPECT_EQ( 1, val1.getDenominator() );
	EXPECT_EQ( 83, val2.getNumerator() );
	EXPECT_EQ( 141, val2.getDenominator() );
	EXPECT_EQ( 12714, val3.getNumerator() );
	EXPECT_EQ( 1616795, val3.getDenominator() );
	EXPECT_EQ( 0, val4.getNumerator() );
	EXPECT_EQ( 1, val4.getDenominator() );
}

TEST( TEST_CASE_NAME, reductionEquals ) {
	constexpr fraction_t val1 { 4, 2 };
	constexpr fraction_t val2 { 498, 846 };
	constexpr fraction_t val3 { 343278, 43653465 };
	constexpr fraction_t val4 { 0, 123 };

	constexpr fraction_t val1Reduced { 2, 1 };
	constexpr fraction_t val2Reduced { 83, 141 };
	constexpr fraction_t val3Reduced { 12714, 1616795 };
	constexpr fraction_t val4Reduced { 0, 1 };

	EXPECT_EQ( val1Reduced, val1 );
	EXPECT_NE( val2Reduced, val1 );
	EXPECT_NE( val3Reduced, val1 );
	EXPECT_NE( val4Reduced, val1 );
	EXPECT_NE( val1Reduced, val2 );
	EXPECT_EQ( val2Reduced, val2 );
	EXPECT_NE( val3Reduced, val2 );
	EXPECT_NE( val4Reduced, val2 );
	EXPECT_NE( val1Reduced, val3 );
	EXPECT_NE( val2Reduced, val3 );
	EXPECT_EQ( val3Reduced, val3 );
	EXPECT_NE( val4Reduced, val3 );
	EXPECT_NE( val1Reduced, val4 );
	EXPECT_NE( val2Reduced, val4 );
	EXPECT_NE( val3Reduced, val4 );
	EXPECT_EQ( val4Reduced, val4 );
}
