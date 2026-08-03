/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:31:01 by yblanco-          #+#    #+#             */
/*   Updated: 2026/05/31 13:46:19 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    _name = "newZombie";
}

Zombie::~Zombie()
{
    std::cout << _name << " Is destroyed\n";
}

void Zombie::announce()
{
    std::cout << _name << ": Braiiiiiiinnnzzz\n";
}

void Zombie::setName(std::string name)
{
    _name = name;
}