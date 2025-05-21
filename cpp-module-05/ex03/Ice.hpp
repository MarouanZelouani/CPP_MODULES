#ifndef _ICE_HPP__
#define _ICE_HPP__

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    ~Ice();
    Ice(Ice& const obj);
    Ice& operator=(Ice& const obj);
    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif