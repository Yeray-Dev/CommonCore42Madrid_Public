/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:21:46 by yblanco-          #+#    #+#             */
/*   Updated: 2026/04/17 14:23:35 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(0, 0);
    Point b(4, 0);
    Point c(0, 4);

    // Caso 1: punto claramente dentro
    Point p1(1, 1);
    std::cout << "Dentro (esperado: 1): " << bsp(a, b, c, p1) << std::endl;

    // Caso 2: punto claramente fuera
    Point p2(5, 5);
    std::cout << "Fuera (esperado: 0): " << bsp(a, b, c, p2) << std::endl;

    // Caso 3: punto sobre una arista
    Point p3(2, 0);
    std::cout << "Arista (esperado: 0): " << bsp(a, b, c, p3) << std::endl;

    // Caso 4: punto en un vértice
    Point p4(0, 0);
    std::cout << "Vertice (esperado: 0): " << bsp(a, b, c, p4) << std::endl;

    // Caso 5: punto fuera pero muy cerca del triángulo
    Point p5(3, 2);
    std::cout << "Cerca fuera (esperado: 0): " << bsp(a, b, c, p5) << std::endl;

    // Caso 6: punto en el centro exacto
    Point p6(1, 1);
    std::cout << "Centro (esperado: 1): " << bsp(a, b, c, p6) << std::endl;

    return 0;
}