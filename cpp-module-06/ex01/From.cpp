#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int sign_grade, int exec_grade) 
    : _name(name), sign_grade(sign_grade), exec_grade(exec_grade), is_signed(false) {
    std::cout << "Default Constructor called" << std::endl;
    if (sign_grade < 1 || exec_grade < 1)
        throw GradeTooLowException();
    else if (sign_grade > 150 || exec_grade > 150)
        throw GradeTooHighException();
}

Form::~Form() {
    std::cout << "Deconstructor called" << std::endl;
}

Form::Form(const Form& obj) : _name(obj._name), sign_grade(obj.sign_grade), exec_grade(obj.exec_grade) {
    std::cout << "Copy Constructor called" << std::endl;
    *this = obj;
}

Form& Form::operator=(const Form& obj) {
    if (this != &obj) {
        this->is_signed = obj.is_signed; 
    }
    return *this;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "grade too high!";
}


const char* Form::GradeTooLowException::what() const throw() {
    return "grade too Low!";
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
    if (b.getGrade() > sign_grade)
        throw GradeTooLowException();
    if (!is_signed)
        is_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form Name : " << f.getName() << std::endl;
    os << "Grade To sign : " << f.getSignGrade() << std::endl;
    os << "Grade to execute : " << f.getExecGrade() << std::endl;
    os << "signed : " << (f.getIsSigned() ? "true" : "false") << std::endl; 
    return os;
}