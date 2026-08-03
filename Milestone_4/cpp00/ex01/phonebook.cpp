#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "Phonebook.hpp"


PhoneBook::PhoneBook() : _id(0) {}

PhoneBook::~PhoneBook() {}

void requestData(std::string newFields[5])
{
    do {
        std::cout << "Number: ";
        std::getline(std::cin, newFields[0]);
        if (newFields[0].empty())
            std::cout << "Try again. This date can't be empty";
    }while (newFields[0].empty());

    do {
        std::cout << "Name: ";
        std::getline (std::cin, newFields[1]);
        if (newFields[1].empty())
            std::cout << "Try again. This date can't be empty";
    }while (newFields[1].empty());

    do {
        std::cout << "Last Name: ";
        std::getline (std::cin, newFields[2]);
        if (newFields[2].empty())
            std::cout << "Try again. This date can't be empty";
    }while (newFields[2].empty());

    do {
        std::cout << "Nickname: ";
        std::getline (std::cin, newFields[3]);
        if (newFields[3].empty())
            std::cout << "Try again. This date can't be empty";
    }while (newFields[3].empty());

    do{
        std::cout << "Darkest Secret: ";
        std::getline (std::cin, newFields[4]);
        if (newFields[4].empty())
            std::cout << "Try again. This date can't be empty";
    }while (newFields[4].empty());
}

void PhoneBook::add()
{
    std::string newFields[5];

    requestData(newFields);
    contact[_id % 8] = Contact(newFields[0], newFields[1], newFields[2], newFields[3], newFields[4]);
    _id++;
}

void PhoneBook::search()
{
    std::string info;
    std::string index;
    int n_index;

    std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|\n";
    if (!_id){
        std::cout << "\n\nRight now Phonebook is empty.\nFirst add any contact.\n\n";
        return;
    }
    int count = (_id < 8) ? _id : 8;
    for (int i = 0; i < count; i++){
        std::stringstream s_index;
        s_index << i + 1;
        std::cout <<  "|         " + s_index.str() + contact[i].getInfoFormatted();
    }
        

    do {
        std::cout << "Which contact do you want to see?\n";
        if (!std::getline(std::cin, index))
            return;
        n_index = std::atoi(index.c_str());
        if (n_index < 1 || n_index > 8)
            std::cout << "The index is not correct\nPlease only use index between 1 and 8\n\n";
    } while (n_index < 1 || n_index > 8);

    info = contact[n_index - 1].getInfo();

    std::cout << info << "\n";
}
