#ifndef __SCAV_TRAP_HPP
# define __SCAV_TRAP_HPP

#include "ClapTrap.hpp";

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(std::string name);
    ~ScavTrap();
    ScavTrap(const ScavTrap& obj);
    ScavTrap& operator= (const ScavTrap& obj);
    void guardGate();
    void attack(const std::string& target);
};

#endif