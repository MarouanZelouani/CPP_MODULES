#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    brain = new Brain();
    std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat DeConstructor called" << std::endl;
    delete brain;
}

Cat::Cat(const Cat& obj) {
    std::cout << "Cat Copy Constructor called" << std::endl;
    *this = obj;

}

Cat& Cat::operator=(const Cat& obj) {
    if (this != &obj) {
        this->type = obj.type;
        brain = new Brain(*obj.brain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "meaw meaw" << std::endl;
}

void Cat::setIdea(std::string idea) {
    brain->setIdea(idea);
}

void Cat::getIdeas() const {
    
    std::string idea;
    for(int i = 0; i < 100; i++) {
        idea = brain->getIdea(i);
        if (idea.empty())
            return ;
        std::cout << "Idea " << i << " - " << idea << std::endl;
    }
}
