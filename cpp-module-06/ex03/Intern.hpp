#ifndef __INTERN_HPP_
#define __INTERN_HPP_

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern 
{
public:
    Intern();
    ~Intern();
    Intern(const Intern& obj);
    Intern& operator=(const Intern& obj);
    AForm* makeForm(std::string& formName, std::string& formTarget);
};

#endif