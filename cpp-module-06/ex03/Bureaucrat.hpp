#ifndef _BUREAUCRAT_HPP__
#define _BUREAUCRAT_HPP__

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
    };
    class GradeTooHighException : public std::exception 
    {
        public:
            const char* what() const throw();
    };
    Bureaucrat(int grade, std::string name);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& obj);
    Bureaucrat& operator=(const Bureaucrat& obj);
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(AForm& f) const;
    void executeForm(AForm const & form) ;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
