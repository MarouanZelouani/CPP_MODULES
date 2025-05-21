#include "DiamondTrap.hpp"

int main ()
{
    std::string Diamond1 = "Diamond_1";
    std::string Diamond2 = "Diamond_2";
    std::string Diamond3 = "Diamond_3";
    
    DiamondTrap DiamondTrap1(Diamond1);
    DiamondTrap DiamondTrap2(Diamond2);
    DiamondTrap DiamondTrap3(Diamond3);
    DiamondTrap DiamondTrap4(DiamondTrap2);
    
    DiamondTrap2.highFivesGuys();
    DiamondTrap2.whoAmI();

    DiamondTrap1.highFivesGuys();
    DiamondTrap1.whoAmI();

    DiamondTrap1.attack(Diamond2);
    DiamondTrap1.attack(Diamond2);
    DiamondTrap1.attack(Diamond2);
    DiamondTrap1.attack(Diamond2);
    DiamondTrap1.attack(Diamond2);

    DiamondTrap2.takeDamage(20);
    DiamondTrap2.takeDamage(20);
    DiamondTrap2.takeDamage(20);
    DiamondTrap2.takeDamage(20);
    DiamondTrap2.takeDamage(20);
    
    DiamondTrap2.beRepaired(5);
    DiamondTrap2.guardGate();  

    DiamondTrap3.attack(Diamond1);
    DiamondTrap1.guardGate();    
}