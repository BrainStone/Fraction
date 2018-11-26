//
// Copyright (c) 2018 Yannick Schinko
// Licensed under the MIT License. See LICENSE file in the project root for full license information.
//
#pragma once

#include <cstdint>
#include <numeric>
#include <stdexcept>
#include <type_traits>

//////////////////
// Declarations
//////////////////

template<
	class T = std::int64_t,
	class CHECK_T = typename std::enable_if<std::is_integral<T>::value>::type
>
class fraction {
private:
	// Flags
	static constexpr bool IS_SIGNED { std::is_signed<T>::value };

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

	// Assignment operator
	constexpr fraction<T, CHECK_T>& operator=( const fraction<T, CHECK_T>& rhs ) noexcept = default;

	// Relational operators
	template<class T1, class T2, class COMMON, class CHECK_T1, class CHECK_T2, class CHECK_COMMON>
	friend constexpr bool operator==( const fraction<T1>& lhs, const fraction<T2>& rhs );
	template<class T1, class CHECK_T1>
	friend constexpr bool operator==( const fraction<T1>& lhs, const fraction<T1>& rhs ) noexcept;

	template<class T1, class T2, class COMMON, class CHECK_T1, class CHECK_T2, class CHECK_COMMON>
	friend constexpr bool operator!=( const fraction<T1>& lhs, const fraction<T2>& rhs );
	template<class T1, class CHECK_T1>
	friend constexpr bool operator!=( const fraction<T1>& lhs, const fraction<T1>& rhs ) noexcept;

private:
	constexpr void reduce();
};

//////////////////
// Friends
//////////////////

template<
	class T1,
	class T2,
	class COMMON = typename std::common_type<T1, T2>::type,
	class CHECK_T1 = typename std::enable_if<std::is_integral<T1>::value>::type,
	class CHECK_T2 = typename std::enable_if<std::is_integral<T2>::value>::type,
	class CHECK_COMMON = typename std::enable_if<std::is_integral<COMMON>::value>::type
>
constexpr bool operator==( const fraction<T1>& lhs, const fraction<T2>& rhs );
template<
	class T1,
	class CHECK_T1 = typename std::enable_if<std::is_integral<T1>::value>::type
>
inline constexpr bool operator==( const fraction<T1>& lhs, const fraction<T1>& rhs ) noexcept;

template<
	class T1,
	class T2,
	class COMMON = typename std::common_type<T1, T2>::type,
	class CHECK_T1 = typename std::enable_if<std::is_integral<T1>::value>::type,
	class CHECK_T2 = typename std::enable_if<std::is_integral<T2>::value>::type,
	class CHECK_COMMON = typename std::enable_if<std::is_integral<COMMON>::value>::type
>
constexpr bool operator!=( const fraction<T1>& lhs, const fraction<T2>& rhs );
template<
	class T1,
	class CHECK_T1 = typename std::enable_if<std::is_integral<T1>::value>::type
>
constexpr bool operator!=( const fraction<T1>& lhs, const fraction<T1>& rhs ) noexcept;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Implementation
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T, class CHECK_T>
template<class D, class CHECK_D>
inline constexpr D fraction<T, CHECK_T>::abs( const D& value ) const noexcept {
	if ( value < 0.0 )
		return -value;
	else
		return value;
}

template<class T, class CHECK_T>
inline constexpr fraction<T, CHECK_T>::fraction( const T& numerator, const T& denominator ) :
	numerator( numerator ),
	denominator( denominator ) {
	reduce();
}

template<class T, class CHECK_T>
template<class D, class CHECK_D>
inline constexpr fraction<T, CHECK_T>::fraction( const D& value, const D& precison ) :
	numerator(),
	denominator() {
	T digitT {};

	const bool negative = value < D( 0.0 );

	if constexpr ( !IS_SIGNED )
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

		rest = D( 1.0 ) / (rest - static_cast<D>(digitT));
	}

	if constexpr ( IS_SIGNED )
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

template<class T1, class T2, class COMMON, class CHECK_T1, class CHECK_T2, class CHECK_COMMON>
inline constexpr bool operator==( const fraction<T1>& lhs, const fraction<T2>& rhs ) {
	return fraction<COMMON>( lhs ) == fraction<COMMON>( rhs );
}

template<class T1, class CHECK_T1>
inline constexpr bool operator==( const fraction<T1>& lhs, const fraction<T1>& rhs ) noexcept {
	return (lhs.numerator == rhs.numerator) && (lhs.denominator == rhs.denominator);
}

template<class T1, class T2, class COMMON, class CHECK_T1, class CHECK_T2, class CHECK_COMMON>
inline constexpr bool operator!=( const fraction<T1>& lhs, const fraction<T2>& rhs ) {
	return !(lhs == rhs);
}

template<class T1, class CHECK_T1>
inline constexpr bool operator!=( const fraction<T1>& lhs, const fraction<T1>& rhs ) noexcept {
	return !(lhs == rhs);
}

template<class T, class CHECK_T>
inline constexpr void fraction<T, CHECK_T>::reduce() {
	if ( denominator == ZERO )
		throw std::invalid_argument( "The denominator must not be 0!" );

	const T gcd { std::gcd( numerator, denominator ) };

	numerator /= gcd;
	denominator /= gcd;

	if constexpr ( IS_SIGNED ) {
		if ( denominator < ZERO ) {
			numerator = -numerator;
			denominator = -denominator;
		}
	}
}
