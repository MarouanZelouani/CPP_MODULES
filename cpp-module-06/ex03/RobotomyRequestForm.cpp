#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(Bureaucrat& target) : AForm(72, 45, "name"), _target(target){
    std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm Deconstructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : RobotomyRequestForm(obj._target) {
    std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;    
    *this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
    if (this != &obj) {
        // do something 
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    executor.executeForm(*this);
    std::cout << "+ Makes some drilling noises +" << std::endl;
    std::srand(std::time(0));
    int random = std::rand() % 2;
    if (random == 0) {
        std::cout << "+ robotomy failed +" << std::endl;
    } else {
        std::cout << "+" << _target.getName() << "has been robotomized +" << std::endl;
    }
}