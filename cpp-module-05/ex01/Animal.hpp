#ifndef _ANIMAL_HPP__
#define _ANIMAL_HPP__

#include <iostream>
#include <string>

class Animal 
{
protected:
    std::string type;
    
public:
    Animal();
    virtual ~Animal();
    Animal(std::string type);
    Animal(const Animal& obj);
    Animal& operator=(const Animal& obj);
    std::string getType() const;
    virtual void makeSound() const;
};

#endif
