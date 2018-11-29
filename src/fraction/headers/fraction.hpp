//
// Copyright (c) 2018 Yannick Schinko
// Licensed under the MIT License. See LICENSE file in the project root for full license information.
//
#pragma once

#include <cstdint>
#include <limits>
#include <numeric>
#include <ostream>
#include <stdexcept>
#include <type_traits>

////////////////////////////////////////////////////
// Traits and Limits (Forward declaration)
////////////////////////////////////////////////////

template<class T>
struct is_fraction;

// Needs to be defined early
template<
	class T
>
inline constexpr bool is_fraction_v = is_fraction<T>::value;

////////////////////////////////////////////////////
// Declarations
////////////////////////////////////////////////////

template<
	class T = std::int64_t,
	class CHECK_T = typename std::enable_if<std::is_integral<T>::value>::type
>
class fraction {
public:
	// Flags
	static constexpr bool is_signed { std::is_signed<T>::value };
	static constexpr bool is_unsigned { std::is_unsigned<T>::value };

	typedef T value_type;

private:
	// Constants
	static constexpr T ZERO { 0 };
	static constexpr T ONE { 1 };

	// Fields
	T numerator;
	T denominator;

	template<
		class D,
		class CHECK_D = typename std::enable_if<std::is_floating_point<D>::value>::type
	>
	constexpr D abs( const D& value ) const noexcept;

public:
	/// We wanna be friends with ourselves
	template<class T1, class CHECK_T1>
	friend class fraction;

	// Fraction Contrsuctor
	constexpr fraction( const T& numerator = ZERO, const T& denominator = ONE );

	/*!
	 * @brief Floating Point constructor
	 *
	 * This constructor accepts a floating point value and optionally a precision, which defines how much
	 * difference between the value and fraction is allowed.
	 *
	 * The underlying algorithm is explained here: http://jonisalonen.com/2012/converting-decimal-numbers-to-ratios/
	 *
	 * @tparam    T
	 * @tparam    CHECK_T  Used for checking if @p T is an integer type
	 * @tparam    D        Type of the floating point type to calculate the fraction from. Should be autodected
	 * @tparam    CHECK_D  Used for checking if @p D is a floating point type
	 * @param[in] value    The value to calculate the fraction from
	 * @param[in] precison Defines how much the value of the fraction is allowed to deviate from @p value. By default it's 0.0, so not at all
	 *
	 * @throws std::invalid_argument when @p T is @c unsigned and @p value is negative.
	 */
	template<
		class D,
		class CHECK_D = typename std::enable_if<std::is_floating_point<D>::value>::type
	>
	constexpr fraction( const D& value, const D& precison = 0.0 );

	template<
		class T1 = std::int64_t,
		class CHECK_T1 = typename std::enable_if<std::is_integral<T1>::value>::type
	>
	constexpr fraction( const fraction<T1, CHECK_T1>& copy );

	constexpr fraction( const fraction<T, CHECK_T>& copy ) noexcept = default;

	constexpr const T& getNumerator() const noexcept;
	constexpr const T& getDenominator() const noexcept;

	// Assignment operators
	constexpr fraction<T, CHECK_T>& operator=( const fraction<T, CHECK_T>& rhs ) noexcept = default;

	// Relational operators
	template<class T1, class CHECK_T1, class T2, class CHECK_T2, class COMMON, class CHECK_COMMON>
	friend constexpr bool operator==( const fraction<T1, CHECK_T1>& lhs, const fraction<T2, CHECK_T2>& rhs );
	template<class T1, class CHECK_T1>
	friend constexpr bool operator==( const fraction<T1, CHECK_T1>& lhs, const fraction<T1, CHECK_T1>& rhs ) noexcept;
	template<class T1, class CHECK_T1, class D, class CHECK_D>
	friend constexpr bool operator==( const fraction<T1, CHECK_T1>& lhs, const D& rhs );
	template<class D, class T1, class CHECK_T1, class CHECK_D>
	friend constexpr bool operator==( const D& lhs, const fraction<T1, CHECK_T1>& rhs );

	template<class T1, class CHECK_T1, class T2, class CHECK_T2, class COMMON, class CHECK_COMMON>
	friend constexpr bool operator!=( const fraction<T1, CHECK_T1>& lhs, const fraction<T2, CHECK_T2>& rhs );
	template<class T1, class CHECK_T1>
	friend constexpr bool operator!=( const fraction<T1, CHECK_T1>& lhs, const fraction<T1, CHECK_T1>& rhs ) noexcept;
	template<class T1, class CHECK_T1, class D, class CHECK_D>
	friend constexpr bool operator!=( const fraction<T1, CHECK_T1>& lhs, const D& rhs );
	template<class D, class T1, class CHECK_T1, class CHECK_D>
	friend constexpr bool operator!=( const D& lhs, const fraction<T1, CHECK_T1>& rhs );

	// TODO: operator<
	// TODO: operator>
	// TODO: operator<=
	// TODO: operator>=

	// Arithmetic operators

	constexpr fraction<T, CHECK_T>& operator+=( const fraction<T, CHECK_T>& rhs );

	template<class T1, class CHECK_T1, class T2, class CHECK_T2, class COMMON, class CHECK_COMMON>
	friend constexpr fraction<COMMON, CHECK_COMMON> operator+( const fraction<T1, CHECK_T1>& lhs, const fraction<T2, CHECK_T2>& rhs );
	template<class T1, class CHECK_T1>
	friend constexpr fraction<T1, CHECK_T1> operator+( const fraction<T1, CHECK_T1>& lhs, const fraction<T1, CHECK_T1>& rhs );
	template<class T1, class CHECK_T1, class D, class CHECK_D>
	friend constexpr fraction<T1, CHECK_T1> operator+( const fraction<T1, CHECK_T1>& lhs, const D& rhs );
	template<class D, class T1, class CHECK_T1, class CHECK_D>
	friend constexpr fraction<T1, CHECK_T1> operator+( const D& lhs, const fraction<T1, CHECK_T1>& rhs );


	constexpr fraction<T, CHECK_T>& operator-=( const fraction<T, CHECK_T>& rhs );

	template<class T1, class CHECK_T1, class T2, class CHECK_T2, class COMMON, class CHECK_COMMON>
	friend constexpr fraction<COMMON, CHECK_COMMON> operator-( const fraction<T1, CHECK_T1>& lhs, const fraction<T2, CHECK_T2>& rhs );
	template<class T1, class CHECK_T1>
	friend constexpr fraction<T1, CHECK_T1> operator-( const fraction<T1, CHECK_T1>& lhs, const fraction<T1, CHECK_T1>& rhs );
	template<class T1, class CHECK_T1, class D, class CHECK_D>
	friend constexpr fraction<T1, CHECK_T1> operator-( const fraction<T1, CHECK_T1>& lhs, const D& rhs );
	template<class D, class T1, class CHECK_T1, class CHECK_D>
	friend constexpr fraction<T1, CHECK_T1> operator-( const D& lhs, const fraction<T1, CHECK_T1>& rhs );


	constexpr fraction<T, CHECK_T>& operator*=( const fraction<T, CHECK_T>& rhs );

	template<class T1, class CHECK_T1, class T2, class CHECK_T2, class COMMON, class CHECK_COMMON>
	friend constexpr fraction<COMMON, CHECK_COMMON> operator*( const fraction<T1, CHECK_T1>& lhs, const fraction<T2, CHECK_T2>& rhs );
	template<class T1, class CHECK_T1>
	friend constexpr fraction<T1, CHECK_T1> operator*( const fraction<T1, CHECK_T1>& lhs, const fraction<T1, CHECK_T1>& rhs );
	template<class T1, class CHECK_T1, class D, class CHECK_D>
	friend constexpr fraction<T1, CHECK_T1> operator*( const fraction<T1, CHECK_T1>& lhs, const D& rhs );
	template<class D, class T1, class CHECK_T1, class CHECK_D>
	friend constexpr fraction<T1, CHECK_T1> operator*( const D& lhs, const fraction<T1, CHECK_T1>& rhs );


	constexpr fraction<T, CHECK_T>& operator/=( const fraction<T, CHECK_T>& rhs );

	template<class T1, class CHECK_T1, class T2, class CHECK_T2, class COMMON, class CHECK_COMMON>
	friend constexpr fraction<COMMON, CHECK_COMMON> operator/( const fraction<T1, CHECK_T1>& lhs, const fraction<T2, CHECK_T2>& rhs );
	template<class T1, class CHECK_T1>
	friend constexpr fraction<T1, CHECK_T1> operator/( const fraction<T1, CHECK_T1>& lhs, const fraction<T1, CHECK_T1>& rhs );
	template<class T1, class CHECK_T1, class D, class CHECK_D>
	friend constexpr fraction<T1, CHECK_T1> operator/( const fraction<T1, CHECK_T1>& lhs, const D& rhs );
	template<class D, class T1, class CHECK_T1, class CHECK_D>
	friend constexpr fraction<T1, CHECK_T1> operator/( const D& lhs, const fraction<T1, CHECK_T1>& rhs );


	constexpr fraction<T, CHECK_T>& operator++();
	constexpr fraction<T, CHECK_T> operator++( int );


	constexpr fraction<T, CHECK_T>& operator--();
	constexpr fraction<T, CHECK_T> operator--( int );


	template<class T1, class CHECK_T1>
	friend constexpr fraction<T1, CHECK_T1> operator+( const fraction<T1, CHECK_T1>& rhs ) noexcept;
	template<class T1, class CHECK_T1>
	friend constexpr fraction<T1, CHECK_T1> operator-( const fraction<T1, CHECK_T1>& rhs );

	// Conversion operators
	template<
		class D,
		class CHECK_D = typename std::enable_if<std::is_arithmetic<D>::value && !is_fraction<D>::value>::type
	>
	constexpr operator D() const noexcept;

	// Stream operators
	template<class charT, class traits, class T1, class CHECK_T1>
	friend std::basic_ostream<charT, traits>& operator<<( std::basic_ostream<charT, traits>& ostream, const fraction<T1, CHECK_T1>& fraction );

	// TODO: operator>> (maybe)

private:
	constexpr void reduce();
};

////////////////////////////////////////////////////
// Friends
////////////////////////////////////////////////////

// Relational operators
template<
	class T1,
	class CHECK_T1,
	class T2,
	class CHECK_T2,
	class COMMON = typename std::common_type<T1, T2>::type,
	class CHECK_COMMON = typename std::enable_if<!std::is_same<T1, T2>::value && std::is_integral<COMMON>::value>::type
>
constexpr bool operator==( const fraction<T1, CHECK_T1>& lhs, const fraction<T2, CHECK_T2>& rhs );
template<
	class T1,
	class CHECK_T1
>
constexpr bool operator==( const fraction<T1, CHECK_T1>& lhs, const fraction<T1, CHECK_T1>& rhs ) noexcept;
template<
	class T1,
	class CHECK_T1,
	class D,
	class CHECK_D = typename std::enable_if<std::is_arithmetic<D>::value && !is_fraction<D>::value>::type
>
constexpr bool operator==( const fraction<T1, CHECK_T1>& lhs, const D& rhs );
template<
	class D,
	class T1,
	class CHECK_T1,
	class CHECK_D = typename std::enable_if<std::is_arithmetic<D>::value && !is_fraction<D>::value>::type
>
constexpr bool operator==( const D& lhs, const fraction<T1, CHECK_T1>& rhs );

template<
	class T1,
	class CHECK_T1,
	class T2,
	class CHECK_T2,
	class COMMON = typename std::common_type<T1, T2>::type,
	class CHECK_COMMON = typename std::enable_if<!std::is_same<T1, T2>::value && std::is_integral<COMMON>::value>::type
>
constexpr bool operator!=( const fraction<T1, CHECK_T1>& lhs, const fraction<T2, CHECK_T2>& rhs );
template<
	class T1,
	class CHECK_T1
>
constexpr bool operator!=( const fraction<T1, CHECK_T1>& lhs, const fraction<T1, CHECK_T1>& rhs ) noexcept;
template<
	class T1,
	class CHECK_T1,
	class D,
	class CHECK_D = typename std::enable_if<std::is_arithmetic<D>::value && !is_fraction<D>::value>::type
>
constexpr bool operator!=( const fraction<T1, CHECK_T1>& lhs, const D& rhs );
template<
	class D,
	class T1,
	class CHECK_T1,
	class CHECK_D = typename std::enable_if<std::is_arithmetic<D>::value && !is_fraction<D>::value>::type
>
constexpr bool operator!=( const D& lhs, const fraction<T1, CHECK_T1>& rhs );

// Arithmetic operators
template<
	class T1,
	class CHECK_T1,
	class T2,
	class CHECK_T2,
	class COMMON = typename std::common_type<T1, T2>::type,
	class CHECK_COMMON = typename std::enable_if<!std::is_same<T1, T2>::value && std::is_integral<COMMON>::value>::type
>
constexpr fraction<COMMON, CHECK_COMMON> operator+( const fraction<T1, CHECK_T1>& lhs, const fraction<T2, CHECK_T2>& rhs );
template<
	class T1,
	class CHECK_T1
>
constexpr fraction<T1, CHECK_T1> operator+( const fraction<T1, CHECK_T1>& lhs, const fraction<T1, CHECK_T1>& rhs );
template<
	class T1,
	class CHECK_T1,
	class D,
	class CHECK_D = typename std::enable_if<std::is_arithmetic<D>::value && !is_fraction<D>::value>::type
>
constexpr fraction<T1, CHECK_T1> operator+( const fraction<T1, CHECK_T1>& lhs, const D& rhs );
template<
	class D,
	class T1,
	class CHECK_T1,
	class CHECK_D = typename std::enable_if<std::is_arithmetic<D>::value && !is_fraction<D>::value>::type
>
constexpr fraction<T1, CHECK_T1> operator+( const D& lhs, const fraction<T1, CHECK_T1>& rhs );

template<
	class T1,
	class CHECK_T1,
	class T2,
	class CHECK_T2,
	class COMMON = typename std::common_type<T1, T2>::type,
	class CHECK_COMMON = typename std::enable_if<!std::is_same<T1, T2>::value && std::is_integral<COMMON>::value>::type
>
constexpr fraction<COMMON, CHECK_COMMON> operator-( const fraction<T1, CHECK_T1>& lhs, const fraction<T2, CHECK_T2>& rhs );
template<
	class T1,
	class CHECK_T1
>
constexpr fraction<T1, CHECK_T1> operator-( const fraction<T1, CHECK_T1>& lhs, const fraction<T1, CHECK_T1>& rhs );
template<
	class T1,
	class CHECK_T1,
	class D,
	class CHECK_D = typename std::enable_if<std::is_arithmetic<D>::value && !is_fraction<D>::value>::type
>
constexpr fraction<T1, CHECK_T1> operator-( const fraction<T1, CHECK_T1>& lhs, const D& rhs );
template<
	class D,
	class T1,
	class CHECK_T1,
	class CHECK_D = typename std::enable_if<std::is_arithmetic<D>::value && !is_fraction<D>::value>::type
>
constexpr fraction<T1, CHECK_T1> operator-( const D& lhs, const fraction<T1, CHECK_T1>& rhs );

template<
	class T1,
	class CHECK_T1,
	class T2,
	class CHECK_T2,
	class COMMON = typename std::common_type<T1, T2>::type,
	class CHECK_COMMON = typename std::enable_if<!std::is_same<T1, T2>::value && std::is_integral<COMMON>::value>::type
>
constexpr fraction<COMMON, CHECK_COMMON> operator*( const fraction<T1, CHECK_T1>& lhs, const fraction<T2, CHECK_T2>& rhs );
template<
	class T1,
	class CHECK_T1
>
constexpr fraction<T1, CHECK_T1> operator*( const fraction<T1, CHECK_T1>& lhs, const fraction<T1, CHECK_T1>& rhs );
template<
	class T1,
	class CHECK_T1,
	class D,
	class CHECK_D = typename std::enable_if<std::is_arithmetic<D>::value && !is_fraction<D>::value>::type
>
constexpr fraction<T1, CHECK_T1> operator*( const fraction<T1, CHECK_T1>& lhs, const D& rhs );
template<
	class D,
	class T1,
	class CHECK_T1,
	class CHECK_D = typename std::enable_if<std::is_arithmetic<D>::value && !is_fraction<D>::value>::type
>
constexpr fraction<T1, CHECK_T1> operator*( const D& lhs, const fraction<T1, CHECK_T1>& rhs );

template<
	class T1,
	class CHECK_T1,
	class T2,
	class CHECK_T2,
	class COMMON = typename std::common_type<T1, T2>::type,
	class CHECK_COMMON = typename std::enable_if<!std::is_same<T1, T2>::value && std::is_integral<COMMON>::value>::type
>
constexpr fraction<COMMON, CHECK_COMMON> operator/( const fraction<T1, CHECK_T1>& lhs, const fraction<T2, CHECK_T2>& rhs );
template<
	class T1,
	class CHECK_T1
>
constexpr fraction<T1, CHECK_T1> operator/( const fraction<T1, CHECK_T1>& lhs, const fraction<T1, CHECK_T1>& rhs );
template<
	class T1,
	class CHECK_T1,
	class D,
	class CHECK_D = typename std::enable_if<std::is_arithmetic<D>::value && !is_fraction<D>::value>::type
>
constexpr fraction<T1, CHECK_T1> operator/( const fraction<T1, CHECK_T1>& lhs, const D& rhs );
template<
	class D,
	class T1,
	class CHECK_T1,
	class CHECK_D = typename std::enable_if<std::is_arithmetic<D>::value && !is_fraction<D>::value>::type
>
constexpr fraction<T1, CHECK_T1> operator/( const D& lhs, const fraction<T1, CHECK_T1>& rhs );

template<
	class T1,
	class CHECK_T1
>
constexpr fraction<T1, CHECK_T1> operator+( const fraction<T1, CHECK_T1>& rhs ) noexcept;
template<
	class T1,
	class CHECK_T1
>
constexpr fraction<T1, CHECK_T1> operator-( const fraction<T1, CHECK_T1>& rhs );

// Stream operators
template<
	class charT,
	class traits,
	class T1,
	class CHECK_T1
>
std::basic_ostream<charT, traits>& operator<<( std::basic_ostream<charT, traits>& ostream, const fraction<T1, CHECK_T1>& fraction );

////////////////////////////////////////////////////
// Traits and Limits
////////////////////////////////////////////////////

template<
	class T
>
struct is_fraction : std::false_type {};

template<
	class T,
	class CHECK_T
>
struct is_fraction<fraction<T, CHECK_T>> : std::true_type {};

namespace std {
	template<
		class T,
		class CHECK_T
	>
	struct is_floating_point<fraction<T, CHECK_T>> : true_type {};

	template<
		class T,
		class CHECK_T
	>
	struct is_signed<fraction<T, CHECK_T>> : integral_constant<bool, fraction<T, CHECK_T>::is_signed> {};
	template<
		class T,
		class CHECK_T
	>
	struct is_unsigned<fraction<T, CHECK_T>> : integral_constant<bool, fraction<T, CHECK_T>::is_unsigned> {};

	template<
		class T1,
		class CHECK_T1,
		class T2,
		class CHECK_T2
	>
	struct common_type<fraction<T1, CHECK_T1>, fraction<T2, CHECK_T2>> {
		typedef fraction<typename std::common_type<T1, T2>::type> type;
	};

	template<
		class T,
		class CHECK_T
	>
	class numeric_limits<fraction<T, CHECK_T>> {
		public:
			static constexpr bool is_specialized { true };
			static constexpr fraction<T, CHECK_T> min() noexcept;
			static constexpr fraction<T, CHECK_T> max() noexcept;
			static constexpr fraction<T, CHECK_T> lowest() noexcept;
			static constexpr int digits = numeric_limits<T>::digits;
			static constexpr int digits10 = numeric_limits<T>::digits10;
			static constexpr bool is_signed = fraction<T, CHECK_T>::is_signed;
			static constexpr bool is_integer = false;
			static constexpr bool is_exact = numeric_limits<T>::is_exact;
			static constexpr int radix = numeric_limits<T>::radix;
			static constexpr fraction<T, CHECK_T> epsilon() noexcept;
			static constexpr fraction<T, CHECK_T> round_error() noexcept;

			static constexpr int max_exponent = 0;
			static constexpr int max_exponent10 = 0;
			static constexpr int min_exponent = 0;
			static constexpr int min_exponent10 = 0;

			static constexpr bool has_infinity = false;
			static constexpr bool has_quiet_NaN = false;
			static constexpr bool has_signaling_NaN = false;
			static constexpr float_denorm_style has_denorm = denorm_absent;
			static constexpr bool has_denorm_loss = false;
			static constexpr fraction<T, CHECK_T> infinity() noexcept;
			static constexpr fraction<T, CHECK_T> quiet_NaN() noexcept;
			static constexpr fraction<T, CHECK_T> signaling_NaN() noexcept;
			static constexpr fraction<T, CHECK_T> denorm_min() noexcept;

			static constexpr bool is_iec559 = false;
			static constexpr bool is_bounded = numeric_limits<T>::is_bounded;
			static constexpr bool is_modulo = numeric_limits<T>::is_modulo;

			static constexpr bool traps = false;
			static constexpr bool tinyness_before = false;
			static constexpr float_round_style round_style = round_to_nearest;
	};
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Implementation
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T, class CHECK_T>
template<class D, class CHECK_D>
inline constexpr D fraction<T, CHECK_T>::abs( const D& value ) const noexcept {
	if ( value < D{ 0 } )
		return -value;
	else
		return value;
}

template<class T, class CHECK_T>
inline constexpr fraction<T, CHECK_T>::fraction( const T& numerator, const T& denominator ) :
	numerator { numerator },
	denominator { denominator } {
	reduce();
}

template<class T, class CHECK_T>
template<class D, class CHECK_D>
inline constexpr fraction<T, CHECK_T>::fraction( const D& value, const D& precison ) :
	numerator {},
	denominator {} {
	T digitT {};

	const bool negative = value < D{ 0 };

	if constexpr ( is_unsigned )
		if ( negative )
			throw std::invalid_argument( "The value needs to be positive, since the base interger type is unsigned!" );

	const D posValue { negative ? -value : value };
	D rest { posValue };

	T n1 { ONE };
	T n2 { ZERO };
	T d1 { ZERO };
	T d2 { ONE };
	T tmp {};

	while ( true ) {
		digitT = static_cast<T>(rest);

		tmp = n1;
		n1 = (digitT * n1) + n2;
		n2 = tmp;

		tmp = d1;
		d1 = (digitT * d1) + d2;
		d2 = tmp;

		if ( fraction<T, CHECK_T>::abs( (static_cast<D>(n1) / static_cast<D>(d1)) - posValue ) <= precison )
			break;

		rest = D{ 1 } / (rest - static_cast<D>(digitT));
	}

	if constexpr ( is_signed )
		numerator = negative ? -n1 : n1;
	else
		numerator = n1;
	denominator = d1;
}

template<class T, class CHECK_T>
template<class T1, class CHECK_T1>
inline constexpr fraction<T, CHECK_T>::fraction( const fraction<T1, CHECK_T1>& copy ) :
	fraction( static_cast<T>(copy.numerator), static_cast<T>(copy.denominator) ) {}

template<class T, class CHECK_T>
inline constexpr const T& fraction<T, CHECK_T>::getNumerator() const noexcept {
	return numerator;
}

template<class T, class CHECK_T>
inline constexpr const T& fraction<T, CHECK_T>::getDenominator() const noexcept {
	return denominator;
}

template<class T1, class CHECK_T1, class T2, class CHECK_T2, class COMMON, class CHECK_COMMON>
inline constexpr bool operator==( const fraction<T1, CHECK_T1>& lhs, const fraction<T2, CHECK_T2>& rhs ) {
	return fraction<COMMON, CHECK_COMMON>{ lhs } == fraction<COMMON, CHECK_COMMON>{ rhs };
}

template<class T1, class CHECK_T1>
inline constexpr bool operator==( const fraction<T1, CHECK_T1>& lhs, const fraction<T1, CHECK_T1>& rhs ) noexcept {
	return (lhs.numerator == rhs.numerator) && (lhs.denominator == rhs.denominator);
}

template<class T1, class CHECK_T1, class D, class CHECK_D>
inline constexpr bool operator==( const fraction<T1, CHECK_T1>& lhs, const D & rhs ) {
	return lhs == fraction<T1, CHECK_T1>{ rhs };
}

template<class D, class T1, class CHECK_T1, class CHECK_D>
inline constexpr bool operator==( const D & lhs, const fraction<T1, CHECK_T1>& rhs ) {
	return rhs == lhs;
}

template<class T1, class CHECK_T1, class T2, class CHECK_T2, class COMMON, class CHECK_COMMON>
inline constexpr bool operator!=( const fraction<T1, CHECK_T1>& lhs, const fraction<T2, CHECK_T2>& rhs ) {
	return !(lhs == rhs);
}

template<class T1, class CHECK_T1>
inline constexpr bool operator!=( const fraction<T1, CHECK_T1>& lhs, const fraction<T1, CHECK_T1>& rhs ) noexcept {
	return !(lhs == rhs);
}

template<class T1, class CHECK_T1, class D, class CHECK_D>
inline constexpr bool operator!=( const fraction<T1, CHECK_T1>& lhs, const D & rhs ) {
	return !(lhs == rhs);
}

template<class D, class T1, class CHECK_T1, class CHECK_D>
inline constexpr bool operator!=( const D & lhs, const fraction<T1, CHECK_T1>& rhs ) {
	return rhs != lhs;
}

template<class T, class CHECK_T>
inline constexpr fraction<T, CHECK_T>& fraction<T, CHECK_T>::operator+=( const fraction<T, CHECK_T>& rhs ) {
	const T lcm { std::lcm( denominator, rhs.denominator ) };

	numerator = (numerator * (lcm / denominator)) + (rhs.numerator * (lcm / rhs.denominator));
	denominator = lcm;

	reduce();

	return *this;
}

template<class T1, class CHECK_T1, class T2, class CHECK_T2, class COMMON, class CHECK_COMMON>
inline constexpr fraction<COMMON, CHECK_COMMON> operator+( const fraction<T1, CHECK_T1>& lhs, const fraction<T2, CHECK_T2>& rhs ) {
	fraction<COMMON, CHECK_COMMON> out { lhs };
	out += rhs;

	return out;
}

template<class T1, class CHECK_T1>
inline constexpr fraction<T1, CHECK_T1> operator+( const fraction<T1, CHECK_T1>& lhs, const fraction<T1, CHECK_T1>& rhs ) {
	fraction<T1, CHECK_T1> out { lhs };
	out += rhs;

	return out;
}

template<class T1, class CHECK_T1, class D, class CHECK_D>
inline constexpr fraction<T1, CHECK_T1> operator+( const fraction<T1, CHECK_T1>& lhs, const D & rhs ) {
	return lhs + fraction<T1, CHECK_T1>{ rhs };
}

template<class D, class T1, class CHECK_T1, class CHECK_D>
inline constexpr fraction<T1, CHECK_T1> operator+( const D & lhs, const fraction<T1, CHECK_T1>& rhs ) {
	return rhs + lhs;
}

template<class T, class CHECK_T>
inline constexpr fraction<T, CHECK_T>& fraction<T, CHECK_T>::operator-=( const fraction<T, CHECK_T>& rhs ) {
	const T lcm { std::lcm( denominator, rhs.denominator ) };

	numerator = (numerator * (lcm / denominator)) - (rhs.numerator * (lcm / rhs.denominator));
	denominator = lcm;

	reduce();

	return *this;
}

template<class T1, class CHECK_T1, class T2, class CHECK_T2, class COMMON, class CHECK_COMMON>
inline constexpr fraction<COMMON, CHECK_COMMON> operator-( const fraction<T1, CHECK_T1>& lhs, const fraction<T2, CHECK_T2>& rhs ) {
	fraction<COMMON, CHECK_COMMON> out { lhs };
	out -= rhs;

	return out;
}

template<class T1, class CHECK_T1>
inline constexpr fraction<T1, CHECK_T1> operator-( const fraction<T1, CHECK_T1>& lhs, const fraction<T1, CHECK_T1>& rhs ) {
	fraction<T1, CHECK_T1> out { lhs };
	out -= rhs;

	return out;
}

template<class T1, class CHECK_T1, class D, class CHECK_D>
inline constexpr fraction<T1, CHECK_T1> operator-( const fraction<T1, CHECK_T1>& lhs, const D & rhs ) {
	return lhs - fraction<T1, CHECK_T1>{ rhs };
}

template<class D, class T1, class CHECK_T1, class CHECK_D>
inline constexpr fraction<T1, CHECK_T1> operator-( const D & lhs, const fraction<T1, CHECK_T1>& rhs ) {
	return fraction<T1, CHECK_T1>{ lhs } -rhs;
}

template<class T, class CHECK_T>
inline constexpr fraction<T, CHECK_T>& fraction<T, CHECK_T>::operator*=( const fraction<T, CHECK_T>& rhs ) {
	numerator *= rhs.numerator;
	denominator *= rhs.denominator;

	reduce();

	return *this;
}

template<class T1, class CHECK_T1, class T2, class CHECK_T2, class COMMON, class CHECK_COMMON>
inline constexpr fraction<COMMON, CHECK_COMMON> operator*( const fraction<T1, CHECK_T1>& lhs, const fraction<T2, CHECK_T2>& rhs ) {
	fraction<COMMON, CHECK_COMMON> out { lhs };
	out *= rhs;

	return out;
}

template<class T1, class CHECK_T1>
inline constexpr fraction<T1, CHECK_T1> operator*( const fraction<T1, CHECK_T1>& lhs, const fraction<T1, CHECK_T1>& rhs ) {
	fraction<T1, CHECK_T1> out { lhs };
	out *= rhs;

	return out;
}

template<class T1, class CHECK_T1, class D, class CHECK_D>
inline constexpr fraction<T1, CHECK_T1> operator*( const fraction<T1, CHECK_T1>& lhs, const D & rhs ) {
	return lhs * fraction<T1, CHECK_T1>{ rhs };
}

template<class D, class T1, class CHECK_T1, class CHECK_D>
inline constexpr fraction<T1, CHECK_T1> operator*( const D & lhs, const fraction<T1, CHECK_T1>& rhs ) {
	return rhs * lhs;
}

template<class T, class CHECK_T>
inline constexpr fraction<T, CHECK_T>& fraction<T, CHECK_T>::operator/=( const fraction<T, CHECK_T>& rhs ) {
	numerator *= rhs.denominator;
	denominator *= rhs.numerator;

	reduce();

	return *this;
}

template<class T1, class CHECK_T1, class T2, class CHECK_T2, class COMMON, class CHECK_COMMON>
inline constexpr fraction<COMMON, CHECK_COMMON> operator/( const fraction<T1, CHECK_T1>& lhs, const fraction<T2, CHECK_T2>& rhs ) {
	fraction<COMMON, CHECK_COMMON> out { lhs };
	out /= rhs;

	return out;
}

template<class T1, class CHECK_T1>
inline constexpr fraction<T1, CHECK_T1> operator/( const fraction<T1, CHECK_T1>& lhs, const fraction<T1, CHECK_T1>& rhs ) {
	fraction<T1, CHECK_T1> out { lhs };
	out /= rhs;

	return out;
}

template<class T1, class CHECK_T1, class D, class CHECK_D>
inline constexpr fraction<T1, CHECK_T1> operator/( const fraction<T1, CHECK_T1>& lhs, const D & rhs ) {
	return lhs / fraction<T1, CHECK_T1>{ rhs };
}

template<class D, class T1, class CHECK_T1, class CHECK_D>
inline constexpr fraction<T1, CHECK_T1> operator/( const D & lhs, const fraction<T1, CHECK_T1>& rhs ) {
	return fraction<T1, CHECK_T1>{ lhs } / rhs;
}

template<class T, class CHECK_T>
inline constexpr fraction<T, CHECK_T>& fraction<T, CHECK_T>::operator++() {
	numerator += denominator;

	// Just in case of interger overflow
	reduce();

	return *this;
}

template<class T, class CHECK_T>
inline constexpr fraction<T, CHECK_T> fraction<T, CHECK_T>::operator++( int ) {
	const fraction<T, CHECK_T> copy( *this );

	operator++();

	return copy;
}

template<class T, class CHECK_T>
inline constexpr fraction<T, CHECK_T>& fraction<T, CHECK_T>::operator--() {
	numerator -= denominator;

	// Just in case of interger overflow
	reduce();

	return *this;
}

template<class T, class CHECK_T>
inline constexpr fraction<T, CHECK_T> fraction<T, CHECK_T>::operator--( int ) {
	const fraction<T, CHECK_T> copy( *this );

	operator--();

	return copy;
}

template<class T1, class CHECK_T1>
inline constexpr fraction<T1, CHECK_T1> operator+( const fraction<T1, CHECK_T1>& rhs ) noexcept {
	return fraction<T1, CHECK_T1>{ rhs };
}

template<class T1, class CHECK_T1>
inline constexpr fraction<T1, CHECK_T1> operator-( const fraction<T1, CHECK_T1>& rhs ) {
	return fraction<T1, CHECK_T1>{ -rhs.numerator, rhs.denominator };
}

template<class T, class CHECK_T>
template<class D, class CHECK_D>
inline constexpr fraction<T, CHECK_T>::operator D() const noexcept {
	return static_cast<D>(numerator) / static_cast<D>(denominator);
}

template<class charT, class traits, class T1, class CHECK_T1>
inline std::basic_ostream<charT, traits>& operator<<( std::basic_ostream<charT, traits>& ostream, const fraction<T1, CHECK_T1>& fraction ) {
	ostream << fraction.numerator << charT { '/' } << fraction.denominator;

	return ostream;
}

template<class T, class CHECK_T>
inline constexpr void fraction<T, CHECK_T>::reduce() {
	if ( denominator == ZERO )
		throw std::invalid_argument( "The denominator must not be 0!" );

	const T gcd { std::gcd( numerator, denominator ) };

	numerator /= gcd;
	denominator /= gcd;

	if constexpr ( is_signed ) {
		if ( denominator < ZERO ) {
			numerator = -numerator;
			denominator = -denominator;
		}
	}
}

namespace std {
	template<class T, class CHECK_T>
	constexpr fraction<T, CHECK_T> numeric_limits<fraction<T, CHECK_T>>::min() noexcept {
		return fraction<T, CHECK_T>{ numeric_limits<T>::min() };
	}

	template<class T, class CHECK_T>
	constexpr fraction<T, CHECK_T> numeric_limits<fraction<T, CHECK_T>>::max() noexcept {
		return fraction<T, CHECK_T>{ numeric_limits<T>::max() };
	}

	template<class T, class CHECK_T>
	constexpr fraction<T, CHECK_T> numeric_limits<fraction<T, CHECK_T>>::lowest() noexcept {
		return min();
	}

	template<class T, class CHECK_T>
	constexpr fraction<T, CHECK_T> numeric_limits<fraction<T, CHECK_T>>::epsilon() noexcept {
		return fraction<T, CHECK_T>{ 1, numeric_limits<T>::max() };
	}

	template<class T, class CHECK_T>
	constexpr fraction<T, CHECK_T> numeric_limits<fraction<T, CHECK_T>>::round_error() noexcept {
		return epsilon();
	}

	template<class T, class CHECK_T>
	constexpr fraction<T, CHECK_T> numeric_limits<fraction<T, CHECK_T>>::infinity() noexcept {
		return fraction<T, CHECK_T>{};
	}

	template<class T, class CHECK_T>
	constexpr fraction<T, CHECK_T> numeric_limits<fraction<T, CHECK_T>>::quiet_NaN() noexcept {
		return fraction<T, CHECK_T>{};
	}

	template<class T, class CHECK_T>
	constexpr fraction<T, CHECK_T> numeric_limits<fraction<T, CHECK_T>>::signaling_NaN() noexcept {
		return fraction<T, CHECK_T>{};
	}

	template<class T, class CHECK_T>
	constexpr fraction<T, CHECK_T> numeric_limits<fraction<T, CHECK_T>>::denorm_min() noexcept {
		return fraction<T, CHECK_T>{};
	}
}
