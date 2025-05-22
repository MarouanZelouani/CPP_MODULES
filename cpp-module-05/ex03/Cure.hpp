#ifndef _CURE_HPP__
#define _CURE_HPP__

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    ~Cure();
    Cure(const Cure& obj);
    Cure& operator=(const Cure& obj);
    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif