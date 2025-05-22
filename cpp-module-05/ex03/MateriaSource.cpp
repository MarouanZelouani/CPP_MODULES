#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource Default Constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _materias[i] = 0;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource Deconstructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        delete _materias[i];
        _materias[i] = 0;
    }
}

MateriaSource::MateriaSource(const MateriaSource& obj) {
    std::cout << "MateriaSource Copy Constructor called" << std::endl;
    *this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj) {
    if (this != &obj) {
        for (int i = 0; i < 4; ++i) {
            delete _materias[i];
            _materias[i] = 0;
            if (obj._materias[i])
                _materias[i] = obj._materias[i]->clone();
            else 
                _materias[i] = 0;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!_materias[i]) {
            std::cout << "Materia has been added!" << std::endl;
            _materias[i] = m;
            return ;
        }
    }
    std::cout << "No space left!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    std::cout << "No Materia with the same type" << std::endl;
    return 0;
}