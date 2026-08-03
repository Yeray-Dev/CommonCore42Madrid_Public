/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 11:57:33 by yblanco-          #+#    #+#             */
/*   Updated: 2026/04/18 11:59:10 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap pj("Bob");

    pj.attack("Enemy");
    pj.takeDamage(5);
    pj.beRepaired(3);
    
    // Test sin energia
    ClapTrap broke("Broke");
    broke.takeDamage(10); // lo matamos
    broke.attack("Enemy"); // no deberia poder atacar
    
    // Test copia
    ClapTrap copy(pj);
    copy.attack("Target");
    
    return 0;
}