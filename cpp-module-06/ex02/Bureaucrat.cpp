#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name) {
    std::cout << "Default Constructor called" << std::endl;
    if (grade < 1)
        throw GradeTooLowException();
    else if (grade > 150)
        throw GradeTooLowException();
    else 
        _grade = grade;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Deconstructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) {
    std::cout << "Copy Constructor called" << std::endl;
    *this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
    if (this != &obj) {
        this->_grade = obj._grade;
    }
    return *this;
}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    _grade--;
    if (_grade < 1)
        throw GradeTooLowException();
}

void Bureaucrat::decrementGrade() {
    _grade++;
    if (_grade > 150)
        throw GradeTooHighException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", Bureaucrat grade " << b.getGrade() << ".";
    return os;
}

void Bureaucrat::signForm(AForm& f) {
    try 
    {
        f.beSigned(*this);
    }
    catch (...)
    {
        std::cout << "couldn't sign" << std::endl;
    }
    std::cout << "signed" << std::endl;
}

void Bureaucrat::executeForm(AForm const & form) const {
    if (form.getExecGrade() <= this->_grade) {
        std::cout << "executed" << std::endl;
        return ;
    }
    std::cout << "couldn't execute" << std::endl;
    throw GradeTooLowException();
}