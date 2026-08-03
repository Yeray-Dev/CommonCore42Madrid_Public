/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 11:23:22 by yblanco-          #+#    #+#             */
/*   Updated: 2026/04/18 12:29:17 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    _name = "";
    _hitPoint = 10;
    _energyPoint = 10;
    _attackPoint = 10;
    std::cout << "ClapTrap is created!\n";
}

ClapTrap::ClapTrap(std::string name)
{
    _name = name;
    _hitPoint = 10;
    _energyPoint = 10;
    _attackPoint = 10;
    std::cout << "ClapTrap is created!\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._name),
     _hitPoint(other._hitPoint),
     _energyPoint(other._energyPoint),
     _attackPoint(other._attackPoint)
{   
    std::cout << "ClapTrap is copied!\n";
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other){
        _name = other._name;
        _hitPoint = other._hitPoint;
        _energyPoint = other._energyPoint;
        _attackPoint = other._attackPoint;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap is destroyed!\n";
}

/* ---- FUNCTIONS ----*/

void ClapTrap::attack(const std::string &target)
{
    if (_energyPoint && _hitPoint){
        _energyPoint--;
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackPoint << " points of damage!" << std::endl;   
    }else
        std::cout << "Energy is not enough\n";
}

void ClapTrap::takeDamage( unsigned int amount )
{
    if (amount >= (unsigned int)_hitPoint)
        _hitPoint = 0;
    else
        _hitPoint -= amount;
        
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    
    if (_hitPoint <= 0)
        std::cout << "\nYou are dead!\n\n";
}

void ClapTrap::beRepaired( unsigned int amount )
{
    if (_energyPoint){
        _hitPoint += amount;
        _energyPoint--;
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points!" << std::endl;
    }else
        std::cout << "Energy is not enough\n";
}