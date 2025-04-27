#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug(void)
{
    std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money.\nYou didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}


void Harl::complain(std::string level)
{
    std::string CommandNames[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*funptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i = -1;

    for (int index = 0; index < 4; ++index)
    {
        if (CommandNames[index] == level)
        {
            i = index;
            break;
        }
    }

    switch (i)
    {
        case 0:
            (this->*funptr[0])();
        case 1:
            (this->*funptr[1])();
        case 2:
            (this->*funptr[2])();
        case 3:
            (this->*funptr[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}