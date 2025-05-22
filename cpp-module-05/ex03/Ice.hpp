#ifndef _ICE_HPP__
#define _ICE_HPP__

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    ~Ice();
    Ice(const Ice& obj);
    Ice& operator=(const Ice& obj);
    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif