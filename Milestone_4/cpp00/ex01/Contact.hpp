#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact{
private:
    std::string _phoneNumber;
	std::string _name;
    std::string _lastName;
    std::string _nickName;
    std::string _darkestSecret;
public:
    // constructor contacto
    Contact (std::string newNumber, std::string newName, std::string newLastname,
        std::string newNickName, std::string newSecret);
    Contact();
    ~Contact();
    std::string getInfo() const;
    std::string getInfoFormatted() const;
};

std::string formatData (std::string data);

#endif