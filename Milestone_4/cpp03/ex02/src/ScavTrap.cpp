/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:09:19 by yblanco-          #+#    #+#             */
/*   Updated: 2026/04/18 12:34:29 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _hitPoint = 100;
    _energyPoint = 50;
    _attackPoint = 50;
    std::cout << "ScavTrap " << _name << " has been created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitPoint = 100;
    _energyPoint = 50;
    _attackPoint = 50;
    std::cout << "ScavTrap " << _name << " has been created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << _name << " has been copied!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
        ClapTrap::operator=(other);

    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " has been destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (_energyPoint && _hitPoint){
        _energyPoint--;
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackPoint << " points of damage!" << std::endl;   
    }else
        std::cout << "Energy is not enough\n";
}

void ScavTrap::guardGate()
{
           std::cout << "ScavTrap " << _name << " is now in Gate Keeper Mode!" << std::endl;   
}

