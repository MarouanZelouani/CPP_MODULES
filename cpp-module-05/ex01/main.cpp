#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp" 

int main()
{
    std::cout << "=== Constructing Animals ===\n" << std::endl;
    const Animal* meta[10];

    for (int i = 0; i < 10; ++i)
    {
        if (i < 5)
            meta[i] = new Dog();
        else
            meta[i] = new Cat();
    }

    std::cout << "\n=== Testing Animals ===\n" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "Animal [" << i << "] Type: " << meta[i]->getType() << std::endl;
        meta[i]->makeSound();
    }
    
    std::cout << "\n=== Deep Copy Test ===\n" << std::endl;
    
    Dog* dogA = new Dog();
    
    dogA->setIdea("Chase the cat");
    dogA->setIdea("Dig a hole");
    dogA->setIdea("zaki lmaki");
    
    Dog* dogB = new Dog(*dogA);
    
    std::cout << "\nDog A ideas:" << std::endl;
    dogA->getIdeas();
    
    std::cout << "\nDeleting Dog A:" << std::endl;
    delete dogA;
    
    std::cout << "\nDog B ideas after deleting Dog A (should still exist):" << std::endl;
    dogB->getIdeas();
    
    std::cout << "\nDeleting Dog A:" << std::endl;
    delete dogB;

    std::cout << "\n=== Deleting Animals ===\n" << std::endl;
    for (int i = 0; i < 10; ++i)
        delete meta[i];

    return 0;
}
