#include "FragTrap.hpp"

int main ()
{
    std::string frag1 = "frag_1";
    std::string frag2 = "frag_2";
    std::string frag3 = "frag_3";

    FragTrap fragTrap1(frag1);
    FragTrap fragTrap2(frag2);
    FragTrap fragTrap3(frag3);
    FragTrap fragTrap4(fragTrap2);

    fragTrap1.highFivesGuys();
    fragTrap1.attack(frag2);
    fragTrap1.attack(frag2);
    fragTrap1.attack(frag2);
    fragTrap1.attack(frag2);
    fragTrap1.attack(frag2);

    fragTrap2.takeDamage(20);
    fragTrap2.takeDamage(20);
    fragTrap2.takeDamage(20);
    fragTrap2.takeDamage(20);
    fragTrap2.takeDamage(20);

    fragTrap2.beRepaired(5);
    
    fragTrap2.highFivesGuys();
    fragTrap3.attack(frag1);
}