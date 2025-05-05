#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) 
    : ClapTrap(name, 100, 50, 20)
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name <<  "activated Gate keeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (!_energy_p)
    {
        std::cout << "No energy point left!, attacking faild!" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " 
    << _damage << " points of damage!" << std::endl;
    _energy_p--;
}

