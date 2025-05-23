#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog DeConstructor called" << std::endl;
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

void Dog::makeSound() const {
    std::cout << "haw haw" << std::endl;
}