/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:28:32 by yblanco-          #+#    #+#             */
/*   Updated: 2026/04/16 21:25:21 by yblanco-         ###   ########.fr       */
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

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other){
        _fixedPoint = other._fixedPoint;
    }
    std::cout << "Copy assignment operator called\n";
    
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return _fixedPoint;
}

void Fixed::setRawBits( int const raw )
{
    _fixedPoint = raw;
}