#include "ScavTrap.hpp"

int main ()
{
    std::string scav1 = "scav_1";
    std::string scav2 = "scav_2";
    std::string scav3 = "scav_3";

    ScavTrap scavTrap1(scav1);
    ScavTrap scavTrap2(scav2);
    ScavTrap scavTrap3(scav3);
    ScavTrap scavTrap4(scavTrap2);

    scavTrap1.attack(scav2);
    scavTrap1.attack(scav2);
    scavTrap1.attack(scav2);
    scavTrap1.attack(scav2);
    scavTrap1.attack(scav2);

    
    scavTrap2.takeDamage(20);
    scavTrap2.takeDamage(20);
    scavTrap2.takeDamage(20);
    scavTrap2.takeDamage(20);
    scavTrap2.takeDamage(20);
    
    
    scavTrap2.beRepaired(5);
    scavTrap2.guardGate();  


    scavTrap3.attack(scav1);
    scavTrap1.guardGate();  
}