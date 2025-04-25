#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "Warning: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}


void Harl::complain(std::string level)
{
    void (Harl::*HarlCommands[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string CommandNames[4] = {"debug", "info", "warning", "error"};

    for (int index = 0; index < 4; ++index)
    {
        if (CommandNames[index] == level)
        {
            (this->*HarlCommands[index])();
            return ;
        }
    }
    std::cout << "Command not found!" << std::endl;
}