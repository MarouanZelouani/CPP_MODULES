#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(Bureaucrat& target) : AForm(145, 137, "name"), _target(target){
    std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Deconstructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : ShrubberyCreationForm(obj._target) {
    std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;    
    *this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
    if (this != &obj) {
        // do something 
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    std::string newFileName = this->_target.getName() + "_shrubbery";
    std::ofstream file(newFileName.c_str());
    
    executor.executeForm(*this);
    if (!this->getIsSigned())
    {
        std::cerr << "Error : can't execute the Form" << std::endl;
        return ;
    }    
    if (file.is_open())
    {
        file << "     ccee88oo\n";
        file << "  C8O8O8Q8PoOb o8oo\n";
        file << " dOB69QO8PdUOpugoO9bD\n";
        file << "CgggbU8OU qOp qOdoUOdcb\n";
        file << "    6OuU  /p u gcoUodpP\n";
        file << "      \\\\//  /douUP\n";
        file << "        \\\\////\n";
        file << "         |||/\\\n";
        file << "         |||\\/\n";
        file << "         |||||\n";
        file << "   .....//||||\\....\n";
    }
    else 
        std::cerr << "Error : can't open file!" << std::endl;
    file.close();
}