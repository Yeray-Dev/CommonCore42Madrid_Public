/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 12:55:02 by yblanco-          #+#    #+#             */
/*   Updated: 2026/04/11 19:11:32 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int checkError(int argc, char **argv)
{
    if (argc != 4){
        std::cerr << "usage: ./program <filename> <s1> <s2>";
        return 1;
    }
    if (std::string(argv[2]).empty()){
        std::cerr << "Error: S1 is empty!";
        return 1;
    }
    if (std::string(argv[3]).empty()){
        std::cerr << "Error: S2 is empty!";
        return 1;
    }
    return 0;
}

int main ( int argc, char **argv )
{
    if(checkError(argc, argv))
        return 1; 
    std::string filename = argv[1];
    std::string line;
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Error: the file cannot be open\n";
        return 1;
    }
    std::ofstream outfile((filename + ".replace").c_str());
    
    while(std::getline(infile, line)){
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos){
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outfile << line << "\n";
    }
}
