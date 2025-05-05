#ifndef __CLAP_TRAP_HPP
#define __CLAP_TRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
    std::string _name;
    int _hit_p;
    int _energy_p;
    int _damage;

public:
    ~ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(std::string name, int hit_p, int energy, int damage);
    ClapTrap(const ClapTrap& obj);
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif