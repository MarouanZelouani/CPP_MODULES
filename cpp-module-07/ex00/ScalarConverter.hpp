#ifndef _SCALAR_CONVERTER_HPP__
#define _SCALAR_CONVERTER_HPP__

#include <iostream>
#include <string>
#include <exception>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <limits>

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
        ScalarConverter(const ScalarConverter& obj);
        ScalarConverter& operator=(const ScalarConverter& obj);
    public:
        static void convert(const std::string& str);
};

int getType(const std::string& str);

#endif