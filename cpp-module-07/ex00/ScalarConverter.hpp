#ifndef _SCALAR_CONVERTER_HPP__
#define _SCALAR_CONVERTER_HPP__

#include <iostream>
#include <string>
#include <exception>
#include <cctype>
#include <sstream>
#include <iomanip>

enum TYPES {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SPECIAL,
    ERROR
};

class ScalarConverter {
    private:
        ScalarConverter();
        ~ScalarConverter();
    public:
        static void convert(const std::string& str);
};

int getType(const std::string& str);

#endif