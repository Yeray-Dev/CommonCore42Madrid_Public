/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 11:57:33 by yblanco-          #+#    #+#             */
/*   Updated: 2026/05/31 16:11:43 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
 
int main()
{
    std::cout << "=== ClapTrap ===" << std::endl;
    ClapTrap c("Alice");
    c.attack("Enemy");
    c.takeDamage(5);
    c.beRepaired(3);
 
    std::cout << "\n=== ScavTrap ===" << std::endl;
    ScavTrap s("Bob");
    s.attack("Enemy");
    s.takeDamage(5);
    s.beRepaired(3);
    s.guardGate();
 
    std::cout << "\n=== FragTrap ===" << std::endl;
    FragTrap f("Charlie");
    f.attack("Enemy");
    f.takeDamage(50);
    f.beRepaired(20);
    f.highFivesGuys();
 
    std::cout << "\n=== DiamondTrap ===" << std::endl;
    DiamondTrap d("Diana");
    d.attack("Enemy");
    d.takeDamage(30);
    d.beRepaired(10);
    d.guardGate();
    d.highFivesGuys();
    d.whoAmI();
 
    std::cout << "\n=== Destruction ===" << std::endl;
    return 0;
}