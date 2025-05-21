#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog Default Constructor called" << std::endl;
    brain = new Brain();
}

Dog::~Dog() {
    std::cout << "Dog DeConstructor called" << std::endl;
    delete brain;
}

Dog::Dog(const Dog& obj) {
    std::cout << "Dog Copy Constructor called" << std::endl;
    *this = obj;
}

Dog& Dog::operator=(const Dog& obj) {
    if (this != &obj) {
        this->type = obj.type;
    }
    return *this;
}

std::string Dog::getType() const {
    return this->type;
}

void Dog::makeSound() const {
    std::cout << "haw haw" << std::endl;
}