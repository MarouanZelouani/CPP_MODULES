#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) 
    : _name(name), _hit_p(10), _energy_p(10), _damage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
    std::cout << "Copy constructor called" << std::endl;
    if (this != &obj)
    {
        _name = obj._name;
        _hit_p = obj._hit_p;
        _energy_p = obj._energy_p;
        _damage = obj._damage;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << _name << " took damage " 
        << amount << " points!" << std::endl;
    _hit_p -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!_energy_p)
    {
        std::cout << "No energy point left!, repairing faild!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " repaired himself!"  << std::endl;
    _hit_p += amount;
    _energy_p--;
}

void ClapTrap::attack(const std::string& target)
{
    if (!_energy_p)
    {
        std::cout << "No energy point left!, attacking faild!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " 
    << _damage << " points of damage!" << std::endl;
    _energy_p--;
}


