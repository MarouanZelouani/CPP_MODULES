#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    // Bureaucrat construction and exception tests
    try {
        Bureaucrat b1(42, "Alice");
        std::cout << b1 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Bureaucrat Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2(0, "Bob");
    } catch (std::exception &e) {
        std::cout << "Bureaucrat Exception (too high): " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3(151, "Charlie");
    } catch (std::exception &e) {
        std::cout << "Bureaucrat Exception (too low): " << e.what() << std::endl;
    }

    // Increment and decrement tests
    try {
        Bureaucrat b4(2, "Diana");
        std::cout << b4 << std::endl;
        b4.incrementGrade();
        std::cout << "After increment: " << b4 << std::endl;
        b4.incrementGrade();
    } catch (std::exception &e) {
        std::cout << "Bureaucrat Exception (increment): " << e.what() << std::endl;
    }

    try {
        Bureaucrat b5(149, "Eve");
        std::cout << b5 << std::endl;
        b5.decrementGrade();
        std::cout << "After decrement: " << b5 << std::endl;
        b5.decrementGrade();
    } catch (std::exception &e) {
        std::cout << "Bureaucrat Exception (decrement): " << e.what() << std::endl;
    }

    // Form construction and exception tests
    try {
        Form f1("FormA", 50, 30);
        std::cout << f1 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Form Exception: " << e.what() << std::endl;
    }

    try {
        Form f2("FormB", 0, 30);
    } catch (std::exception &e) {
        std::cout << "Form Exception (sign grade too high): " << e.what() << std::endl;
    }

    try {
        Form f3("FormC", 151, 30);
    } catch (std::exception &e) {
        std::cout << "Form Exception (sign grade too low): " << e.what() << std::endl;
    }

    // Bureaucrat signing Form
    try {
        Bureaucrat signer(40, "Frank");
        Form f4("FormD", 50, 30);
        signer.signForm(f4);
        std::cout << f4 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Sign Exception: " << e.what() << std::endl;
    }

    // Bureaucrat with low grade tries to sign
    try {
        Bureaucrat low(100, "Grace");
        Form f5("FormE", 50, 30);
        low.signForm(f5);
        std::cout << f5 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Sign Exception (low grade): " << e.what() << std::endl;
    }

    return 0;
}