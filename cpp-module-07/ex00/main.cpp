#include "ScalarConverter.hpp"

int main(int ac, char** av) {

    std::string str[] = {
        "INT",
        "CHAR",
        "FLOAT",
        "DOUBLE",
        "ERROR"
    };
    
    if (ac != 2) {
        std::cout << "Usage: ./converter <argmument>" << std::endl;
        return EXIT_FAILURE;
    }
    // ScalarConverter sc;
    // sc.convert(av[1]);
    std::cout << str[getType(av[1])] << std::endl;
    
    return EXIT_SUCCESS;
}