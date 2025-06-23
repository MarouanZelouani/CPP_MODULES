#include "Bureaucrat.hpp"

int main (void)
{
    try {
        Bureaucrat me(1, "marouan");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}