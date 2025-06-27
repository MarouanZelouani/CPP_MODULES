#ifndef __PPF_HPP__
#define __PPF_HPP__

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;    
public:
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& obj);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
    void execute(Bureaucrat const & executor) const;
};

#endif