#ifndef __SCAV_TRAP_HPP
# define __SCAV_TRAP_HPP

#include "ClapTrap.hpp";

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(std::string name);
    ~ScavTrap();
    void guardGate();
    void attack(const std::string& target) override;
};

#endif