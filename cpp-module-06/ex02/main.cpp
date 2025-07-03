#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    try {
        Bureaucrat boss(1, "Boss");
        Bureaucrat worker(140, "Worker");

        ShrubberyCreationForm shrub0("gg");
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << "-------------------------------------\n";
        
        // Try signing and executing with a low-grade bureaucrat
        worker.signForm(shrub0);
        worker.executeForm(shrub0);
        std::cout << "-------------------------------------\n";

        // Boss signs and executes all forms
        boss.signForm(shrub);
        boss.executeForm(shrub);

        boss.signForm(robot);
        boss.executeForm(robot);

        boss.signForm(pardon);
        boss.executeForm(pardon);
        std::cout << "-------------------------------------\n";

        // Try to execute unsigned form
        ShrubberyCreationForm notSigned("fail");
        boss.executeForm(notSigned);

    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}