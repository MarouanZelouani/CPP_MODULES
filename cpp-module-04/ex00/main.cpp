#include "ClapTrap.hpp"

int main ()
{
    ClapTrap clapTrap1("clap_1");
    ClapTrap clapTrap2("clap_2");

    clapTrap1.attack("clap_2");
    clapTrap2.beRepaired(10);
}