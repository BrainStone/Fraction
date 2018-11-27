//
// Copyright (c) 2018 Yannick Schinko
// Licensed under the MIT License. See LICENSE file in the project root for full license information.
//
#include <gtest/gtest.h>

#include "fraction.hpp"

#define TEST_CASE_NAME ConstexprTest_uint64_t

using fraction_t = fraction<std::uint64_t>;

TEST( TEST_CASE_NAME, zeroExcpetion ) {
	EXPECT_THROW( fraction_t( 0, 0 ), std::invalid_argument );
}

TEST( TEST_CASE_NAME, equals ) {
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { 83, 141 };
	constexpr fraction_t val3Expected { 12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1Actual { 2, 1 };
	constexpr fraction_t val2Actual { 83, 141 };
	constexpr fraction_t val3Actual { 12714, 1616795 };
	constexpr fraction_t val4Actual { 0, 1 };

	EXPECT_EQ( val1Expected, val1Actual );
	EXPECT_NE( val2Expected, val1Actual );
	EXPECT_NE( val3Expected, val1Actual );
	EXPECT_NE( val4Expected, val1Actual );
	EXPECT_NE( val1Expected, val2Actual );
	EXPECT_EQ( val2Expected, val2Actual );
	EXPECT_NE( val3Expected, val2Actual );
	EXPECT_NE( val4Expected, val2Actual );
	EXPECT_NE( val1Expected, val3Actual );
	EXPECT_NE( val2Expected, val3Actual );
	EXPECT_EQ( val3Expected, val3Actual );
	EXPECT_NE( val4Expected, val3Actual );
	EXPECT_NE( val1Expected, val4Actual );
	EXPECT_NE( val2Expected, val4Actual );
	EXPECT_NE( val3Expected, val4Actual );
	EXPECT_EQ( val4Expected, val4Actual );
}

TEST( TEST_CASE_NAME, differentFractionTypeEquals ) {
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { 83, 141 };
	constexpr fraction_t val3Expected { 12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction<std::uint32_t> val1Actual { 2, 1 };
	constexpr fraction<std::uint32_t> val2Actual { 83, 141 };
	constexpr fraction<std::uint32_t> val3Actual { 12714, 1616795 };
	constexpr fraction<std::uint32_t> val4Actual { 0, 1 };

	EXPECT_EQ( val1Expected, val1Actual );
	EXPECT_NE( val2Expected, val1Actual );
	EXPECT_NE( val3Expected, val1Actual );
	EXPECT_NE( val4Expected, val1Actual );
	EXPECT_NE( val1Expected, val2Actual );
	EXPECT_EQ( val2Expected, val2Actual );
	EXPECT_NE( val3Expected, val2Actual );
	EXPECT_NE( val4Expected, val2Actual );
	EXPECT_NE( val1Expected, val3Actual );
	EXPECT_NE( val2Expected, val3Actual );
	EXPECT_EQ( val3Expected, val3Actual );
	EXPECT_NE( val4Expected, val3Actual );
	EXPECT_NE( val1Expected, val4Actual );
	EXPECT_NE( val2Expected, val4Actual );
	EXPECT_NE( val3Expected, val4Actual );
	EXPECT_EQ( val4Expected, val4Actual );
}

TEST( TEST_CASE_NAME, differentTypeEquals ) {
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { 83, 141 };
	constexpr fraction_t val3Expected { 12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr std::uint64_t val1Actual { 2 };
	constexpr double val2Actual { 0.588652482269503546099290780141843971 };
	constexpr double val3Actual { 0.007863705664601882118635943332333412 };
	constexpr std::uint64_t val4Actual { 0 };

	EXPECT_EQ( val1Expected, val1Actual );
	EXPECT_NE( val2Expected, val1Actual );
	EXPECT_NE( val3Expected, val1Actual );
	EXPECT_NE( val4Expected, val1Actual );
	EXPECT_NE( val1Expected, val2Actual );
	EXPECT_EQ( val2Expected, val2Actual );
	EXPECT_NE( val3Expected, val2Actual );
	EXPECT_NE( val4Expected, val2Actual );
	EXPECT_NE( val1Expected, val3Actual );
	EXPECT_NE( val2Expected, val3Actual );
	EXPECT_EQ( val3Expected, val3Actual );
	EXPECT_NE( val4Expected, val3Actual );
	EXPECT_NE( val1Expected, val4Actual );
	EXPECT_NE( val2Expected, val4Actual );
	EXPECT_NE( val3Expected, val4Actual );
	EXPECT_EQ( val4Expected, val4Actual );

	EXPECT_EQ( val1Actual, val1Expected );
	EXPECT_NE( val1Actual, val2Expected );
	EXPECT_NE( val1Actual, val3Expected );
	EXPECT_NE( val1Actual, val4Expected );
	EXPECT_NE( val2Actual, val1Expected );
	EXPECT_EQ( val2Actual, val2Expected );
	EXPECT_NE( val2Actual, val3Expected );
	EXPECT_NE( val2Actual, val4Expected );
	EXPECT_NE( val3Actual, val1Expected );
	EXPECT_NE( val3Actual, val2Expected );
	EXPECT_EQ( val3Actual, val3Expected );
	EXPECT_NE( val3Actual, val4Expected );
	EXPECT_NE( val4Actual, val1Expected );
	EXPECT_NE( val4Actual, val2Expected );
	EXPECT_NE( val4Actual, val3Expected );
	EXPECT_EQ( val4Actual, val4Expected );
}

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

TEST( TEST_CASE_NAME, floatingPointConstructor ) {
	constexpr fraction_t val1 { 2.0 };
	constexpr fraction_t val2 { 0.588652482269503546099290780141843971 };
	constexpr fraction_t val3 { 0.007863705664601882118635943332333412 };
	constexpr fraction_t val4 { 0.0 };

	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { 83, 141 };
	constexpr fraction_t val3Expected { 12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	EXPECT_EQ( val1Expected, val1 );
	EXPECT_NE( val2Expected, val1 );
	EXPECT_NE( val3Expected, val1 );
	EXPECT_NE( val4Expected, val1 );
	EXPECT_NE( val1Expected, val2 );
	EXPECT_EQ( val2Expected, val2 );
	EXPECT_NE( val3Expected, val2 );
	EXPECT_NE( val4Expected, val2 );
	EXPECT_NE( val1Expected, val3 );
	EXPECT_NE( val2Expected, val3 );
	EXPECT_EQ( val3Expected, val3 );
	EXPECT_NE( val4Expected, val3 );
	EXPECT_NE( val1Expected, val4 );
	EXPECT_NE( val2Expected, val4 );
	EXPECT_NE( val3Expected, val4 );
	EXPECT_EQ( val4Expected, val4 );
}

TEST( TEST_CASE_NAME, negativeFloatingPointConstructor ) {
	EXPECT_THROW( fraction_t( -1.0 ), std::invalid_argument );
}

TEST( TEST_CASE_NAME, differentTypeCopyConstructor ) {
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { 83, 141 };
	constexpr fraction_t val3Expected { 12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction<std::uint32_t> val1Actual_uint32_t { 2, 1 };
	constexpr fraction<std::uint32_t> val2Actual_uint32_t { 83, 141 };
	constexpr fraction<std::uint32_t> val3Actual_uint32_t { 12714, 1616795 };
	constexpr fraction<std::uint32_t> val4Actual_uint32_t { 0, 1 };

	constexpr fraction_t val1Actual { val1Actual_uint32_t };
	constexpr fraction_t val2Actual { val2Actual_uint32_t };
	constexpr fraction_t val3Actual { val3Actual_uint32_t };
	constexpr fraction_t val4Actual { val4Actual_uint32_t };

	EXPECT_EQ( val1Expected, val1Actual );
	EXPECT_NE( val2Expected, val1Actual );
	EXPECT_NE( val3Expected, val1Actual );
	EXPECT_NE( val4Expected, val1Actual );
	EXPECT_NE( val1Expected, val2Actual );
	EXPECT_EQ( val2Expected, val2Actual );
	EXPECT_NE( val3Expected, val2Actual );
	EXPECT_NE( val4Expected, val2Actual );
	EXPECT_NE( val1Expected, val3Actual );
	EXPECT_NE( val2Expected, val3Actual );
	EXPECT_EQ( val3Expected, val3Actual );
	EXPECT_NE( val4Expected, val3Actual );
	EXPECT_NE( val1Expected, val4Actual );
	EXPECT_NE( val2Expected, val4Actual );
	EXPECT_NE( val3Expected, val4Actual );
	EXPECT_EQ( val4Expected, val4Actual );
}

TEST( TEST_CASE_NAME, differentFractionTypeConversion ) {
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { 83, 141 };
	constexpr fraction_t val3Expected { 12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction<std::uint32_t> val1Actual_uint32_t { 2, 1 };
	constexpr fraction<std::uint32_t> val2Actual_uint32_t { 83, 141 };
	constexpr fraction<std::uint32_t> val3Actual_uint32_t { 12714, 1616795 };
	constexpr fraction<std::uint32_t> val4Actual_uint32_t { 0, 1 };

	constexpr fraction_t val1Actual { static_cast<fraction_t>(val1Actual_uint32_t) };
	constexpr fraction_t val2Actual { static_cast<fraction_t>(val2Actual_uint32_t) };
	constexpr fraction_t val3Actual { static_cast<fraction_t>(val3Actual_uint32_t) };
	constexpr fraction_t val4Actual { static_cast<fraction_t>(val4Actual_uint32_t) };

	EXPECT_EQ( val1Expected, val1Actual );
	EXPECT_NE( val2Expected, val1Actual );
	EXPECT_NE( val3Expected, val1Actual );
	EXPECT_NE( val4Expected, val1Actual );
	EXPECT_NE( val1Expected, val2Actual );
	EXPECT_EQ( val2Expected, val2Actual );
	EXPECT_NE( val3Expected, val2Actual );
	EXPECT_NE( val4Expected, val2Actual );
	EXPECT_NE( val1Expected, val3Actual );
	EXPECT_NE( val2Expected, val3Actual );
	EXPECT_EQ( val3Expected, val3Actual );
	EXPECT_NE( val4Expected, val3Actual );
	EXPECT_NE( val1Expected, val4Actual );
	EXPECT_NE( val2Expected, val4Actual );
	EXPECT_NE( val3Expected, val4Actual );
	EXPECT_EQ( val4Expected, val4Actual );
}

TEST( TEST_CASE_NAME, differentTypeConversion ) {
	constexpr std::uint64_t val1Expected { 2 };
	constexpr double val2Expected { 0.588652482269503546099290780141843971 };
	constexpr double val3Expected { 0.007863705664601882118635943332333412 };
	constexpr std::uint64_t val4Expected { 0 };

	constexpr fraction_t val1Actual_uint64_t { 2, 1 };
	constexpr fraction_t val2Actual_uint64_t { 83, 141 };
	constexpr fraction_t val3Actual_uint64_t { 12714, 1616795 };
	constexpr fraction_t val4Actual_uint64_t { 0, 1 };

	constexpr std::uint64_t val1Actual { static_cast<std::uint64_t>(val1Actual_uint64_t) };
	constexpr double val2Actual { static_cast<double>(val2Actual_uint64_t) };
	constexpr double val3Actual { static_cast<double>(val3Actual_uint64_t) };
	constexpr std::uint64_t val4Actual { static_cast<std::uint64_t>(val4Actual_uint64_t) };

	EXPECT_EQ( val1Expected, val1Actual );
	EXPECT_NE( val2Expected, val1Actual );
	EXPECT_NE( val3Expected, val1Actual );
	EXPECT_NE( val4Expected, val1Actual );
	EXPECT_NE( val1Expected, val2Actual );
	EXPECT_EQ( val2Expected, val2Actual );
	EXPECT_NE( val3Expected, val2Actual );
	EXPECT_NE( val4Expected, val2Actual );
	EXPECT_NE( val1Expected, val3Actual );
	EXPECT_NE( val2Expected, val3Actual );
	EXPECT_EQ( val3Expected, val3Actual );
	EXPECT_NE( val4Expected, val3Actual );
	EXPECT_NE( val1Expected, val4Actual );
	EXPECT_NE( val2Expected, val4Actual );
	EXPECT_NE( val3Expected, val4Actual );
	EXPECT_EQ( val4Expected, val4Actual );
}

TEST( TEST_CASE_NAME, additon ) {
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { 83, 141 };
	constexpr fraction_t val3Expected { 12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1AdditonLhs { 1, 2 };
	constexpr fraction_t val2AdditonLhs { 66, 456 };
	constexpr fraction_t val3AdditonLhs { 466, 4850385 };
	constexpr fraction_t val4AdditonLhs { 0, 1 };
	constexpr fraction_t val1AdditonRhs { 3, 2 };
	constexpr fraction_t val2AdditonRhs { 4757, 10716 };
	constexpr fraction_t val3AdditonRhs { 37676, 4850385 };
	constexpr fraction_t val4AdditonRhs { 0, 1 };

	constexpr fraction_t val1Actual { val1AdditonLhs + val1AdditonRhs };
	constexpr fraction_t val2Actual { val2AdditonLhs + val2AdditonRhs };
	constexpr fraction_t val3Actual { val3AdditonLhs + val3AdditonRhs };
	constexpr fraction_t val4Actual { val4AdditonLhs + val4AdditonRhs };

	EXPECT_EQ( val1Expected, val1Actual );
	EXPECT_NE( val2Expected, val1Actual );
	EXPECT_NE( val3Expected, val1Actual );
	EXPECT_NE( val4Expected, val1Actual );
	EXPECT_NE( val1Expected, val2Actual );
	EXPECT_EQ( val2Expected, val2Actual );
	EXPECT_NE( val3Expected, val2Actual );
	EXPECT_NE( val4Expected, val2Actual );
	EXPECT_NE( val1Expected, val3Actual );
	EXPECT_NE( val2Expected, val3Actual );
	EXPECT_EQ( val3Expected, val3Actual );
	EXPECT_NE( val4Expected, val3Actual );
	EXPECT_NE( val1Expected, val4Actual );
	EXPECT_NE( val2Expected, val4Actual );
	EXPECT_NE( val3Expected, val4Actual );
	EXPECT_EQ( val4Expected, val4Actual );
}

TEST( TEST_CASE_NAME, differentFractionTypesAdditon ) {
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { 83, 141 };
	constexpr fraction_t val3Expected { 12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1AdditonLhs { 1, 2 };
	constexpr fraction_t val2AdditonLhs { 66, 456 };
	constexpr fraction<std::uint32_t> val3AdditonLhs { 466, 4850385 };
	constexpr fraction<std::uint32_t> val4AdditonLhs { 0, 1 };
	constexpr fraction<std::uint32_t> val1AdditonRhs { 3, 2 };
	constexpr fraction<std::uint32_t> val2AdditonRhs { 4757, 10716 };
	constexpr fraction_t val3AdditonRhs { 37676, 4850385 };
	constexpr fraction_t val4AdditonRhs { 0, 1 };

	constexpr fraction_t val1Actual { val1AdditonLhs + val1AdditonRhs };
	constexpr fraction_t val2Actual { val2AdditonLhs + val2AdditonRhs };
	constexpr fraction_t val3Actual { val3AdditonLhs + val3AdditonRhs };
	constexpr fraction_t val4Actual { val4AdditonLhs + val4AdditonRhs };

	EXPECT_EQ( val1Expected, val1Actual );
	EXPECT_NE( val2Expected, val1Actual );
	EXPECT_NE( val3Expected, val1Actual );
	EXPECT_NE( val4Expected, val1Actual );
	EXPECT_NE( val1Expected, val2Actual );
	EXPECT_EQ( val2Expected, val2Actual );
	EXPECT_NE( val3Expected, val2Actual );
	EXPECT_NE( val4Expected, val2Actual );
	EXPECT_NE( val1Expected, val3Actual );
	EXPECT_NE( val2Expected, val3Actual );
	EXPECT_EQ( val3Expected, val3Actual );
	EXPECT_NE( val4Expected, val3Actual );
	EXPECT_NE( val1Expected, val4Actual );
	EXPECT_NE( val2Expected, val4Actual );
	EXPECT_NE( val3Expected, val4Actual );
	EXPECT_EQ( val4Expected, val4Actual );
}

TEST( TEST_CASE_NAME, differentTypesAdditon ) {
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { 83, 141 };
	constexpr fraction_t val3Expected { 12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1AdditonLhs { 1, 2 };
	constexpr fraction_t val2AdditonLhs { 83, 141 };
	constexpr double val3AdditonLhs { 0.000096074847666731609964982161 };
	constexpr std::uint64_t val4AdditonLhs { 0 };
	constexpr double val1AdditonRhs { 1.5 };
	constexpr std::uint64_t val2AdditonRhs { 0 };
	constexpr fraction_t val3AdditonRhs { 37676, 4850385 };
	constexpr fraction_t val4AdditonRhs { 0, 1 };

	constexpr fraction_t val1Actual { val1AdditonLhs + val1AdditonRhs };
	constexpr fraction_t val2Actual { val2AdditonLhs + val2AdditonRhs };
	constexpr fraction_t val3Actual { val3AdditonLhs + val3AdditonRhs };
	constexpr fraction_t val4Actual { val4AdditonLhs + val4AdditonRhs };

	EXPECT_EQ( val1Expected, val1Actual );
	EXPECT_NE( val2Expected, val1Actual );
	EXPECT_NE( val3Expected, val1Actual );
	EXPECT_NE( val4Expected, val1Actual );
	EXPECT_NE( val1Expected, val2Actual );
	EXPECT_EQ( val2Expected, val2Actual );
	EXPECT_NE( val3Expected, val2Actual );
	EXPECT_NE( val4Expected, val2Actual );
	EXPECT_NE( val1Expected, val3Actual );
	EXPECT_NE( val2Expected, val3Actual );
	EXPECT_EQ( val3Expected, val3Actual );
	EXPECT_NE( val4Expected, val3Actual );
	EXPECT_NE( val1Expected, val4Actual );
	EXPECT_NE( val2Expected, val4Actual );
	EXPECT_NE( val3Expected, val4Actual );
	EXPECT_EQ( val4Expected, val4Actual );
}

TEST( TEST_CASE_NAME, subtraction ) {
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { 83, 141 };
	constexpr fraction_t val3Expected { 12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1AdditonLhs { 7, 2 };
	constexpr fraction_t val2AdditonLhs { 45419, 40749 };
	constexpr fraction_t val3AdditonLhs { 92008293157, 91046576835 };
	constexpr fraction_t val4AdditonLhs { 1, 1 };
	constexpr fraction_t val1AdditonRhs { 3, 2 };
	constexpr fraction_t val2AdditonRhs { 456, 867 };
	constexpr fraction_t val3AdditonRhs { 56465, 56313 };
	constexpr fraction_t val4AdditonRhs { 1, 1 };

	constexpr fraction_t val1Actual { val1AdditonLhs - val1AdditonRhs };
	constexpr fraction_t val2Actual { val2AdditonLhs - val2AdditonRhs };
	constexpr fraction_t val3Actual { val3AdditonLhs - val3AdditonRhs };
	constexpr fraction_t val4Actual { val4AdditonLhs - val4AdditonRhs };

	EXPECT_EQ( val1Expected, val1Actual );
	EXPECT_NE( val2Expected, val1Actual );
	EXPECT_NE( val3Expected, val1Actual );
	EXPECT_NE( val4Expected, val1Actual );
	EXPECT_NE( val1Expected, val2Actual );
	EXPECT_EQ( val2Expected, val2Actual );
	EXPECT_NE( val3Expected, val2Actual );
	EXPECT_NE( val4Expected, val2Actual );
	EXPECT_NE( val1Expected, val3Actual );
	EXPECT_NE( val2Expected, val3Actual );
	EXPECT_EQ( val3Expected, val3Actual );
	EXPECT_NE( val4Expected, val3Actual );
	EXPECT_NE( val1Expected, val4Actual );
	EXPECT_NE( val2Expected, val4Actual );
	EXPECT_NE( val3Expected, val4Actual );
	EXPECT_EQ( val4Expected, val4Actual );
}

TEST( TEST_CASE_NAME, differentFractionTypesSubtraction ) {
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { 83, 141 };
	constexpr fraction_t val3Expected { 12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1AdditonLhs { 1, 2 };
	constexpr fraction_t val2AdditonLhs { 45419, 40749 };
	constexpr fraction<std::int32_t> val3AdditonLhs { 85715563, 3233590 };
	constexpr fraction<std::int32_t> val4AdditonLhs { 1, 1 };
	constexpr fraction<std::int32_t> val1AdditonRhs { -3, 2 };
	constexpr fraction<std::int32_t> val2AdditonRhs { 456, 867 };
	constexpr fraction_t val3AdditonRhs { 53, 2 };
	constexpr fraction_t val4AdditonRhs { 1, 1 };

	constexpr fraction_t val1Actual { val1AdditonLhs - val1AdditonRhs };
	constexpr fraction_t val2Actual { val2AdditonLhs - val2AdditonRhs };
	constexpr fraction_t val3Actual { val3AdditonLhs - val3AdditonRhs };
	constexpr fraction_t val4Actual { val4AdditonLhs - val4AdditonRhs };

	EXPECT_EQ( val1Expected, val1Actual );
	EXPECT_NE( val2Expected, val1Actual );
	EXPECT_NE( val3Expected, val1Actual );
	EXPECT_NE( val4Expected, val1Actual );
	EXPECT_NE( val1Expected, val2Actual );
	EXPECT_EQ( val2Expected, val2Actual );
	EXPECT_NE( val3Expected, val2Actual );
	EXPECT_NE( val4Expected, val2Actual );
	EXPECT_NE( val1Expected, val3Actual );
	EXPECT_NE( val2Expected, val3Actual );
	EXPECT_EQ( val3Expected, val3Actual );
	EXPECT_NE( val4Expected, val3Actual );
	EXPECT_NE( val1Expected, val4Actual );
	EXPECT_NE( val2Expected, val4Actual );
	EXPECT_NE( val3Expected, val4Actual );
	EXPECT_EQ( val4Expected, val4Actual );
}

TEST( TEST_CASE_NAME, differentTypesSubtraction ) {
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { 83, 141 };
	constexpr fraction_t val3Expected { 12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1AdditonLhs { 7, 2 };
	constexpr fraction_t val2AdditonLhs { 647, 141 };
	constexpr double val3AdditonLhs { 26.507863705664601882118635 };
	constexpr std::uint64_t val4AdditonLhs { 1 };
	constexpr double val1AdditonRhs { 1.5 };
	constexpr std::uint64_t val2AdditonRhs { 4 };
	constexpr fraction_t val3AdditonRhs { 53, 2 };
	constexpr fraction_t val4AdditonRhs { 1, 1 };

	constexpr fraction_t val1Actual { val1AdditonLhs - val1AdditonRhs };
	constexpr fraction_t val2Actual { val2AdditonLhs - val2AdditonRhs };
	constexpr fraction_t val3Actual { val3AdditonLhs - val3AdditonRhs };
	constexpr fraction_t val4Actual { val4AdditonLhs - val4AdditonRhs };

	EXPECT_EQ( val1Expected, val1Actual );
	EXPECT_NE( val2Expected, val1Actual );
	EXPECT_NE( val3Expected, val1Actual );
	EXPECT_NE( val4Expected, val1Actual );
	EXPECT_NE( val1Expected, val2Actual );
	EXPECT_EQ( val2Expected, val2Actual );
	EXPECT_NE( val3Expected, val2Actual );
	EXPECT_NE( val4Expected, val2Actual );
	EXPECT_NE( val1Expected, val3Actual );
	EXPECT_NE( val2Expected, val3Actual );
	EXPECT_EQ( val3Expected, val3Actual );
	EXPECT_NE( val4Expected, val3Actual );
	EXPECT_NE( val1Expected, val4Actual );
	EXPECT_NE( val2Expected, val4Actual );
	EXPECT_NE( val3Expected, val4Actual );
	EXPECT_EQ( val4Expected, val4Actual );
}
