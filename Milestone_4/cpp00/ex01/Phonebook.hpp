#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook{
private:
	Contact contact[8];
    int _id;
public:
    PhoneBook();
    ~PhoneBook();
    void add();
    void search();
};

#endif