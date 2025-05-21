#include "Cure.hpp"

Cure::Cure() : AMateria("Cure") {
    std::cout << "Cure Default Constructor called" << std::endl;
}

Cure::~Cure() {
    std::cout << "Cure Deonstructor called" << std::endl;
}

Cure::Cure(Cure& const obj) : AMateria(obj) {
    std::cout << "Cure Copy Constructor called" << std::endl;
    *this = obj;
}

Cure& Cure::operator=(Cure& const obj) {  
    if (this != &obj) {
        this->type = obj.type;
    }
    return *this;
}

AMateria* Cure::clone() const {
    return new Cure();
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}