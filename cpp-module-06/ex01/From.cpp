#include "Form.hpp"

Form::Form(int sign_grade, int exec_grade, std::string name) 
    : _name(name), sign_grade(sign_grade), exec_grade(exec_grade) {
    std::cout << "Default Constructor called" << std::endl;
    if (sign_grade < 1 || exec_grade < 1)
        throw GradeTooLowException();
    else if (sign_grade > 150 || exec_grade > 150)
        throw GradeTooHighException();
}

Form::~Form() {
    std::cout << "Deconstructor called" << std::endl;
}

Form::Form(const Form& obj) : Form(obj.sign_grade, obj.exec_grade, obj._name) {
    std::cout << "Copy Constructor called" << std::endl;
    // *this = obj;
}

Form& Form::operator=(const Form& obj) {
    if (this != &obj) {
        // do noting 
    }
    return *this;
}

std::string Form::getName() const {
    return _name; 
}

int Form::getSignGrade() const {
    return sign_grade;
}

int Form::getExecGrade() const {
    return exec_grade;
}

bool Form::getIsSigned() const {
    return is_signed;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() >= sign_grade && !is_signed)
        is_signed == true;
    else
        throw GradeTooLowException(); 
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    // os << b.getName() << ", Bureaucrat grade " << b.getGrade() << ".";
    return os;
}