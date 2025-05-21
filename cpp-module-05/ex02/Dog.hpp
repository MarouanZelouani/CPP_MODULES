#ifndef _DOG_HPP__
#define _DOG_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain* brain;
public:
    Dog();
    ~Dog();
    Dog(const Dog& obj);
    Dog& operator=(const Dog& obj);
    void makeSound() const;
    std::string getType() const;
};

#endif