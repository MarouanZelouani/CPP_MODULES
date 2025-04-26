#ifndef _CONTACT_HPP
#define _CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string dakestSecret;
    
public:
    Contact();
    ~Contact();
    void setFirstName(std::string name);
    std::string getFisrstName();
    void setLastName(std::string name);
    std::string getLastName();
    void setNickName(std::string name);
    std::string getNickName();
    void setPhoneNumber(std::string number);
    std::string getPhoneNumber();
    void setDarkestSecret(std::string secret);
    std::string getDarkestSecret();
    
};


#endif