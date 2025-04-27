#include "HumanB.hpp"

HumanB::HumanB(std::string name)
    : name(name), weapon(NULL)
{}

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack()
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else 
        std::cout << "No Weapon" << std::endl;
}