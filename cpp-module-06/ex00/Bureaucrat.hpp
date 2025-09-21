#ifndef _BUREAUCRAT_HPP__
#define _BUREAUCRAT_HPP__

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat(int grade, std::string name);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& obj);
    Bureaucrat& operator=(const Bureaucrat& obj);
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    class GradeTooLowException : public std::exception {
        public: const char* what() const throw();
    };
    class GradeTooHighException : public std::exception {
        public: const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
