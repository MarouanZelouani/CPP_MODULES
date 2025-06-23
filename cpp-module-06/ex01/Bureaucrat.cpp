#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name) {
    std::cout << "Default Constructor called" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
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
    if (_grade == 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade == 150)
        throw GradeTooLowException();
    _grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", Bureaucrat grade " << b.getGrade() << ".";
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "grade too Low!";
}

void Bureaucrat::signForm(Form& f) const {
    try 
    {
        f.beSigned(*this);
        std::cout << "Bureaucrat " << _name << "successfuly signed ";
        std::cout << "The Form " << f.getName() <<  std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << *this << " couldn't sign form!" << std::endl;
        std::cout << e.what() << std::endl;
    }
}