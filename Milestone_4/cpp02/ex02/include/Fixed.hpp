/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 10:08:31 by yblanco-          #+#    #+#             */
/*   Updated: 2026/04/17 12:42:24 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int _fixedPoint;
		static const int fBit = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int number);
		Fixed(const float fNumber);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		
		/* ---- OPERATORS ---- */
		//Arithmetic Operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		//Comparison Operators
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		//Increment/Decrement Operators
		//Pre
		Fixed &operator++();
		Fixed &operator--();
		//post
		Fixed operator++(int);
		Fixed operator--(int);

		/* ---- FUNCTIONS ----*/
		
		int							getRawBits( void ) const;
		void						setRawBits( int const raw );
		float						toFloat( void ) const;
		int							toInt( void ) const;
		static			Fixed		&min( Fixed &a, Fixed &b );
		static			Fixed		&max( Fixed &a, Fixed &b );
		static const	Fixed		&min( const Fixed &a, const Fixed &b );
		static const	Fixed		&max( const Fixed &a, const  Fixed &b );
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif