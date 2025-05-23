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
        for (int i = 0; i < 100; i++)
            ideas[i] = obj.ideas[i];
    }
    return *this;
}

void Brain::setIdea(std::string idea) {
    for (int i = 0; i < 100; i++) {
        if (ideas[i].empty()) {
            ideas[i] = idea;
            return ;
        }
    }
}

std::string Brain::getIdea(int idx) const {
    if (idx >= 0 && idx < 100)
        return ideas[idx];
    return "";
}
