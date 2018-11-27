//
// Copyright (c) 2018 Yannick Schinko
// Licensed under the MIT License. See LICENSE file in the project root for full license information.
//
#include <gtest/gtest.h>

#include "fraction.hpp"

#define TEST_CASE_NAME ConstexprTest_int64_t

using fraction_t = fraction<std::int64_t>;

TEST( TEST_CASE_NAME, zeroExcpetion ) {
	EXPECT_THROW( fraction_t( 0, 0 ), std::invalid_argument );
}

TEST( TEST_CASE_NAME, equals ) {
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { -83, 141 };
	constexpr fraction_t val3Expected { -12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1Actual { 2, 1 };
	constexpr fraction_t val2Actual { -83, 141 };
	constexpr fraction_t val3Actual { -12714, 1616795 };
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
	constexpr fraction_t val2Expected { -83, 141 };
	constexpr fraction_t val3Expected { -12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction<std::int32_t> val1Actual { 2, 1 };
	constexpr fraction<std::int32_t> val2Actual { -83, 141 };
	constexpr fraction<std::int32_t> val3Actual { -12714, 1616795 };
	constexpr fraction<std::int32_t> val4Actual { 0, 1 };

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
	constexpr fraction_t val2Expected { -83, 141 };
	constexpr fraction_t val3Expected { -12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr std::int64_t val1Actual { 2 };
	constexpr double val2Actual { -0.588652482269503546099290780141843971 };
	constexpr double val3Actual { -0.007863705664601882118635943332333412 };
	constexpr std::int64_t val4Actual { 0 };

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
	constexpr fraction_t val2 { -498, 846 };
	constexpr fraction_t val3 { 343278, -43653465 };
	constexpr fraction_t val4 { -0, -123 };

	EXPECT_EQ( 2, val1.getNumerator() );
	EXPECT_EQ( 1, val1.getDenominator() );
	EXPECT_EQ( -83, val2.getNumerator() );
	EXPECT_EQ( 141, val2.getDenominator() );
	EXPECT_EQ( -12714, val3.getNumerator() );
	EXPECT_EQ( 1616795, val3.getDenominator() );
	EXPECT_EQ( 0, val4.getNumerator() );
	EXPECT_EQ( 1, val4.getDenominator() );
}

TEST( TEST_CASE_NAME, reductionEquals ) {
	constexpr fraction_t val1 { 4, 2 };
	constexpr fraction_t val2 { -498, 846 };
	constexpr fraction_t val3 { 343278, -43653465 };
	constexpr fraction_t val4 { -0, -123 };

	constexpr fraction_t val1Reduced { 2, 1 };
	constexpr fraction_t val2Reduced { -83, 141 };
	constexpr fraction_t val3Reduced { -12714, 1616795 };
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
	constexpr fraction_t val2 { -0.588652482269503546099290780141843971 };
	constexpr fraction_t val3 { -0.007863705664601882118635943332333412 };
	constexpr fraction_t val4 { 0.0 };

	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { -83, 141 };
	constexpr fraction_t val3Expected { -12714, 1616795 };
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

TEST( TEST_CASE_NAME, differentTypeCopyConstructor ) {
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { -83, 141 };
	constexpr fraction_t val3Expected { -12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction<std::int32_t> val1Actual_int32_t { 2, 1 };
	constexpr fraction<std::int32_t> val2Actual_int32_t { -83, 141 };
	constexpr fraction<std::int32_t> val3Actual_int32_t { -12714, 1616795 };
	constexpr fraction<std::int32_t> val4Actual_int32_t { 0, 1 };

	constexpr fraction_t val1Actual { val1Actual_int32_t };
	constexpr fraction_t val2Actual { val2Actual_int32_t };
	constexpr fraction_t val3Actual { val3Actual_int32_t };
	constexpr fraction_t val4Actual { val4Actual_int32_t };

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
	constexpr fraction_t val2Expected { -83, 141 };
	constexpr fraction_t val3Expected { -12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction<std::int32_t> val1Actual_int32_t { 2, 1 };
	constexpr fraction<std::int32_t> val2Actual_int32_t { -83, 141 };
	constexpr fraction<std::int32_t> val3Actual_int32_t { -12714, 1616795 };
	constexpr fraction<std::int32_t> val4Actual_int32_t { 0, 1 };

	constexpr fraction_t val1Actual { static_cast<fraction_t>(val1Actual_int32_t) };
	constexpr fraction_t val2Actual { static_cast<fraction_t>(val2Actual_int32_t) };
	constexpr fraction_t val3Actual { static_cast<fraction_t>(val3Actual_int32_t) };
	constexpr fraction_t val4Actual { static_cast<fraction_t>(val4Actual_int32_t) };

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
	constexpr std::int64_t val1Expected { 2 };
	constexpr double val2Expected { -0.588652482269503546099290780141843971 };
	constexpr double val3Expected { -0.007863705664601882118635943332333412 };
	constexpr std::int64_t val4Expected { 0 };

	constexpr fraction_t val1Actual_int64_t { 2, 1 };
	constexpr fraction_t val2Actual_int64_t { -83, 141 };
	constexpr fraction_t val3Actual_int64_t { -12714, 1616795 };
	constexpr fraction_t val4Actual_int64_t { 0, 1 };

	constexpr std::int64_t val1Actual { static_cast<std::int64_t>(val1Actual_int64_t) };
	constexpr double val2Actual { static_cast<double>(val2Actual_int64_t) };
	constexpr double val3Actual { static_cast<double>(val3Actual_int64_t) };
	constexpr std::int64_t val4Actual { static_cast<std::int64_t>(val4Actual_int64_t) };

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
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { -83, 141 };
	constexpr fraction_t val3Expected { -12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1AdditionLhs { 1, 2 };
	constexpr fraction_t val2AdditionLhs { 7899, 1235 };
	constexpr fraction_t val3AdditionLhs { -4565, 5464 };
	constexpr fraction_t val4AdditionLhs { 1, 1 };
	constexpr fraction_t val1AdditionRhs { 3, 2 };
	constexpr fraction_t val2AdditionRhs { -1216264, 174135 };
	constexpr fraction_t val3AdditionRhs { 7311199879, 8834167880 };
	constexpr fraction_t val4AdditionRhs { -1, 1 };

	constexpr fraction_t val1Actual { val1AdditionLhs + val1AdditionRhs };
	constexpr fraction_t val2Actual { val2AdditionLhs + val2AdditionRhs };
	constexpr fraction_t val3Actual { val3AdditionLhs + val3AdditionRhs };
	constexpr fraction_t val4Actual { val4AdditionLhs + val4AdditionRhs };

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
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { -83, 141 };
	constexpr fraction_t val3Expected { -12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1AdditionLhs { 1, 2 };
	constexpr fraction_t val2AdditionLhs { 7899, 1235 };
	constexpr fraction<std::int32_t> val3AdditionLhs { -4565, 5464 };
	constexpr fraction<std::int32_t> val4AdditionLhs { 1, 1 };
	constexpr fraction<std::int32_t> val1AdditionRhs { 3, 2 };
	constexpr fraction<std::int32_t> val2AdditionRhs { -1216264, 174135 };
	constexpr fraction_t val3AdditionRhs { 7311199879, 8834167880 };
	constexpr fraction_t val4AdditionRhs { -1, 1 };

	constexpr fraction_t val1Actual { val1AdditionLhs + val1AdditionRhs };
	constexpr fraction_t val2Actual { val2AdditionLhs + val2AdditionRhs };
	constexpr fraction_t val3Actual { val3AdditionLhs + val3AdditionRhs };
	constexpr fraction_t val4Actual { val4AdditionLhs + val4AdditionRhs };

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
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { -83, 141 };
	constexpr fraction_t val3Expected { -12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1AdditionLhs { 1, 2 };
	constexpr fraction_t val2AdditionLhs { 481, 141 };
	constexpr double val3AdditionLhs { -0.835468521229868228404099560761 };
	constexpr std::int64_t val4AdditionLhs { 1 };
	constexpr double val1AdditionRhs { 1.5 };
	constexpr std::int64_t val2AdditionRhs { -4 };
	constexpr fraction_t val3AdditionRhs { 7311199879, 8834167880 };
	constexpr fraction_t val4AdditionRhs { -1, 1 };

	constexpr fraction_t val1Actual { val1AdditionLhs + val1AdditionRhs };
	constexpr fraction_t val2Actual { val2AdditionLhs + val2AdditionRhs };
	constexpr fraction_t val3Actual { val3AdditionLhs + val3AdditionRhs };
	constexpr fraction_t val4Actual { val4AdditionLhs + val4AdditionRhs };

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
	constexpr fraction_t val2Expected { -83, 141 };
	constexpr fraction_t val3Expected { -12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1SubtractionLhs { 1, 2 };
	constexpr fraction_t val2SubtractionLhs { 7899, 1235 };
	constexpr fraction_t val3SubtractionLhs { -4565, 5464 };
	constexpr fraction_t val4SubtractionLhs { 1, 1 };
	constexpr fraction_t val1SubtractionRhs { -3, 2 };
	constexpr fraction_t val2SubtractionRhs { 1216264, 174135 };
	constexpr fraction_t val3SubtractionRhs { -7311199879, 8834167880 };
	constexpr fraction_t val4SubtractionRhs { 1, 1 };

	constexpr fraction_t val1Actual { val1SubtractionLhs - val1SubtractionRhs };
	constexpr fraction_t val2Actual { val2SubtractionLhs - val2SubtractionRhs };
	constexpr fraction_t val3Actual { val3SubtractionLhs - val3SubtractionRhs };
	constexpr fraction_t val4Actual { val4SubtractionLhs - val4SubtractionRhs };

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
	constexpr fraction_t val2Expected { -83, 141 };
	constexpr fraction_t val3Expected { -12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1SubtractionLhs { 1, 2 };
	constexpr fraction_t val2SubtractionLhs { 7899, 1235 };
	constexpr fraction<std::int32_t> val3SubtractionLhs { -4565, 5464 };
	constexpr fraction<std::int32_t> val4SubtractionLhs { 1, 1 };
	constexpr fraction<std::int32_t> val1SubtractionRhs { -3, 2 };
	constexpr fraction<std::int32_t> val2SubtractionRhs { 1216264, 174135 };
	constexpr fraction_t val3SubtractionRhs { -7311199879, 8834167880 };
	constexpr fraction_t val4SubtractionRhs { 1, 1 };

	constexpr fraction_t val1Actual { val1SubtractionLhs - val1SubtractionRhs };
	constexpr fraction_t val2Actual { val2SubtractionLhs - val2SubtractionRhs };
	constexpr fraction_t val3Actual { val3SubtractionLhs - val3SubtractionRhs };
	constexpr fraction_t val4Actual { val4SubtractionLhs - val4SubtractionRhs };

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
	constexpr fraction_t val2Expected { -83, 141 };
	constexpr fraction_t val3Expected { -12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1SubtractionLhs { 1, 2 };
	constexpr fraction_t val2SubtractionLhs { 481, 141 };
	constexpr double val3SubtractionLhs { -0.835468521229868228404099560761 };
	constexpr std::int64_t val4SubtractionLhs { 1 };
	constexpr double val1SubtractionRhs { -1.5 };
	constexpr std::int64_t val2SubtractionRhs { 4 };
	constexpr fraction_t val3SubtractionRhs { -7311199879, 8834167880 };
	constexpr fraction_t val4SubtractionRhs { 1, 1 };

	constexpr fraction_t val1Actual { val1SubtractionLhs - val1SubtractionRhs };
	constexpr fraction_t val2Actual { val2SubtractionLhs - val2SubtractionRhs };
	constexpr fraction_t val3Actual { val3SubtractionLhs - val3SubtractionRhs };
	constexpr fraction_t val4Actual { val4SubtractionLhs - val4SubtractionRhs };

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
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { -83, 141 };
	constexpr fraction_t val3Expected { -12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1MultiplicationLhs { -1, 2 };
	constexpr fraction_t val2MultiplicationLhs { 7899, 1235 };
	constexpr fraction_t val3MultiplicationLhs { 5, 1 };
	constexpr fraction_t val4MultiplicationLhs { 5686, 78 };
	constexpr fraction_t val1MultiplicationRhs { -4, 1 };
	constexpr fraction_t val2MultiplicationRhs { -102505, 1113759 };
	constexpr fraction_t val3MultiplicationRhs { -12714, 8083975 };
	constexpr fraction_t val4MultiplicationRhs { 0, 1 };

	constexpr fraction_t val1Actual { val1MultiplicationLhs * val1MultiplicationRhs };
	constexpr fraction_t val2Actual { val2MultiplicationLhs * val2MultiplicationRhs };
	constexpr fraction_t val3Actual { val3MultiplicationLhs * val3MultiplicationRhs };
	constexpr fraction_t val4Actual { val4MultiplicationLhs * val4MultiplicationRhs };

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
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { -83, 141 };
	constexpr fraction_t val3Expected { -12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1MultiplicationLhs { -1, 2 };
	constexpr fraction_t val2MultiplicationLhs { 7899, 1235 };
	constexpr fraction<std::int32_t> val3MultiplicationLhs { 5, 1 };
	constexpr fraction<std::int32_t> val4MultiplicationLhs { 5686, 78 };
	constexpr fraction<std::int32_t> val1MultiplicationRhs { -4, 1 };
	constexpr fraction<std::int32_t> val2MultiplicationRhs { -102505, 1113759 };
	constexpr fraction_t val3MultiplicationRhs { -12714, 8083975 };
	constexpr fraction_t val4MultiplicationRhs { 0, 1 };

	constexpr fraction_t val1Actual { val1MultiplicationLhs * val1MultiplicationRhs };
	constexpr fraction_t val2Actual { val2MultiplicationLhs * val2MultiplicationRhs };
	constexpr fraction_t val3Actual { val3MultiplicationLhs * val3MultiplicationRhs };
	constexpr fraction_t val4Actual { val4MultiplicationLhs * val4MultiplicationRhs };

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
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { -83, 141 };
	constexpr fraction_t val3Expected { -12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1MultiplicationLhs { -1, 2 };
	constexpr fraction_t val2MultiplicationLhs { 7899, 1235 };
	constexpr std::int64_t val3MultiplicationLhs { 5 };
	constexpr double val4MultiplicationLhs { 72.89743589743589743589743 };
	constexpr std::int64_t val1MultiplicationRhs { -4 };
	constexpr double val2MultiplicationRhs { -0.09203517098402796296 };
	constexpr fraction_t val3MultiplicationRhs { -12714, 8083975 };
	constexpr fraction_t val4MultiplicationRhs { 0, 1 };

	constexpr fraction_t val1Actual { val1MultiplicationLhs * val1MultiplicationRhs };
	constexpr fraction_t val2Actual { val2MultiplicationLhs * val2MultiplicationRhs };
	constexpr fraction_t val3Actual { val3MultiplicationLhs * val3MultiplicationRhs };
	constexpr fraction_t val4Actual { val4MultiplicationLhs * val4MultiplicationRhs };

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
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { -83, 141 };
	constexpr fraction_t val3Expected { -12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1DivisionLhs { -1, 2 };
	constexpr fraction_t val2DivisionLhs { 7899, 1235 };
	constexpr fraction_t val3DivisionLhs { 5, 1 };
	constexpr fraction_t val4DivisionLhs { 0, 78 };
	constexpr fraction_t val1DivisionRhs { -1, 4 };
	constexpr fraction_t val2DivisionRhs { 1113759 , -102505 };
	constexpr fraction_t val3DivisionRhs { -8083975 , 12714 };
	constexpr fraction_t val4DivisionRhs { 5, 1 };

	constexpr fraction_t val1Actual { val1DivisionLhs / val1DivisionRhs };
	constexpr fraction_t val2Actual { val2DivisionLhs / val2DivisionRhs };
	constexpr fraction_t val3Actual { val3DivisionLhs / val3DivisionRhs };
	constexpr fraction_t val4Actual { val4DivisionLhs / val4DivisionRhs };

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
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { -83, 141 };
	constexpr fraction_t val3Expected { -12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1DivisionLhs { -1, 2 };
	constexpr fraction_t val2DivisionLhs { 7899, 1235 };
	constexpr fraction<std::int32_t> val3DivisionLhs { 5, 1 };
	constexpr fraction<std::int32_t> val4DivisionLhs { 0, 78 };
	constexpr fraction<std::int32_t> val1DivisionRhs { -1, 4 };
	constexpr fraction<std::int32_t> val2DivisionRhs { 1113759 , -102505 };
	constexpr fraction_t val3DivisionRhs { -8083975 , 12714 };
	constexpr fraction_t val4DivisionRhs { 5, 1 };

	constexpr fraction_t val1Actual { val1DivisionLhs / val1DivisionRhs };
	constexpr fraction_t val2Actual { val2DivisionLhs / val2DivisionRhs };
	constexpr fraction_t val3Actual { val3DivisionLhs / val3DivisionRhs };
	constexpr fraction_t val4Actual { val4DivisionLhs / val4DivisionRhs };

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
	constexpr fraction_t val1Expected { 2, 1 };
	constexpr fraction_t val2Expected { -83, 141 };
	constexpr fraction_t val3Expected { -12714, 1616795 };
	constexpr fraction_t val4Expected { 0, 1 };

	constexpr fraction_t val1DivisionLhs { -16, 2 };
	constexpr fraction_t val2DivisionLhs { 7899, 1235 };
	constexpr std::int64_t val3DivisionLhs { 5 };
	constexpr double val4DivisionLhs { 0 };
	constexpr std::int64_t val1DivisionRhs { -4 };
	constexpr double val2DivisionRhs { -10.865411443344227110872 };
	constexpr fraction_t val3DivisionRhs { -8083975 , 12714 };
	constexpr fraction_t val4DivisionRhs { 5, 1 };

	constexpr fraction_t val1Actual { val1DivisionLhs / val1DivisionRhs };
	constexpr fraction_t val2Actual { val2DivisionLhs / val2DivisionRhs };
	constexpr fraction_t val3Actual { val3DivisionLhs / val3DivisionRhs };
	constexpr fraction_t val4Actual { val4DivisionLhs / val4DivisionRhs };

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
