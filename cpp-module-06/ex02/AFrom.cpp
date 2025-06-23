#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int sign_grade, int exec_grade) 
    : _name(name), sign_grade(sign_grade), exec_grade(exec_grade), is_signed(false) {
    std::cout << "Default Constructor called" << std::endl;
    if (sign_grade < 1 || exec_grade < 1)
        throw GradeTooLowException();
    else if (sign_grade > 150 || exec_grade > 150)
        throw GradeTooHighException();
}

AForm::~AForm() {
    std::cout << "Deconstructor called" << std::endl;
}

AForm::AForm(const AForm& obj) : _name(obj._name), sign_grade(obj.sign_grade), exec_grade(obj.exec_grade) {
    std::cout << "Copy Constructor called" << std::endl;
    *this = obj;
}

AForm& AForm::operator=(const AForm& obj) {
    if (this != &obj) {
        this->is_signed = obj.is_signed; 
    }
    return *this;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "grade too high!";
}


const char* AForm::GradeTooLowException::what() const throw() {
    return "grade too Low!";
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
    if (b.getGrade() > sign_grade)
        throw GradeTooLowException();
    if (!is_signed)
        is_signed = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form Name : " << f.getName() << std::endl;
    os << "Grade To sign : " << f.getSignGrade() << std::endl;
    os << "Grade to execute : " << f.getExecGrade() << std::endl;
    os << "signed : " << (f.getIsSigned() ? "true" : "false") << std::endl; 
    return os;
}