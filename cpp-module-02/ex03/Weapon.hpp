#ifndef __WEAPON_HPP
#define __WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
    std::string type;

public:
    Weapon(std::string type);
    ~Weapon();
    const std::string& getType();
    void setType(std::string type);
};

#endif