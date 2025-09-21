#ifndef __FORM_HPP_
#define __FORM_HPP_

#include <iostream>
#include <string>

class Bureaucrat;

class Form 
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
    Form(std::string name, int sign_grade, int exec_grade);
    ~Form();
    Form(const Form& obj);
    Form& operator=(const Form& obj);
    std::string getName() const;
    int getSignGrade() const;
    int getExecGrade() const;
    bool getIsSigned() const;
    void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif