#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robot", 72, 45) {
    std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
    this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm Deconstructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj) {
    std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;    
    *this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
    if (this != &obj) {
        AForm::operator=(obj);
        this->_target = obj._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw ExecutingUnsignedFormException();
    if (executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    std::cout << "+ Makes some drilling noises +" << std::endl;
    std::srand(std::time(0));
    int random = std::rand() % 2;
    if (random == 0)
        std::cout << "+ robotomy failed +" << std::endl;
    else
        std::cout << "+ " << _target << "has been robotomized +" << std::endl;
}