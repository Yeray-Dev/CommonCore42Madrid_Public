/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 11:57:33 by yblanco-          #+#    #+#             */
/*   Updated: 2026/04/18 12:39:02 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    std::cout << "\n=== Destruction ===" << std::endl;
    return 0;
}