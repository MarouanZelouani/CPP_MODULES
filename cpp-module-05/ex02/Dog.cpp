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
        this->brain = new Brain(*obj.brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "haw haw" << std::endl;
}

void Dog::setIdea(std::string idea) {
    brain->setIdea(idea);
}

void Dog::getIdeas() const {
    
    std::string idea;
    for(int i = 0; i < 100; i++) {
        idea = brain->getIdea(i);
        if (idea.empty())
            return ;
        std::cout << "Idea " << i << " - " << idea << std::endl;
    }
}

