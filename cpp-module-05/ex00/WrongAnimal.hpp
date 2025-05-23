#ifndef _WRONG_ANIMAL_HPP__
#define _WRONG_ANIMAL_HPP__

#include <iostream>
#include <string>

// makeSound() is not virtual, demonstrates wrong polymorphism
class WrongAnimal 
{
protected:
    std::string type;
    
public:
    WrongAnimal();
    virtual ~WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(const WrongAnimal & obj);
    WrongAnimal& operator=(const WrongAnimal & obj);
    std::string getType() const;
    void makeSound() const;
};

#endif
