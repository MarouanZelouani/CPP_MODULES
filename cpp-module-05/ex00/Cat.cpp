#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat DeConstructor called" << std::endl;
}

Cat::Cat(const Cat& obj) {
    std::cout << "Cat Copy Constructor called" << std::endl;
    *this = obj;
}

Cat& Cat::operator=(const Cat& obj) {
    if (this != &obj) {
        this->type = obj.type;
    }
    return *this;
}

std::string Cat::getType() const {
    return this->type;
}

void Cat::makeSound() const {
    std::cout << "meaw meaw" << std::endl;
}