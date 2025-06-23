#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(Bureaucrat& target) : AForm::AForm(25, 5, "name"), _target(target){
    std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm Deconstructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : PresidentialPardonForm(obj._target) {
    std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;    
    *this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
    if (this != &obj) {
        // do something 
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    executor.executeForm(*this);
    if (this->getIsSigned())
        std::cout << _target.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    else 
        std::cout << "can't execute" << std::endl;
}