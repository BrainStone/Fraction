//
// Copyright (c) 2018 Yannick Schinko
// Licensed under the MIT License. See LICENSE file in the project root for full license information.
//
#include <sstream>

#include <gtest/gtest.h>

#include "defines.hpp"

#define TEST_CASE_NAME ConstexprTest_uint64_t

TEST( TEST_CASE_NAME, zeroExcpetion ) {
	EXPECT_THROW( ufraction_t( 0, 0 ), std::invalid_argument );
}

TEST( TEST_CASE_NAME, equals ) {
	constexpr ufraction_t val1Expected { 2, 1 };
	constexpr ufraction_t val2Expected { 83, 141 };
	constexpr ufraction_t val3Expected { 12714, 1616795 };
	constexpr ufraction_t val4Expected { 0, 1 };

	constexpr ufraction_t val1Actual { 2, 1 };
	constexpr ufraction_t val2Actual { 83, 141 };
	constexpr ufraction_t val3Actual { 12714, 1616795 };
	constexpr ufraction_t val4Actual { 0, 1 };

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
	constexpr ufraction_t val1Expected { 2, 1 };
	constexpr ufraction_t val2Expected { 83, 141 };
	constexpr ufraction_t val3Expected { 12714, 1616795 };
	constexpr ufraction_t val4Expected { 0, 1 };

	constexpr ufraction32_t val1Actual { 2, 1 };
	constexpr ufraction32_t val2Actual { 83, 141 };
	constexpr ufraction32_t val3Actual { 12714, 1616795 };
	constexpr ufraction32_t val4Actual { 0, 1 };

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
	constexpr ufraction_t val1Expected { 2, 1 };
	constexpr ufraction_t val2Expected { 83, 141 };
	constexpr ufraction_t val3Expected { 12714, 1616795 };
	constexpr ufraction_t val4Expected { 0, 1 };

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
	constexpr ufraction_t val1 { 4, 2 };
	constexpr ufraction_t val2 { 498, 846 };
	constexpr ufraction_t val3 { 343278, 43653465 };
	constexpr ufraction_t val4 { 0, 123 };

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
	constexpr ufraction_t val1 { 4, 2 };
	constexpr ufraction_t val2 { 498, 846 };
	constexpr ufraction_t val3 { 343278, 43653465 };
	constexpr ufraction_t val4 { 0, 123 };

	constexpr ufraction_t val1Reduced { 2, 1 };
	constexpr ufraction_t val2Reduced { 83, 141 };
	constexpr ufraction_t val3Reduced { 12714, 1616795 };
	constexpr ufraction_t val4Reduced { 0, 1 };

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

TEST( TEST_CASE_NAME, lessThan ) {
	constexpr ufraction_t val1 { 2, 1 };
	constexpr ufraction_t val2 { 83, 141 };
	constexpr ufraction_t val3 { 12714, 1616795 };
	constexpr ufraction_t val4 { 0, 1 };

	constexpr ufraction_t val5 { 2, 5 };
	constexpr ufraction_t val6 { 1, 2 };

	EXPECT_LT( val2, val1 );
	EXPECT_LT( val3, val1 );
	EXPECT_LT( val4, val1 );
	EXPECT_LT( val3, val2 );
	EXPECT_LT( val4, val2 );
	EXPECT_LT( val4, val3 );

	EXPECT_LT( val5, val6 );

	EXPECT_FALSE( val1 < val1 );
	EXPECT_FALSE( val2 < val2 );
	EXPECT_FALSE( val3 < val3 );
	EXPECT_FALSE( val4 < val4 );
}

TEST( TEST_CASE_NAME, greaterThan ) {
	constexpr ufraction_t val1 { 2, 1 };
	constexpr ufraction_t val2 { 83, 141 };
	constexpr ufraction_t val3 { 12714, 1616795 };
	constexpr ufraction_t val4 { 0, 1 };

	EXPECT_GT( val1, val2 );
	EXPECT_GT( val1, val3 );
	EXPECT_GT( val1, val4 );
	EXPECT_GT( val2, val3 );
	EXPECT_GT( val2, val4 );
	EXPECT_GT( val3, val4 );

	EXPECT_FALSE( val1 > val1 );
	EXPECT_FALSE( val2 > val2 );
	EXPECT_FALSE( val3 > val3 );
	EXPECT_FALSE( val4 > val4 );
}

TEST( TEST_CASE_NAME, lessThanOrEquals ) {
	constexpr ufraction_t val1 { 2, 1 };
	constexpr ufraction_t val2 { 83, 141 };
	constexpr ufraction_t val3 { 12714, 1616795 };
	constexpr ufraction_t val4 { 0, 1 };

	EXPECT_LE( val2, val1 );
	EXPECT_LE( val3, val1 );
	EXPECT_LE( val4, val1 );
	EXPECT_LE( val3, val2 );
	EXPECT_LE( val4, val2 );
	EXPECT_LE( val4, val3 );

	EXPECT_TRUE( val1 <= val1 );
	EXPECT_TRUE( val2 <= val2 );
	EXPECT_TRUE( val3 <= val3 );
	EXPECT_TRUE( val4 <= val4 );
}

TEST( TEST_CASE_NAME, greaterThanOrEquals ) {
	constexpr ufraction_t val1 { 2, 1 };
	constexpr ufraction_t val2 { 83, 141 };
	constexpr ufraction_t val3 { 12714, 1616795 };
	constexpr ufraction_t val4 { 0, 1 };

	EXPECT_GE( val1, val2 );
	EXPECT_GE( val1, val3 );
	EXPECT_GE( val1, val4 );
	EXPECT_GE( val2, val3 );
	EXPECT_GE( val2, val4 );
	EXPECT_GE( val3, val4 );

	EXPECT_TRUE( val1 >= val1 );
	EXPECT_TRUE( val2 >= val2 );
	EXPECT_TRUE( val3 >= val3 );
	EXPECT_TRUE( val4 >= val4 );
}

TEST( TEST_CASE_NAME, floatingPointConstructor ) {
	constexpr ufraction_t val1 { 2.0 };
	constexpr ufraction_t val2 { 0.588652482269503546099290780141843971 };
	constexpr ufraction_t val3 { 0.007863705664601882118635943332333412 };
	constexpr ufraction_t val4 { 0.0 };

	constexpr ufraction_t val1Expected { 2, 1 };
	constexpr ufraction_t val2Expected { 83, 141 };
	constexpr ufraction_t val3Expected { 12714, 1616795 };
	constexpr ufraction_t val4Expected { 0, 1 };

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
	EXPECT_THROW( ufraction_t( -1.0 ), std::invalid_argument );
}

TEST( TEST_CASE_NAME, differentTypeConstructor ) {
	constexpr std::uint64_t factor { std::numeric_limits<std::uint32_t>::max() };

	constexpr ufraction32_t val1Expected { 2, 1 };
	constexpr ufraction32_t val2Expected { 83, 141 };
	constexpr ufraction32_t val3Expected { 12714, 1616795 };
	constexpr ufraction32_t val4Expected { 0, 1 };

	constexpr ufraction32_t val1Actual { 2 * factor, 1 * factor };
	constexpr ufraction32_t val2Actual { 83 * factor, 141 * factor };
	constexpr ufraction32_t val3Actual { 12714 * factor, 1616795 * factor };
	constexpr ufraction32_t val4Actual { 0 * factor, 1 * factor };

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

TEST( TEST_CASE_NAME, differentFractionTypeCopyConstructor ) {
	constexpr ufraction_t val1Expected { 2, 1 };
	constexpr ufraction_t val2Expected { 83, 141 };
	constexpr ufraction_t val3Expected { 12714, 1616795 };
	constexpr ufraction_t val4Expected { 0, 1 };

	constexpr ufraction32_t val1Actual_uint32_t { 2, 1 };
	constexpr ufraction32_t val2Actual_uint32_t { 83, 141 };
	constexpr ufraction32_t val3Actual_uint32_t { 12714, 1616795 };
	constexpr ufraction32_t val4Actual_uint32_t { 0, 1 };

	constexpr ufraction_t val1Actual { val1Actual_uint32_t };
	constexpr ufraction_t val2Actual { val2Actual_uint32_t };
	constexpr ufraction_t val3Actual { val3Actual_uint32_t };
	constexpr ufraction_t val4Actual { val4Actual_uint32_t };

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
	constexpr ufraction_t val1Expected { 2, 1 };
	constexpr ufraction_t val2Expected { 83, 141 };
	constexpr ufraction_t val3Expected { 12714, 1616795 };
	constexpr ufraction_t val4Expected { 0, 1 };

	constexpr ufraction32_t val1Actual_uint32_t { 2, 1 };
	constexpr ufraction32_t val2Actual_uint32_t { 83, 141 };
	constexpr ufraction32_t val3Actual_uint32_t { 12714, 1616795 };
	constexpr ufraction32_t val4Actual_uint32_t { 0, 1 };

	constexpr ufraction_t val1Actual { static_cast<ufraction_t>(val1Actual_uint32_t) };
	constexpr ufraction_t val2Actual { static_cast<ufraction_t>(val2Actual_uint32_t) };
	constexpr ufraction_t val3Actual { static_cast<ufraction_t>(val3Actual_uint32_t) };
	constexpr ufraction_t val4Actual { static_cast<ufraction_t>(val4Actual_uint32_t) };

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

	constexpr ufraction_t val1Actual_uint64_t { 2, 1 };
	constexpr ufraction_t val2Actual_uint64_t { 83, 141 };
	constexpr ufraction_t val3Actual_uint64_t { 12714, 1616795 };
	constexpr ufraction_t val4Actual_uint64_t { 0, 1 };

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

TEST( TEST_CASE_NAME, addition ) {
	constexpr ufraction_t val1Expected { 2, 1 };
	constexpr ufraction_t val2Expected { 83, 141 };
	constexpr ufraction_t val3Expected { 12714, 1616795 };
	constexpr ufraction_t val4Expected { 0, 1 };

	constexpr ufraction_t val1AdditionLhs { 1, 2 };
	constexpr ufraction_t val2AdditionLhs { 66, 456 };
	constexpr ufraction_t val3AdditionLhs { 466, 4850385 };
	constexpr ufraction_t val4AdditionLhs { 0, 1 };
	constexpr ufraction_t val1AdditionRhs { 3, 2 };
	constexpr ufraction_t val2AdditionRhs { 4757, 10716 };
	constexpr ufraction_t val3AdditionRhs { 37676, 4850385 };
	constexpr ufraction_t val4AdditionRhs { 0, 1 };

	constexpr ufraction_t val1Actual { val1AdditionLhs + val1AdditionRhs };
	constexpr ufraction_t val2Actual { val2AdditionLhs + val2AdditionRhs };
	constexpr ufraction_t val3Actual { val3AdditionLhs + val3AdditionRhs };
	constexpr ufraction_t val4Actual { val4AdditionLhs + val4AdditionRhs };

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

TEST( TEST_CASE_NAME, differentFractionTypesAddition ) {
	constexpr ufraction_t val1Expected { 2, 1 };
	constexpr ufraction_t val2Expected { 83, 141 };
	constexpr ufraction_t val3Expected { 12714, 1616795 };
	constexpr ufraction_t val4Expected { 0, 1 };

	constexpr ufraction_t val1AdditionLhs { 1, 2 };
	constexpr ufraction_t val2AdditionLhs { 66, 456 };
	constexpr ufraction32_t val3AdditionLhs { 466, 4850385 };
	constexpr ufraction32_t val4AdditionLhs { 0, 1 };
	constexpr ufraction32_t val1AdditionRhs { 3, 2 };
	constexpr ufraction32_t val2AdditionRhs { 4757, 10716 };
	constexpr ufraction_t val3AdditionRhs { 37676, 4850385 };
	constexpr ufraction_t val4AdditionRhs { 0, 1 };

	constexpr ufraction_t val1Actual { val1AdditionLhs + val1AdditionRhs };
	constexpr ufraction_t val2Actual { val2AdditionLhs + val2AdditionRhs };
	constexpr ufraction_t val3Actual { val3AdditionLhs + val3AdditionRhs };
	constexpr ufraction_t val4Actual { val4AdditionLhs + val4AdditionRhs };

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

TEST( TEST_CASE_NAME, differentTypesAddition ) {
	constexpr ufraction_t val1Expected { 2, 1 };
	constexpr ufraction_t val2Expected { 83, 141 };
	constexpr ufraction_t val3Expected { 12714, 1616795 };
	constexpr ufraction_t val4Expected { 0, 1 };

	constexpr ufraction_t val1AdditionLhs { 1, 2 };
	constexpr ufraction_t val2AdditionLhs { 83, 141 };
	constexpr double val3AdditionLhs { 0.000096074847666731609964982161 };
	constexpr std::uint64_t val4AdditionLhs { 0 };
	constexpr double val1AdditionRhs { 1.5 };
	constexpr std::uint64_t val2AdditionRhs { 0 };
	constexpr ufraction_t val3AdditionRhs { 37676, 4850385 };
	constexpr ufraction_t val4AdditionRhs { 0, 1 };

	constexpr ufraction_t val1Actual { val1AdditionLhs + val1AdditionRhs };
	constexpr ufraction_t val2Actual { val2AdditionLhs + val2AdditionRhs };
	constexpr ufraction_t val3Actual { val3AdditionLhs + val3AdditionRhs };
	constexpr ufraction_t val4Actual { val4AdditionLhs + val4AdditionRhs };

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
	constexpr ufraction_t val1Expected { 2, 1 };
	constexpr ufraction_t val2Expected { 83, 141 };
	constexpr ufraction_t val3Expected { 12714, 1616795 };
	constexpr ufraction_t val4Expected { 0, 1 };

	constexpr ufraction_t val1SubtractionLhs { 7, 2 };
	constexpr ufraction_t val2SubtractionLhs { 45419, 40749 };
	constexpr ufraction_t val3SubtractionLhs { 92008293157, 91046576835 };
	constexpr ufraction_t val4SubtractionLhs { 1, 1 };
	constexpr ufraction_t val1SubtractionRhs { 3, 2 };
	constexpr ufraction_t val2SubtractionRhs { 456, 867 };
	constexpr ufraction_t val3SubtractionRhs { 56465, 56313 };
	constexpr ufraction_t val4SubtractionRhs { 1, 1 };

	constexpr ufraction_t val1Actual { val1SubtractionLhs - val1SubtractionRhs };
	constexpr ufraction_t val2Actual { val2SubtractionLhs - val2SubtractionRhs };
	constexpr ufraction_t val3Actual { val3SubtractionLhs - val3SubtractionRhs };
	constexpr ufraction_t val4Actual { val4SubtractionLhs - val4SubtractionRhs };

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
	constexpr ufraction_t val1Expected { 2, 1 };
	constexpr ufraction_t val2Expected { 83, 141 };
	constexpr ufraction_t val3Expected { 12714, 1616795 };
	constexpr ufraction_t val4Expected { 0, 1 };

	constexpr ufraction_t val1SubtractionLhs { 1, 2 };
	constexpr ufraction_t val2SubtractionLhs { 45419, 40749 };
	constexpr fraction<std::int32_t> val3SubtractionLhs { 85715563, 3233590 };
	constexpr fraction<std::int32_t> val4SubtractionLhs { 1, 1 };
	constexpr fraction<std::int32_t> val1SubtractionRhs { -3, 2 };
	constexpr fraction<std::int32_t> val2SubtractionRhs { 456, 867 };
	constexpr ufraction_t val3SubtractionRhs { 53, 2 };
	constexpr ufraction_t val4SubtractionRhs { 1, 1 };

	constexpr ufraction_t val1Actual { val1SubtractionLhs - val1SubtractionRhs };
	constexpr ufraction_t val2Actual { val2SubtractionLhs - val2SubtractionRhs };
	constexpr ufraction_t val3Actual { val3SubtractionLhs - val3SubtractionRhs };
	constexpr ufraction_t val4Actual { val4SubtractionLhs - val4SubtractionRhs };

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
	constexpr ufraction_t val1Expected { 2, 1 };
	constexpr ufraction_t val2Expected { 83, 141 };
	constexpr ufraction_t val3Expected { 12714, 1616795 };
	constexpr ufraction_t val4Expected { 0, 1 };

	constexpr ufraction_t val1SubtractionLhs { 7, 2 };
	constexpr ufraction_t val2SubtractionLhs { 647, 141 };
	constexpr double val3SubtractionLhs { 26.507863705664601882118635 };
	constexpr std::uint64_t val4SubtractionLhs { 1 };
	constexpr double val1SubtractionRhs { 1.5 };
	constexpr std::uint64_t val2SubtractionRhs { 4 };
	constexpr ufraction_t val3SubtractionRhs { 53, 2 };
	constexpr ufraction_t val4SubtractionRhs { 1, 1 };

	constexpr ufraction_t val1Actual { val1SubtractionLhs - val1SubtractionRhs };
	constexpr ufraction_t val2Actual { val2SubtractionLhs - val2SubtractionRhs };
	constexpr ufraction_t val3Actual { val3SubtractionLhs - val3SubtractionRhs };
	constexpr ufraction_t val4Actual { val4SubtractionLhs - val4SubtractionRhs };

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

TEST( TEST_CASE_NAME, multiplication ) {
	constexpr ufraction_t val1Expected { 2, 1 };
	constexpr ufraction_t val2Expected { 83, 141 };
	constexpr ufraction_t val3Expected { 12714, 1616795 };
	constexpr ufraction_t val4Expected { 0, 1 };

	constexpr ufraction_t val1MultiplicationLhs { 1, 2 };
	constexpr ufraction_t val2MultiplicationLhs { 7899, 1235 };
	constexpr ufraction_t val3MultiplicationLhs { 5, 1 };
	constexpr ufraction_t val4MultiplicationLhs { 5686, 78 };
	constexpr ufraction_t val1MultiplicationRhs { 4, 1 };
	constexpr ufraction_t val2MultiplicationRhs { 102505, 1113759 };
	constexpr ufraction_t val3MultiplicationRhs { 12714, 8083975 };
	constexpr ufraction_t val4MultiplicationRhs { 0, 1 };

	constexpr ufraction_t val1Actual { val1MultiplicationLhs * val1MultiplicationRhs };
	constexpr ufraction_t val2Actual { val2MultiplicationLhs * val2MultiplicationRhs };
	constexpr ufraction_t val3Actual { val3MultiplicationLhs * val3MultiplicationRhs };
	constexpr ufraction_t val4Actual { val4MultiplicationLhs * val4MultiplicationRhs };

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

TEST( TEST_CASE_NAME, differentFractionTypesMultiplication ) {
	constexpr ufraction_t val1Expected { 2, 1 };
	constexpr ufraction_t val2Expected { 83, 141 };
	constexpr ufraction_t val3Expected { 12714, 1616795 };
	constexpr ufraction_t val4Expected { 0, 1 };

	constexpr ufraction_t val1MultiplicationLhs { 1, 2 };
	constexpr ufraction_t val2MultiplicationLhs { 7899, 1235 };
	constexpr ufraction32_t val3MultiplicationLhs { 5, 1 };
	constexpr ufraction32_t val4MultiplicationLhs { 5686, 78 };
	constexpr ufraction32_t val1MultiplicationRhs { 4, 1 };
	constexpr ufraction32_t val2MultiplicationRhs { 102505, 1113759 };
	constexpr ufraction_t val3MultiplicationRhs { 12714, 8083975 };
	constexpr ufraction_t val4MultiplicationRhs { 0, 1 };

	constexpr ufraction_t val1Actual { val1MultiplicationLhs * val1MultiplicationRhs };
	constexpr ufraction_t val2Actual { val2MultiplicationLhs * val2MultiplicationRhs };
	constexpr ufraction_t val3Actual { val3MultiplicationLhs * val3MultiplicationRhs };
	constexpr ufraction_t val4Actual { val4MultiplicationLhs * val4MultiplicationRhs };

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

TEST( TEST_CASE_NAME, differentTypesMultiplication ) {
	constexpr ufraction_t val1Expected { 2, 1 };
	constexpr ufraction_t val2Expected { 83, 141 };
	constexpr ufraction_t val3Expected { 12714, 1616795 };
	constexpr ufraction_t val4Expected { 0, 1 };

	constexpr ufraction_t val1MultiplicationLhs { 1, 2 };
	constexpr ufraction_t val2MultiplicationLhs { 7899, 1235 };
	constexpr std::uint64_t val3MultiplicationLhs { 5 };
	constexpr double val4MultiplicationLhs { 72.89743589743589743589743 };
	constexpr std::uint64_t val1MultiplicationRhs { 4 };
	constexpr double val2MultiplicationRhs { 0.09203517098402796296 };
	constexpr ufraction_t val3MultiplicationRhs { 12714, 8083975 };
	constexpr ufraction_t val4MultiplicationRhs { 0, 1 };

	constexpr ufraction_t val1Actual { val1MultiplicationLhs * val1MultiplicationRhs };
	constexpr ufraction_t val2Actual { val2MultiplicationLhs * val2MultiplicationRhs };
	constexpr ufraction_t val3Actual { val3MultiplicationLhs * val3MultiplicationRhs };
	constexpr ufraction_t val4Actual { val4MultiplicationLhs * val4MultiplicationRhs };

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

TEST( TEST_CASE_NAME, division ) {
	constexpr ufraction_t val1Expected { 2, 1 };
	constexpr ufraction_t val2Expected { 83, 141 };
	constexpr ufraction_t val3Expected { 12714, 1616795 };
	constexpr ufraction_t val4Expected { 0, 1 };

	constexpr ufraction_t val1DivisionLhs { 1, 2 };
	constexpr ufraction_t val2DivisionLhs { 7899, 1235 };
	constexpr ufraction_t val3DivisionLhs { 5, 1 };
	constexpr ufraction_t val4DivisionLhs { 0, 78 };
	constexpr ufraction_t val1DivisionRhs { 1, 4 };
	constexpr ufraction_t val2DivisionRhs { 1113759 , 102505 };
	constexpr ufraction_t val3DivisionRhs { 8083975 , 12714 };
	constexpr ufraction_t val4DivisionRhs { 5, 1 };

	constexpr ufraction_t val1Actual { val1DivisionLhs / val1DivisionRhs };
	constexpr ufraction_t val2Actual { val2DivisionLhs / val2DivisionRhs };
	constexpr ufraction_t val3Actual { val3DivisionLhs / val3DivisionRhs };
	constexpr ufraction_t val4Actual { val4DivisionLhs / val4DivisionRhs };

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

TEST( TEST_CASE_NAME, differentFractionTypesDivision ) {
	constexpr ufraction_t val1Expected { 2, 1 };
	constexpr ufraction_t val2Expected { 83, 141 };
	constexpr ufraction_t val3Expected { 12714, 1616795 };
	constexpr ufraction_t val4Expected { 0, 1 };

	constexpr ufraction_t val1DivisionLhs { 1, 2 };
	constexpr ufraction_t val2DivisionLhs { 7899, 1235 };
	constexpr ufraction32_t val3DivisionLhs { 5, 1 };
	constexpr ufraction32_t val4DivisionLhs { 0, 78 };
	constexpr ufraction32_t val1DivisionRhs { 1, 4 };
	constexpr ufraction32_t val2DivisionRhs { 1113759 , 102505 };
	constexpr ufraction_t val3DivisionRhs { 8083975 , 12714 };
	constexpr ufraction_t val4DivisionRhs { 5, 1 };

	constexpr ufraction_t val1Actual { val1DivisionLhs / val1DivisionRhs };
	constexpr ufraction_t val2Actual { val2DivisionLhs / val2DivisionRhs };
	constexpr ufraction_t val3Actual { val3DivisionLhs / val3DivisionRhs };
	constexpr ufraction_t val4Actual { val4DivisionLhs / val4DivisionRhs };

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

TEST( TEST_CASE_NAME, differentTypesDivision ) {
	constexpr ufraction_t val1Expected { 2, 1 };
	constexpr ufraction_t val2Expected { 83, 141 };
	constexpr ufraction_t val3Expected { 12714, 1616795 };
	constexpr ufraction_t val4Expected { 0, 1 };

	constexpr ufraction_t val1DivisionLhs { 16, 2 };
	constexpr ufraction_t val2DivisionLhs { 7899, 1235 };
	constexpr std::uint64_t val3DivisionLhs { 5 };
	constexpr double val4DivisionLhs { 0 };
	constexpr std::uint64_t val1DivisionRhs { 4 };
	constexpr double val2DivisionRhs { 10.865411443344227110872 };
	constexpr ufraction_t val3DivisionRhs { 8083975 , 12714 };
	constexpr ufraction_t val4DivisionRhs { 5, 1 };

	constexpr ufraction_t val1Actual { val1DivisionLhs / val1DivisionRhs };
	constexpr ufraction_t val2Actual { val2DivisionLhs / val2DivisionRhs };
	constexpr ufraction_t val3Actual { val3DivisionLhs / val3DivisionRhs };
	constexpr ufraction_t val4Actual { val4DivisionLhs / val4DivisionRhs };

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

TEST( TEST_CASE_NAME, ostream ) {
	constexpr ufraction_t val1 { 2, 1 };
	constexpr ufraction_t val2 { 83, 141 };
	constexpr ufraction_t val3 { 12714, 1616795 };
	constexpr ufraction_t val4 { 0, 1 };

	const std::string val1Expected { "2/1" };
	const std::string val2Expected { "83/141" };
	const std::string val3Expected { "12714/1616795" };
	const std::string val4Expected { "0/1" };

	std::stringstream ss1;
	std::stringstream ss2;
	std::stringstream ss3;
	std::stringstream ss4;

	ss1 << val1;
	ss2 << val2;
	ss3 << val3;
	ss4 << val4;

	const std::string val1Actual { ss1.str() };
	const std::string val2Actual { ss2.str() };
	const std::string val3Actual { ss3.str() };
	const std::string val4Actual { ss4.str() };

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

TEST( TEST_CASE_NAME, wostream ) {
	constexpr ufraction_t val1 { 2, 1 };
	constexpr ufraction_t val2 { 83, 141 };
	constexpr ufraction_t val3 { 12714, 1616795 };
	constexpr ufraction_t val4 { 0, 1 };

	const std::wstring val1Expected { L"2/1" };
	const std::wstring val2Expected { L"83/141" };
	const std::wstring val3Expected { L"12714/1616795" };
	const std::wstring val4Expected { L"0/1" };

	std::wstringstream ss1;
	std::wstringstream ss2;
	std::wstringstream ss3;
	std::wstringstream ss4;

	ss1 << val1;
	ss2 << val2;
	ss3 << val3;
	ss4 << val4;

	const std::wstring val1Actual { ss1.str() };
	const std::wstring val2Actual { ss2.str() };
	const std::wstring val3Actual { ss3.str() };
	const std::wstring val4Actual { ss4.str() };

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
