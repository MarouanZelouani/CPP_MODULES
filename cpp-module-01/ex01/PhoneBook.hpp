#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class  PhoneBook
{
private:
    Contact contacts[8];
    int nextContactIndex;
    int numberofContacts;

public:
    PhoneBook();
    ~PhoneBook();
    void addContact();
    void searchForContact();
};

#endif