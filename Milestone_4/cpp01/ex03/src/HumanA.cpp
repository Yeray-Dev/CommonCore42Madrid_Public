/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 11:11:28 by yblanco-          #+#    #+#             */
/*   Updated: 2026/04/11 12:39:04 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &club) : _weapon(club)
{
    _name = name;
}

HumanA::~HumanA()
{

}

void HumanA::attack()
{
    std::string typeWeapon = _weapon.getType();
    std::cout << _name << " attacks with their " << typeWeapon << "\n";
}