#include "ClapTrap.hpp"

int main ()
{
    std::string clap1 = "clap_1";
    std::string clap2 = "clap_2";
    std::string clap3 = "clap_3";

    ClapTrap clapTrap1(clap1);
    ClapTrap clapTrap2(clap2);
    ClapTrap clapTrap3(clap3);
    ClapTrap copyClap(clapTrap1);

    clapTrap1.attack(clap2);
    clapTrap1.attack(clap2);
    clapTrap1.attack(clap2);

    clapTrap2.takeDamage(5);
    clapTrap2.takeDamage(5);
    clapTrap2.takeDamage(5);

    clapTrap2.beRepaired(5);    
}