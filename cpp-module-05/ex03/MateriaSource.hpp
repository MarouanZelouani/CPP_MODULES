#ifndef _MATERIA_SOURCE_HPP__
#define _MATERIA_SOURCE_HPP__

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* _materias[4];
public:
    MateriaSource();
    MateriaSource(MateriaSource& const obj);
    MateriaSource& operator=(MateriaSource& const obj);
    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

#endif