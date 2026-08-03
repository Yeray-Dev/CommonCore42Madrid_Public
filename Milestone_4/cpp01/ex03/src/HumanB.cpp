/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 11:24:29 by yblanco-          #+#    #+#             */
/*   Updated: 2026/04/11 12:39:16 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    _name = name;
}

HumanB::~HumanB()
{
    
}

void HumanB::setWeapon(Weapon &club)
{
    _weapon = &club;
}

void HumanB::attack()
{
    std::string typeWeapon = _weapon->getType();
    std::cout << _name << " attacks with their " << typeWeapon << "\n";
}