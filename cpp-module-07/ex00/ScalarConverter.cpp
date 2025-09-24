#include "ScalarConverter.hpp"

void CharConverter(const std::string& str) {
    std::cout << "char: ";
    if (!std::isprint(static_cast<unsigned char>(str[0])))
        std::cout << "Non displayable" << std::endl;
    else 
        std::cout << str[0] << std::endl;
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(str[0]) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(str[0]) << std::endl;
}

void IntConverter(const std::string& str) {
    int int_n;
    std::istringstream is(str);
    if (!(is >> int_n))
        throw std::runtime_error("Error!");
    std::cout << "char: ";
    if (int_n < 0 || int_n > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(int_n)))
        std::cout << "Non displayable" << std::endl;
    else 
        std::cout << static_cast<char>(int_n) << std::endl;
    std::cout << "int: " << int_n << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(int_n) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(int_n)<< std::endl;
}


void FloatConverter(const std::string& str) {
    float float_n;
    std::istringstream is(str);
    if (!(is >> float_n))
        throw std::runtime_error("Error!");
    std::cout << "char: ";
    if (float_n < 0 || float_n > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(float_n)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << static_cast<char>(float_n) << std::endl;
    std::cout << "int: " << static_cast<int>(float_n) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << float_n << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(float_n)<< std::endl;
}

void DoubleConverter(const std::string& str) {
    double double_n;
    std::istringstream is(str);
    if (!(is >> double_n))
        throw std::runtime_error("Error!");
    std::cout << "char: ";
    if (double_n < 0 || double_n > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(double_n)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << static_cast<char>(double_n) << std::endl;
    std::cout << "int: " << static_cast<int>(double_n) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(double_n) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << double_n << std::endl;
}

void ScalarConverter::convert(const std::string& str) {
    if (str.empty())
        throw std::runtime_error("Empty string!");
    int type = getType(str);
    if (type == ERROR)
        throw std::runtime_error("Error!");
    switch (type)
    {
        case CHAR:
            CharConverter(str);
            break;
        case INT:
            IntConverter(str);
            break;
        case FLOAT:
            FloatConverter(str);
            break;
        case DOUBLE:
            DoubleConverter(str);
            break;
    }  
}