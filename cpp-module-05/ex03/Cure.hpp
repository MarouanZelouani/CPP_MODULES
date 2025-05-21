#ifndef _CURE_HPP__
#define _CURE_HPP__

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    ~Cure();
    Cure(Cure& const obj);
    Cure& operator=(Cure& const obj);
    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif