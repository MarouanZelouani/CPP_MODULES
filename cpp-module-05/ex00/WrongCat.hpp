#ifndef _WRONG_CAT_HPP__
#define _WRONG_CAT_HPP__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    ~WrongCat();
    WrongCat(const WrongCat& obj);
    WrongCat& operator=(const WrongCat& obj);
    void makeSound() const;
    std::string getType() const;
};

#endif