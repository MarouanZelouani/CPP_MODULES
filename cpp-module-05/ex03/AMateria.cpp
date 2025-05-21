#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) {
    std::cout << "AMateria Default Constructor called" << std::endl;
    this->type = type;
}

AMateria::AMateria(AMateria& const obj) {
    std::cout << "AMateria Copy Constructor called" << std::endl;
    *this = obj;
}

AMateria& AMateria::operator=(AMateria& const obj) {
    if (this != &obj) {
        this->type = obj.type;
    }
    return *this;
}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "* do somthing with " << target.getName() << " *" << std::endl; 
}