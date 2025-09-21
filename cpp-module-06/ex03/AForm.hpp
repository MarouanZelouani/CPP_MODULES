#ifndef __FORM_HPP_
#define __FORM_HPP_

#include <iostream>
#include <string>

class Bureaucrat;

class AForm 
{ 
private:
    const std::string _name;
    const int sign_grade;
    const int exec_grade;
    bool is_signed;

public:
    class GradeTooLowException : public std::exception {
        public: const char* what() const throw();
    };
    class GradeTooHighException : public std::exception {
        public: const char* what() const throw();
    };
    class ExecutingUnsignedFormException : public std::exception {
        public: const char* what() const throw();
    };
    AForm(std::string name, int sign_grade, int exec_grade);
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