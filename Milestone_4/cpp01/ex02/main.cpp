/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 10:16:38 by yblanco-          #+#    #+#             */
/*   Updated: 2026/04/11 10:30:46 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string &stringREF = brain;
    std::string *stringPTR = &brain;
    
    std::cout << &brain;
    std::cout << &stringREF;
    std::cout << stringPTR;

    std::cout << brain;
    std::cout << stringREF;
    std::cout << *stringPTR;

}