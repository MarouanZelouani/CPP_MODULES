#include "Intern.hpp"

Intern::Intern() { std::cout << "Intern Constructor called" << std::endl; }

Intern::~Intern(){ std::cout << "Intern Deconstructor called" << std::endl; }

Intern::Intern(const Intern& obj) { 
    std::cout << "Intern Copy Constructor called" << std::endl; 
    *this = obj;  
}

Intern& Intern::operator=(const Intern& obj) {
    (void)obj;
    return *this;
}

AForm* makePresidentialFrom(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm* makeRobotomyFrom(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* makeShrubberyForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string& formName, std::string& formTarget) {   
    std::string formTypes[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    typedef AForm* (*FormCreator)(std::string);
    FormCreator creators[3] = {makePresidentialFrom, makeRobotomyFrom, makeShrubberyForm};
    
    for (int i = 0; i <= 3; i++) {
        if (formName == formTypes[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](formTarget);
        }
    }

    std::cout << "form " << formName << " does't exist" << std::endl;
    return NULL;
}