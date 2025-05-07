#ifndef __DIAMOND_TRAP
#define __DIAMOND_TRAP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string _name;
public:
    DiamondTrap(std::string name);
    ~DiamondTrap();
    DiamondTrap(const DiamondTrap& obj);
    DiamondTrap& operator= (const DiamondTrap& obj);
    void attack (const std::string& target);
    void whoAmI();
};

#endif