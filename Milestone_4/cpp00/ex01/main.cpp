#include "Contact.hpp"
#include "Phonebook.hpp"
#include <iostream>

int main(void)
{
    PhoneBook pb;
    std::string command;
    std::string index;

    while (1){
        std::cout << "What do you want to do? " << "(ADD | SEARCH | EXIT)\n" << ">> ";
        if (!std::getline(std::cin, command))
            break;

        if (command == "ADD"){
            pb.add();
        }else if (command == "SEARCH"){
            pb.search();
        }else if (command == "EXIT"){
            break;
        }
    }
}
