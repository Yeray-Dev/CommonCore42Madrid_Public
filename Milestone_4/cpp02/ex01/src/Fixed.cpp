/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:07:54 by yblanco-          #+#    #+#             */
/*   Updated: 2026/05/31 16:03:51 by yblanco-         ###   ########.fr       */
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