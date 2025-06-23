#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(Bureaucrat* target) : AForm::AForm("name", 25, 5) {
    std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
    this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm Deconstructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj) {
    std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;    
    *this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
    if (this != &obj) {
        this->_target = obj._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {

    if (executor.getGrade() > this->getExecGrade() || !this->getIsSigned())
        throw GradeTooLowException();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}