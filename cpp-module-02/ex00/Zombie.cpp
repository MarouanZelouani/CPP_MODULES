#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{}

Zombie::~Zombie()
{
    std::cout << name << " : Destroyed!" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;    
}

