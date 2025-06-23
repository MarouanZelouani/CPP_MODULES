#include "AForm.hpp"

AForm::AForm(int sign_grade, int exec_grade, std::string name) 
    : _name(name), sign_grade(sign_grade), exec_grade(exec_grade) {
    std::cout << "Default Constructor called" << std::endl;
    if (sign_grade < 1 || exec_grade < 1)
        throw GradeTooLowException();
    else if (sign_grade > 150 || exec_grade > 150)
        throw GradeTooHighException();
}

AForm::~AForm() {
    std::cout << "Deconstructor called" << std::endl;
}

AForm::AForm(const AForm& obj) : AForm(obj.sign_grade, obj.exec_grade, obj._name) {
    std::cout << "Copy Constructor called" << std::endl;
    // *this = obj;
}

AForm& AForm::operator=(const AForm& obj) {
    if (this != &obj) {
        // do noting 
    }
    return *this;
}

std::string AForm::getName() const {
    return _name; 
}

int AForm::getSignGrade() const {
    return sign_grade;
}

int AForm::getExecGrade() const {
    return exec_grade;
}

bool AForm::getIsSigned() const {
    return is_signed;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() >= sign_grade && !is_signed)
        is_signed == true;
    else
        throw GradeTooLowException(); 
}

// std::ostream& operator<<(std::ostream& os, const AForm& f) {
//     // os << b.getName() << ", Bureaucrat grade " << b.getGrade() << ".";
//     return os;
// }