#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) 
    : ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "High Five please!!" << std::endl;
}