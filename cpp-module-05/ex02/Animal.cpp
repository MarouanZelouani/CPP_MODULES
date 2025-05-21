#include "Animal.hpp"

Animal::Animal() : type("default_type") {
    std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
    std::cout << "Animal String Constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal Deconstructor called" << std::endl;
}

Animal::Animal (const Animal& obj) {
    std::cout << "Animal Copy Constructor called" << std::endl;
    *this = obj;
}

Animal& Animal::operator=(const Animal& obj) {
    if (this != &obj) {
        type = obj.type;
    }
    return *this;
}