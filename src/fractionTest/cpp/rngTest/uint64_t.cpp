//
// Copyright (c) 2018 Yannick Schinko
// Licensed under the MIT License. See LICENSE file in the project root for full license information.
//
#include <sstream>

#include <gtest/gtest.h>

#include "defines.hpp"
#include "rngTest\rngUtils.hpp"

#define TEST_CASE_NAME RNGTest_uint64_t

TEST( TEST_CASE_NAME, lessThan ) {
	// First 4 bytes of MD5 hash of test name
	constexpr seed_type seed { 0x780e005c };

	runTest( []( std::size_t caseNr ) {
		const ufraction_t val1 { nextUint64NoZero(), nextUint64() };
		const ufraction_t val2 { nextUint64NoZero(), nextUint64() };

		const double val1Double { static_cast<double>(val1) };
		const double val2Double { static_cast<double>(val2) };

		if ( val1Double < val2Double ) {
			EXPECT_LT( val1, val2 ) << "Case: " << caseNr;
		} else if ( val2Double < val1Double ) {
			EXPECT_LT( val2, val1 ) << "Case: " << caseNr;
		}
	}, seed );

	runTest( []( std::size_t caseNr ) {
		const ufraction32_t val1 { nextUint32NoZero(), nextUint32() };
		const ufraction32_t val2 { nextUint32NoZero(), nextUint32() };

		const double val1Double { static_cast<double>(val1) };
		const double val2Double { static_cast<double>(val2) };

		if ( val1Double < val2Double ) {
			EXPECT_LT( val1, val2 ) << "Case: " << caseNr;
		} else if ( val2Double < val1Double ) {
			EXPECT_LT( val2, val1 ) << "Case: " << caseNr;
		}
	}, seed );
}

TEST( TEST_CASE_NAME, greaterThan ) {
	// First 4 bytes of MD5 hash of test name
	constexpr seed_type seed { 0x6d86bbcb };

	runTest( []( std::size_t caseNr ) {
		const ufraction_t val1 { nextUint64NoZero(), nextUint64() };
		const ufraction_t val2 { nextUint64NoZero(), nextUint64() };

		const double val1Double { static_cast<double>(val1) };
		const double val2Double { static_cast<double>(val2) };

		if ( val1Double > val2Double ) {
			EXPECT_GT( val1, val2 ) << "Case: " << caseNr;
		} else if ( val2Double > val1Double ) {
			EXPECT_GT( val2, val1 ) << "Case: " << caseNr;
		}
	}, seed );

	runTest( []( std::size_t caseNr ) {
		const ufraction32_t val1 { nextUint32NoZero(), nextUint32() };
		const ufraction32_t val2 { nextUint32NoZero(), nextUint32() };

		const double val1Double { static_cast<double>(val1) };
		const double val2Double { static_cast<double>(val2) };

		if ( val1Double > val2Double ) {
			EXPECT_GT( val1, val2 ) << "Case: " << caseNr;
		} else if ( val2Double > val1Double ) {
			EXPECT_GT( val2, val1 ) << "Case: " << caseNr;
		}
	}, seed );
}

TEST( TEST_CASE_NAME, lessThanOrEquals ) {
	// First 4 bytes of MD5 hash of test name
	constexpr seed_type seed { 0x688899ca };

	runTest( []( std::size_t caseNr ) {
		const ufraction_t val1 { nextUint64NoZero(), nextUint64() };
		const ufraction_t val2 { nextUint64NoZero(), nextUint64() };

		const double val1Double { static_cast<double>(val1) };
		const double val2Double { static_cast<double>(val2) };

		if ( val1Double <= val2Double ) {
			EXPECT_LE( val1, val2 ) << "Case: " << caseNr;
		} else if ( val2Double <= val1Double ) {
			EXPECT_LE( val2, val1 ) << "Case: " << caseNr;
		}
	}, seed );

	runTest( []( std::size_t caseNr ) {
		const ufraction32_t val1 { nextUint32NoZero(), nextUint32() };
		const ufraction32_t val2 { nextUint32NoZero(), nextUint32() };

		const double val1Double { static_cast<double>(val1) };
		const double val2Double { static_cast<double>(val2) };

		if ( val1Double <= val2Double ) {
			EXPECT_LE( val1, val2 ) << "Case: " << caseNr;
		} else if ( val2Double <= val1Double ) {
			EXPECT_LE( val2, val1 ) << "Case: " << caseNr;
		}
	}, seed );
}

TEST( TEST_CASE_NAME, greaterThanOrEquals ) {
	// First 4 bytes of MD5 hash of test name
	constexpr seed_type seed { 0x8ea5a2e1 };

	runTest( []( std::size_t caseNr ) {
		const ufraction_t val1 { nextUint64NoZero(), nextUint64() };
		const ufraction_t val2 { nextUint64NoZero(), nextUint64() };

		const double val1Double { static_cast<double>(val1) };
		const double val2Double { static_cast<double>(val2) };

		if ( val1Double >= val2Double ) {
			EXPECT_GE( val1, val2 ) << "Case: " << caseNr;
		} else if ( val2Double >= val1Double ) {
			EXPECT_GE( val2, val1 ) << "Case: " << caseNr;
		}
	}, seed );

	runTest( []( std::size_t caseNr ) {
		const ufraction32_t val1 { nextUint32NoZero(), nextUint32() };
		const ufraction32_t val2 { nextUint32NoZero(), nextUint32() };

		const double val1Double { static_cast<double>(val1) };
		const double val2Double { static_cast<double>(val2) };

		if ( val1Double >= val2Double ) {
			EXPECT_GE( val1, val2 ) << "Case: " << caseNr;
		} else if ( val2Double >= val1Double ) {
			EXPECT_GE( val2, val1 ) << "Case: " << caseNr;
		}
	}, seed );
}
