/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:43:35 by yblanco-          #+#    #+#             */
/*   Updated: 2026/04/13 16:19:28 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void )
{
    std::string level;
    
    
    Harl newHarl;
    
    while(1){
        std::cout << "Level > ";
        std::getline(std::cin, level);
        newHarl.complain(level);
        if (level == "EXIT")
            return 1;
    }
    return 0;
}