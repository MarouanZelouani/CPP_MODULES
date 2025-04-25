#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.cpp"

string formatOutput(string str)
{
    string newStr;

    if (str.length() > 10)
    {
        newStr = str.substr(1, 9) + ".";
    }
    else 
        newStr = str;
    return (newStr);
}

string getInputFromUser(string message)
{
    string inputString;
    int flag;
    
    flag = 1;
    system("clear");
    while (flag)
    {
        std::cout << message;
        getline(std::cin, inputString);
        if (inputString.empty())
            std::cout << "Input it empty!" << endl;
        else 
            flag = 0;
    }
    return (inputString);
}

class PhoneBook 
{
private:
    Contact contacts[8];
    int nextContactIndex;
    int numberofContacts;

public:
    
    PhoneBook()
    {
        this->nextContactIndex = 0;
        this->numberofContacts = 0;
    }

    ~PhoneBook(){}

    void addContact()
    {
        Contact tmpContact;

        if (this->nextContactIndex == 8)
            this->nextContactIndex = 0;
        tmpContact.setFirstName(getInputFromUser("Fist name :"));
        tmpContact.setFirstName(getInputFromUser("Last name :"));
        tmpContact.setFirstName(getInputFromUser("Nickname :"));
        tmpContact.setFirstName(getInputFromUser("Phone-number :"));
        tmpContact.setFirstName(getInputFromUser("Darkest secret :"));
        system("clear");
        this->contacts[this->nextContactIndex] = tmpContact;
        this->nextContactIndex++;
        this->numberofContacts++;
    }

    void searchForContact()
    {
        string input;
        int index;

        if (this->numberofContacts == 0)
        {
            std::cout << "The contact list is empty!" << endl;
            return ;
        }

        std::cout << setw(10) << right << "Index" << "|"
        << setw(10) << right << "Firstname" << "|"
        << setw(10) << right << "Lastname" << "|"
        << setw(10) << right << "Nickname" << endl;

        for (int i = 0; i <= this->nextContactIndex; i++)
        {
            std::cout << setw(10) << right << i << "|";
            std::cout << setw(10) << right << formatOutput(this->contacts[i].getFisrstName()) << "|";
            std::cout << setw(10) << right << formatOutput(this->contacts[i].getLastName()) << "|";
            std::cout << setw(10) << right << formatOutput(this->contacts[i].getNickName()) << endl;             
        }   
        
        std::cout << "Type an index to search for :";
        getline(std::cin, input);
        index = std::stoi(input);

        std::cout << "Firstname : " << this->contacts[index].getFisrstName() << endl;
        std::cout << "Lastname : " << this->contacts[index].getLastName() << endl;
        std::cout << "Nicknmae : " << this->contacts[index].getNickName() << endl;
        std::cout << "Phone-number : " << this->contacts[index].getPhoneNumber() << endl;
        std::cout << "Darkest secret : " << this->contacts[index].getDarkestSecret() << endl;
        std::cout << endl << "Press a key to return to the main menu : " << endl;
        getchar();
    }
};