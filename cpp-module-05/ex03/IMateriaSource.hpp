#ifndef _IMATERIA_SOURCE_HPP__
#define _IMATERIA_SOURCE_HPP__

#include "AMateria.hpp"

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria* m) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif