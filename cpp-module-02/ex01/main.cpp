#include "Zombie.hpp"

int main ()
{
    int HordeSize = 5; 
    Zombie *zombies = zombieHorde(HordeSize, "ME");
    for (int i = 0; i < HordeSize; i++)
    {
        std::cout << i << " : ";
        zombies[i].announce();
    }    
    delete[] zombies;
}