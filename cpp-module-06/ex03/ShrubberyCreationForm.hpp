#ifndef __SCF_HPP__
#define __SCF_HPP__

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;    
public:
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& obj);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
    void execute(Bureaucrat const & executor) const;
};

#endif