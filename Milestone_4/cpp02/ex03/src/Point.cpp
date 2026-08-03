/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:28:47 by yblanco-          #+#    #+#             */
/*   Updated: 2026/04/17 13:42:55 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{

}
Point::Point(const float fNumberA, const float fNumberB) : _x(Fixed(fNumberA)), _y(Fixed(fNumberB))
{
 
}
Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
   
}

Point &Point::operator=(const Point &other)
{
   (void) other;
   return *this;
}

Point::~Point()
{
    
}

//Geters

Fixed const &Point::getX() const { return _x; }
Fixed const &Point::getY() const { return _y; }