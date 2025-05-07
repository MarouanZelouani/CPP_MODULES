#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) 
    : ClapTrap(name)
{
    std::cout << "FragTrap Default constructor called" << std::endl;
    this->_hit_p = 100;
    this->_energy_p = 100;
    this->_damage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap& FragTrap::operator= (const FragTrap& obj)
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

FragTrap::FragTrap(const FragTrap& obj)
    : ClapTrap(obj)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (_energy_p)
    {
        std::cout << "High Five please!!" << std::endl;
        _energy_p--;
    }
    std::cout << "not enough enery point, can't HIGHFIVE!" << std::endl;
}