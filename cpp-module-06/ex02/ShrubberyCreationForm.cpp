#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrub", 145, 137) {
    std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
    this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Deconstructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj) {
    std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;    
    *this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
    if (this != &obj) {
        AForm::operator=(obj);
        this->_target = obj._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw ExecutingUnsignedFormException();
    if (executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    std::string newFileName = this->_target + "_shrubbery";
    std::ofstream file(newFileName.c_str());
    
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