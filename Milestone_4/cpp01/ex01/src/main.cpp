/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:58:18 by yblanco-          #+#    #+#             */
/*   Updated: 2026/04/09 20:05:50 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::cout << "---- Test 1: Horde of 5 ----\n";
    int size = 5;
    Zombie *arrZombie = zombieHorde(size, "Bob");
    for (int i = 0; i < size; i++)
        arrZombie[i].announce();    
    delete[] arrZombie;
}