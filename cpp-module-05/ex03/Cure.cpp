#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << "Cure Default Constructor called" << std::endl;
}

Cure::~Cure() {
    std::cout << "Cure Deonstructor called" << std::endl;
}

Cure::Cure(const Cure& obj) : AMateria(obj) {
    std::cout << "Cure Copy Constructor called" << std::endl;
    *this = obj;
}

Cure& Cure::operator=(const Cure& obj) {  
    if (this != &obj) {
        this->type = obj.type;
    }
    return *this;
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}