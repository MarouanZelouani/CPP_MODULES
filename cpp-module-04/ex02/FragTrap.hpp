#ifndef __FRAG_TRAP_HPP
#define __FRAG_TRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
public :
    FragTrap(std::string name);
    ~FragTrap();
    FragTrap(const FragTrap& obj);
    FragTrap& operator= (const FragTrap& obj);
    void highFivesGuys(void);
};

#endif