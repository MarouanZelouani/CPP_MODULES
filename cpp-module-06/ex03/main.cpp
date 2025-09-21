#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
    try
    {
        Intern someIntern;
        Bureaucrat boss(1, "Boss");
        Bureaucrat worker(140, "Worker");
    
        std::string formNames[] = {
            "presidential pardon",
            "robotomy request",
            "shrubbery creation",
            "unknown form"
        };
        std::cout << "-------------------------------------\n";
        std::cout << "-------------------------------------\n";
        
        for (int i = 0; i < 4; ++i) {
            std::string target = "Target_" + formNames[i];
            AForm* form = someIntern.makeForm(formNames[i], target);
            if (form) {
                boss.signForm(*form);
                boss.executeForm(*form);
                delete form;
            }
            std::cout << "-------------------------------------\n";
        }
        std::cout << "-------------------------------------\n";
        
        // Test with a worker who can't sign or execute
        std::string target = "Garden";
        AForm* shrub = someIntern.makeForm(formNames[2], target);
        if (shrub) {
            worker.signForm(*shrub);
            worker.executeForm(*shrub);
            delete shrub;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}