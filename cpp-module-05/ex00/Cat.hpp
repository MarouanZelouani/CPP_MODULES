#ifndef _Cat_HPP__
#define _Cat_HPP__

#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    ~Cat();
    Cat(const Cat& obj);
    Cat& operator=(const Cat& obj);
    void makeSound() const;
    std::string getType() const;
};

#endif