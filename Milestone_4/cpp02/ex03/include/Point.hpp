/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:19:25 by yblanco-          #+#    #+#             */
/*   Updated: 2026/05/31 15:58:30 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "../include/Fixed.hpp"

class Point{
    private:
        const Fixed _x;
        const Fixed _y;
    public:
        Point();
        Point(const float fNumberA, const float fNumberB);
        Point(const Point &other);
        Point &operator=(const Point &other);
        ~Point();

        // Getters
        Fixed const &getX() const;
        Fixed const &getY() const;
};

#endif