#ifndef __SCF_HPP__
#define __SCF_HPP__

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    Bureaucrat* _target;    
public:
    ShrubberyCreationForm(Bureaucrat* target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& obj);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
    void execute(Bureaucrat const & executor) const;
};

#endif