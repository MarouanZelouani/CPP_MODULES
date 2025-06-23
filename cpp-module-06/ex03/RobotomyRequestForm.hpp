#ifndef __RRF_HPP__
#define __RRF_HPP__

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    Bureaucrat* _target;    
public:
    RobotomyRequestForm(Bureaucrat* target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& obj);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
    void execute(Bureaucrat const & executor) const;
};

#endif