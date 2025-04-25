#include "HumanB.hpp"

HumanB::HumanB(std::string name)
    : name(name)
{}

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon& Weapon)
{
    this->weapon = weapon;
}

void HumanB::attack()
{
    std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}