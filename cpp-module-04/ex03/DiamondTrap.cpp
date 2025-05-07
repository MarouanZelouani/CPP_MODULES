#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap (std::string name)
    :   ClapTrap(name + "_clap_name"), 
        ScavTrap(name + "_scav_name"), 
        FragTrap(name + "_Frag_name")
{
    std::cout << "DiamondTrap Constructor called" << std::endl;
    _name = name;
    _hit_p = FragTrap::_hit_p;
    _energy_p = ScavTrap::_energy_p;
    _damage = FragTrap::_damage;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap DeConstructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& obj)
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

DiamondTrap::DiamondTrap(const DiamondTrap& obj)
    :   ClapTrap(obj),
        ScavTrap(obj),
        FragTrap(obj) 
{
    std::cout << "DiamondTrap DeConstructor called" << std::endl;
    *this = obj;
}

void DiamondTrap::whoAmI()
{
    std::cout << "Hi I'm " << _name << " nice meeting you!" << std::endl;
}
