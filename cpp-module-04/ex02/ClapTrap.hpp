#ifndef __CLAP_TRAP_HPP
#define __CLAP_TRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
    std::string _name;
    unsigned int _hit_p;
    unsigned int _energy_p;
    unsigned int _damage;

public:
    ~ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& obj);
    ClapTrap& operator= (const ClapTrap& obj);
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif