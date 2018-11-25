//
// Copyright (c) 2018 Yannick Schinko
// Licensed under the MIT License. See LICENSE file in the project root for full license information.
//
#pragma once

#include <cstdint>
#include <numeric>
#include <stdexcept>
#include <type_traits>

template<
	class T = std::int64_t,
	class = typename std::enable_if<std::is_integral<T>::value>::type
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

public:
	// Fraction Contrsuctor
	constexpr fraction( T numerator = ZERO, T denominator = ONE );

	// Floating Point constructor
	template<
		class D,
		class = typename std::enable_if<std::is_floating_point<D>::value>::type
	>
	constexpr fraction( D value, D precison = 0 );

	constexpr fraction( const fraction<T>& copy ) = default;

	constexpr const T& getNumerator() const noexcept;
	constexpr const T& getDenominator() const noexcept;
	
	// Assignment operator
	constexpr fraction<T>& operator=( const fraction<T>& rhs ) noexcept = default;

	// Relational operators
	constexpr bool operator==( const fraction<T>& rhs ) const noexcept;
	constexpr bool operator!=( const fraction<T>& rhs ) const noexcept;

private:
	constexpr void reduce();
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Implementation
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T, class CHECK>
inline constexpr fraction<T, CHECK>::fraction( T numerator, T denominator ) :
	numerator( numerator ),
	denominator( denominator ) {
	reduce();
}

template<class T, class CHECK>
template<class D, class CHECK2>
inline constexpr fraction<T, CHECK>::fraction( D value, D precison ) {}

template<class T, class CHECK>
inline constexpr const T& fraction<T, CHECK>::getNumerator() const noexcept {
	return numerator;
}

template<class T, class CHECK>
inline constexpr const T& fraction<T, CHECK>::getDenominator() const noexcept {
	return denominator;
}

template<class T, class CHECK>
inline constexpr bool fraction<T, CHECK>::operator==( const fraction<T>& rhs ) const noexcept {
	return (numerator == rhs.numerator) && (denominator == rhs.denominator);
}

template<class T, class CHECK>
inline constexpr bool fraction<T, CHECK>::operator!=( const fraction<T>& rhs ) const noexcept {
	return !(operator==(rhs));
}

template<class T, class CHECK>
inline constexpr void fraction<T, CHECK>::reduce() {
	if ( denominator == ZERO )
		throw std::invalid_argument("The denominator must not be 0!");

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
