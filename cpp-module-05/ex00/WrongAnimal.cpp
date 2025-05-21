#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("default_type") {
    std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
    std::cout << "WrongAnimal String Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal Deconstructor called" << std::endl;
}

WrongAnimal::WrongAnimal (const WrongAnimal& obj) {
    std::cout << "WrongAnimal Copy Constructor called" << std::endl;
    *this = obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) {
    if (this != &obj) {
        type = obj.type;
    }
    return *this;
}

std::string WrongAnimal::getType() const {
    return this->type;
}

void WrongAnimal::makeSound() const {
    std::cout << "wrong_animal no sound" << std::endl;
}