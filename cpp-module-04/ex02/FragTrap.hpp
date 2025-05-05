#ifndef __FLAG_TRAP_HPP
#define __FLAH_TRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
public :
    FragTrap(std::string name);
    ~FragTrap();
    void highFivesGuys(void);
};

#endif