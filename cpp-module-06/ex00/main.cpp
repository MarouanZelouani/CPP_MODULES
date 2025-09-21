#include "Bureaucrat.hpp"

int main(void)
{
    // Bureaucrat construction and exception tests
    try {
        Bureaucrat b1(42, "b1");
        std::cout << b1 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Bureaucrat Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2(0, "b2");
    } catch (std::exception &e) {
        std::cout << "Bureaucrat Exception (too high): " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3(151, "b3");
    } catch (std::exception &e) {
        std::cout << "Bureaucrat Exception (too low): " << e.what() << std::endl;
    }
    std::cout << "---------------------------------------------\n";
    
    // Increment and decrement tests
    try {
        Bureaucrat b4(2, "b4");
        std::cout << b4 << std::endl;
        b4.incrementGrade();
        std::cout << "After increment: " << b4 << std::endl;
        b4.incrementGrade();
    } catch (std::exception &e) {
        std::cout << "Bureaucrat Exception (increment): " << e.what() << std::endl;
    }

    try {
        Bureaucrat b5(149, "b5");
        std::cout << b5 << std::endl;
        b5.decrementGrade();
        std::cout << "After decrement: " << b5 << std::endl;
        b5.decrementGrade();
    } catch (std::exception &e) {
        std::cout << "Bureaucrat Exception (decrement): " << e.what() << std::endl;
    }
    return 0;
}