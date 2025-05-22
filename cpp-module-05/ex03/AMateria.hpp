#ifndef _AMATERIA_HPP__
#define _AMATERIA_HPP__

#include <iostream>
#include <string>
#include "ICharacter.hpp"


class AMateria
{
protected:
    std::string type;
public:
    AMateria(std::string const & type);
    virtual ~AMateria();
    AMateria(const AMateria& obj);
    AMateria& operator=(const AMateria& obj);
    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif