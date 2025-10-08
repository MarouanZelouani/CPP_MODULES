#include "ScalarConverter.hpp"

int main(int ac, char** av) {

    // std::string str[] = {
    //     "INT",
    //     "CHAR",
    //     "FLOAT",
    //     "DOUBLE",
    //     "ERROR"
    // };
    
    if (ac != 2) {
        std::cout << "Usage: ./converter <argmument>" << std::endl;
        return 1;
    }

    // test getType more
    // std::cout << str[getType(av[1])] << std::endl;
    try {
        ScalarConverter::convert(av[1]);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}