#ifndef _Cat_HPP__
#define _Cat_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain* brain;
public:
    Cat();
    ~Cat();
    Cat(const Cat& obj);
    Cat& operator=(const Cat& obj);
    void makeSound() const;
    void setIdea(std::string idea);
    void getIdeas() const;
};

#endif