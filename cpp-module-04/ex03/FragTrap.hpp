#ifndef __FLAG_TRAP_HPP
#define __FLAH_TRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public :
    FragTrap(std::string name);
    ~FragTrap();
    FragTrap(const FragTrap& obj);
    FragTrap& operator= (const FragTrap& obj);
    void highFivesGuys(void);
};

#endif