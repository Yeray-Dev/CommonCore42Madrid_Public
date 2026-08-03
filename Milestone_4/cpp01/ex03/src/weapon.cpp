/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 11:53:10 by yblanco-          #+#    #+#             */
/*   Updated: 2026/04/11 12:21:07 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    _type = type;
}
Weapon::~Weapon()
{
    
}

std::string Weapon::getType()
{
    return _type;
}
void Weapon::setType(std::string type)
{
    _type = type;
}