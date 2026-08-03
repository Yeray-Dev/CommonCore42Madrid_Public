/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:43:35 by yblanco-          #+#    #+#             */
/*   Updated: 2026/04/16 19:32:32 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( int argc, char **argv )
{   
    if (argc != 2){
        std::cerr << "Usage: ./harlFilter <level>\n";
        std::cerr << "Levels: DEBUG, INFO, WARNING, ERROR\n";
        return 1;
    }
    Harl newHarl;
    std::string level = argv[1];    
    newHarl.complain(level);
    return 0;
}