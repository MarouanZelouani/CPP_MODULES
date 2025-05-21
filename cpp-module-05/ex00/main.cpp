#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wc = new WrongCat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << wc->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    wc->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    delete wc;
    return 0;
}