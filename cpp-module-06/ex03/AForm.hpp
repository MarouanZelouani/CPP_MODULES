#ifndef __FORM_HPP_
#define __FORM_HPP_

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class AForm 
{ 
private:
    const std::string _name;
    bool is_signed = false;
    const int sign_grade;
    const int exec_grade;

public:
    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw() {
                return "Grade too low!";
            }
    };
    class GradeTooHighException : public std::exception 
    {
        public:
            const char* what() const throw() {
                return "Grade too high!";
            }
    };
    AForm(int sign_grade, int exec_grade, std::string name);
    virtual ~AForm();
    AForm(const AForm& obj);
    AForm& operator=(const AForm& obj);
    std::string getName() const;
    int getSignGrade() const;
    int getExecGrade() const;
    bool getIsSigned() const;
    void beSigned(const Bureaucrat& b);
    virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif