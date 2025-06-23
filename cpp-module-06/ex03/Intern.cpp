#include "Intern.hpp"

Intern::Intern() {}
Intern::~Intern(){}
Intern::Intern(const Intern& obj) {}
Intern& Intern::operator=(const Intern& obj){}

AForm* Intern::makeForm(std::string& formName, std::string& formTarget) {
    
    std::cout << "Intern clreates " << formName << std::endl;
}