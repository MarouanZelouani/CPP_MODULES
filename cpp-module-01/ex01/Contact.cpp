#include <iostream>
#include <string>

using namespace std;

class Contact
{
private:
    string firstName;
    string lastName;
    string nickName;
    string phoneNumber;
    string dakestSecret;
    
public:

    Contact(){}
    ~Contact(){}

    void setFirstName(string name) 
    {
        this->firstName = name;
    }

    string getFisrstName() 
    {
        return this->firstName;
    }

    void setLastName(string name)
    {
        this->lastName = name;
    }

    string getLastName()
    {
        return this->lastName;
    }

    void setNickName(string name)
    {
        this->nickName = name;
    }

    string getNickName()
    {
        return this->nickName;
    }

    void setPhoneNumber(string number)
    {
        this->phoneNumber = number;
    }

    string getPhoneNumber()
    {
        return this->phoneNumber;
    }

    void setDarkestSecret(string secret)
    {
        this->dakestSecret = secret;
    }

    string getDarkestSecret()
    {
        return this->dakestSecret;
    }
};
