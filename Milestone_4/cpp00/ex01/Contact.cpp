#include "Contact.hpp"


Contact::Contact(std::string newNumber, std::string newName, std::string newLastname,
        std::string newNickName, std::string newSecret){
            _phoneNumber = newNumber;
            _name = newName;
            _lastName = newLastname;
            _nickName = newNickName;
            _darkestSecret = newSecret;
}

Contact::Contact() : _phoneNumber(""), _name(""), _lastName(""),
                    _nickName(""), _darkestSecret("") {}

Contact::~Contact() {}

std::string Contact::getInfo() const
{
    std::string info;

    info += "Name: " + _name + "\n";
    info += "Last Name: " + _lastName + "\n";
    info += "Phone Number: " + _phoneNumber + "\n";
    info += "Nickname: " + _nickName + "\n";
    info += "Darkest Secret: " + _darkestSecret + "\n";

    return info;
}
std::string formatData (std::string data)
{
    int diference = 0;
    std::string formattedData;

    if (data.length() > 10){
       formattedData = data.substr(0 , 9) + ".";
    }else{
        diference = 10 - data.length();
        formattedData.append(diference, ' ');
        formattedData += data;
    }

    return formattedData;
}

std::string Contact::getInfoFormatted() const
{
    std::string allInfo;
    
    allInfo += "|" + formatData(_name) + "|" + formatData(_lastName) + "|" + formatData(_nickName) + "|\n";
    
    return allInfo;
}