#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Basic Polymorphism Test ===\n" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wc = new WrongCat();
    
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    std::cout << wc->getType() << std::endl;

    i->makeSound();
    j->makeSound();
    wc->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    delete wc;

    std::cout << "\n=== Copy Constructor Test ===\n" << std::endl;
    Dog originalDog;
    Dog copiedDog(originalDog);
    originalDog.makeSound();
    copiedDog.makeSound();

    std::cout << "\n=== Assignment Operator Test ===\n" << std::endl;
    Cat cat1;
    Cat cat2;
    cat2 = cat1;
    cat1.makeSound();
    cat2.makeSound();

    std::cout << "\n=== WrongAnimal Copy & Assign Test ===\n" << std::endl;
    WrongCat wc1;
    WrongCat wc2(wc1);
    WrongCat wc3;
    wc3 = wc1;

    wc1.makeSound();
    wc2.makeSound();
    wc3.makeSound();

    std::cout << "\n=== Manual Destruction End ===\n" << std::endl;

    return 0;
}