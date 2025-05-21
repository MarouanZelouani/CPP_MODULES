#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat Default Constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat DeConstructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj) {
    std::cout << "WrongCat Copy Constructor called" << std::endl;
    *this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat& obj) {
    if (this != &obj) {
        this->type = obj.type;
    }
    return *this;
}

std::string WrongCat::getType() const {
    return this->type;
}

void WrongCat::makeSound() const {
    std::cout << "wrong_cat meaw meaw" << std::endl;
}