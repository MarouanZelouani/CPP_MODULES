#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) 
    : ClapTrap(name)
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
    this->_hit_p = 100;
    this->_energy_p = 50;
    this->_damage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap& obj)
{
    if (this != &obj)
    {
        _name = obj._name;
        _hit_p = obj._hit_p;
        _energy_p = obj._energy_p;
        _damage = obj._damage;
    }
    return *this;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
    : ClapTrap(obj)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    if (_energy_p && _hit_p)
    {
        std::cout << "ScavTrap " << _name <<  " activated Gate keeper mode!" << std::endl;
        _energy_p--;
        return ;
    }
    std::cout << "No energy point left!, GUARD GATE! can't be activated" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_energy_p && _hit_p)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " 
        << _damage << " points of damage!" << std::endl;
        _energy_p--;
        return ;
    }
    std::cout << "No energy point left!, attacking faild!" << std::endl;
}

// void ScavTrap::printStatus()
// {
//     std::cout << "hit = " << _hit_p << " energy = " << _energy_p << std::endl;
// }