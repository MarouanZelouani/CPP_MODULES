#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    std::cout << "Ice Default Constructor called" << std::endl;
}

Ice::~Ice() {
    std::cout << "Ice Deonstructor called" << std::endl;
}

Ice::Ice(Ice& const obj) : AMateria(obj) {
    std::cout << "Ice Copy Constructor called" << std::endl;
    *this = obj;
}

Ice& Ice::operator=(Ice& const obj) {
    if (this != &obj) {
        this->type = obj.type;
    }
    return *this;
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice(); 
}
