#include "Zombie.hpp"

int main ()
{
    Zombie* zombie = newZombie("ME");
    zombie->announce();
    randomChump("NOTME");
    delete zombie;
}