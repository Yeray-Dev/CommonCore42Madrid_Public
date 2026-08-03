/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 10:29:05 by yblanco-          #+#    #+#             */
/*   Updated: 2026/05/31 16:04:27 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed()
{
    _fixedPoint = 0;
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other) : _fixedPoint(other._fixedPoint)
{
    std::cout << "Copy constructor called\n";
}

Fixed::Fixed(const int number)
{
    _fixedPoint = number << fBit;
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float fNumber)
{
    _fixedPoint = roundf(fNumber * (1 << fBit));
    std::cout << "Float constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        _fixedPoint = other._fixedPoint;
    std::cout << "Copy assignment operator called\n";
    
    return *this;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
   out << fixed.toFloat();
   return out;
}

float Fixed::toFloat() const

{
    return static_cast<float>(_fixedPoint) / (1 << fBit);
}

int Fixed::toInt() const
{
    return _fixedPoint >> fBit;
}

//Arithmetic Operators

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(toFloat() / other.toFloat());    
}

// Comparison Operators

bool Fixed::operator>(const Fixed &other) const
{
    return toFloat() > other.toFloat();
}

bool Fixed::operator<(const Fixed &other) const
{
    return toFloat() < other.toFloat();
}

bool Fixed::operator>=(const Fixed &other) const
{
    return toFloat() >= other.toFloat();   
}

bool Fixed::operator<=(const Fixed &other) const
{
    return toFloat() <= other.toFloat();   
}

bool Fixed::operator==(const Fixed &other) const
{
    return toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed &other) const
{
    return toFloat() != other.toFloat();
}

Fixed &Fixed::operator++()
{
    _fixedPoint++;
    return *this;
}

Fixed &Fixed::operator--()
{
    _fixedPoint--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    _fixedPoint++;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    _fixedPoint--;
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}