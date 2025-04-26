#include "Contact.hpp"

Contact::Contact(){}
Contact::~Contact(){}

void Contact::setFirstName(std::string name) 
{
    this->firstName = name;
}

std::string Contact::getFisrstName() 
{
    return this->firstName;
}

void Contact::setLastName(std::string name)
{
    this->lastName = name;
}

std::string Contact::getLastName()
{
    return this->lastName;
}

void Contact::setNickName(std::string name)
{
    this->nickName = name;
}

std::string Contact::getNickName()
{
    return this->nickName;
}

void Contact::setPhoneNumber(std::string number)
{
    this->phoneNumber = number;
}

std::string Contact::getPhoneNumber()
{
    return this->phoneNumber;
}

void Contact::setDarkestSecret(std::string secret)
{
    this->dakestSecret = secret;
}

std::string Contact::getDarkestSecret()
{
    return this->dakestSecret;
}