#include <iomanip>
#include "PhoneBook.hpp"

std::string formatOutput(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

std::string getInputFromUser(std::string message)
{
    std::string inputString;

    std::cout << message;
    getline(std::cin, inputString);
    if (std::cin.eof())
    {
        std::cout << "\nBYE!" << std::endl;
        exit(1);  
    }
    return (inputString);
}

bool isValide(Contact tmpContact)
{
    if (tmpContact.getFisrstName().empty() || tmpContact.getLastName().empty() 
        || tmpContact.getNickName().empty() || tmpContact.getDarkestSecret().empty() 
        || tmpContact.getPhoneNumber().empty())
        return false;
    return true;
}

PhoneBook::PhoneBook() : nextContactIndex(0), numberofContacts(0) {}

PhoneBook::~PhoneBook(){}

void PhoneBook::addContact()
{
    Contact tmpContact;

    tmpContact.setFirstName(getInputFromUser("Fist name : "));
    tmpContact.setLastName(getInputFromUser("Last name : "));
    tmpContact.setNickName(getInputFromUser("Nickname : "));
    tmpContact.setPhoneNumber(getInputFromUser("Phone-number : "));
    tmpContact.setDarkestSecret(getInputFromUser("Darkest secret : "));
    if(!isValide(tmpContact))
    {
        std::cout << "empty attribute detected!" << std::endl;
        std::cout << "unsaved contact!" << std::endl;
        return ;
    }
    if (this->nextContactIndex == 8)
        this->nextContactIndex = 0;
    this->contacts[this->nextContactIndex] = tmpContact;
    this->nextContactIndex++;
    this->numberofContacts++;
}

void PhoneBook::searchForContact()
{
    std::string input;
    int index;

    if (this->numberofContacts == 0)
    {
        std::cout << "The contact list is empty!" << std::endl;
        return ;
    }

    std::cout << std::setw(10) << std::right << "Index" << "|"
    << std::setw(10) << std::right << "Firstname" << "|"
    << std::setw(10) << std::right << "Lastname" << "|"
    << std::setw(10) << std::right << "Nickname" << std::endl;

    for (int i = 0; i < this->numberofContacts; i++)
    {
        std::cout << std::setw(10) << std::right << i << "|";
        std::cout << std::setw(10) << std::right << formatOutput(this->contacts[i].getFisrstName()) << "|";
        std::cout << std::setw(10) << std::right << formatOutput(this->contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << std::right << formatOutput(this->contacts[i].getNickName()) << std::endl;             
    }   
    
    std::cout << "Type an index to search for :";
    getline(std::cin, input);
    index = std::stoi(input);

    if (index + 1 > this->numberofContacts)
    {
        std::cout << "No Contact with the index of : " << index << std::endl;
        return ;
    }

    std::cout << "Firstname : " << this->contacts[index].getFisrstName() << std::endl;
    std::cout << "Lastname : " << this->contacts[index].getLastName() << std::endl;
    std::cout << "Nicknmae : " << this->contacts[index].getNickName() << std::endl;
    std::cout << "Phone-number : " << this->contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret : " << this->contacts[index].getDarkestSecret() << std::endl;
    std::cout << std::endl << "Press a key to return to the main menu : " << std::endl;
    getchar();
}