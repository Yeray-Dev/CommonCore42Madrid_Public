/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:29:09 by yblanco-          #+#    #+#             */
/*   Updated: 2026/04/18 13:21:17 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _hitPoint = 100;
    _energyPoint = 100;
    _attackPoint = 30;
    std::cout << "FragTrap " << _name << " has been created successful!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoint = 100;
    _energyPoint = 100;
    _attackPoint = 30;
    std::cout << "FragTrap " << name << " has been created successful!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap " << _name << " has been copied!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
        ClapTrap::operator=(other);

    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " has been destroyed successful!" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (_energyPoint && _hitPoint){
        _energyPoint--;
        std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackPoint << " points of damage!" << std::endl;   
    }else
        std::cout << "Energy is not enough\n";
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " wants to high five! Who's with me?" << std::endl;
}