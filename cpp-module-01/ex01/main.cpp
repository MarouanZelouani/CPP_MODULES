#include "PhoneBook.hpp"

int main ()
{
    PhoneBook phoneBook;
    std::string input;

    system("clear");
    while (1)
    {
        std::cout << "Enter a COMMAND (ADD, SEARCH, EXIT) : ";
        getline(std::cin, input);
        if (!input.compare("ADD"))
            phoneBook.addContact();
        else if (!input.compare("SEARCH"))
            phoneBook.searchForContact();
        else if (!input.compare("EXIT"))
            break;
        else if (std::cin.eof())
        {
            std::cout << std::endl;
            break;
        }
        else 
            std::cout << "Invalid input !" << std::endl;
    }
    std::cout << "BYE BYE" << std::endl;
}