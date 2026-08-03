/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:01:18 by yblanco-          #+#    #+#             */
/*   Updated: 2026/04/17 14:21:10 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed cross(Point n1, Point n2, Point P)
{
    return (n2.getX() - n1.getX()) * (P.getY() - n1.getY()) - 
            (n2.getY() - n1.getY()) * (P.getX() - n1.getX());
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
    Fixed vAB = cross(a, b, point);
    Fixed vBC = cross(b, c, point);
    Fixed vCA = cross(c, a, point);

    return (vAB.getRawBits() * vBC.getRawBits() > 0) && (vBC.getRawBits() * vCA.getRawBits() > 0);
}