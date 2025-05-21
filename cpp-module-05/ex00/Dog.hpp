#ifndef _DOG_HPP__
#define _DOG_HPP__

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    ~Dog();
    Dog(const Dog& obj);
    Dog& operator=(const Dog& obj);
    void makeSound() const;
    std::string getType() const;
};

#endif