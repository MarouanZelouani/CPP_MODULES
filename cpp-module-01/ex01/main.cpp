#include "PhoneBook.cpp"

int main ()
{
    PhoneBook phoneBook;
    string input;

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
        else 
            std::cout << "Invalid input !" << endl;
        system("clear");
    }
    std::cout << "Bye Bye -_-" << endl;
}