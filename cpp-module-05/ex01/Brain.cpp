#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain DeConstructor called" << std::endl;
}

Brain::Brain(const Brain& obj) {
    std::cout << "Brain Copy Constructor called" << std::endl;
    *this = obj;
}

Brain& Brain::operator=(const Brain& obj) {
    if (this != &obj) {
       //
    }
    return *this;
}
