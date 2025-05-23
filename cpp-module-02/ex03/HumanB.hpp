#ifndef __HUMAN_B_HPP
#define __HUMAN_B_HPP

#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon* weapon;

public:
    HumanB(std::string name);
    ~HumanB();
    void setWeapon(Weapon& weapon);
    void attack();
};

#endif