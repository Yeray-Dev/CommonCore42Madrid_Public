/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:30:57 by yblanco-          #+#    #+#             */
/*   Updated: 2026/04/09 19:30:58 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
private:
    std::string _name;
public:
    void announce( void );
    Zombie(std::string name);
    ~Zombie();
};


void randomChump( std::string name);
Zombie* newZombie(std::string name);

#endif