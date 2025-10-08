#include "ScalarConverter.hpp"

bool isSpecila(const std::string& str)
{
    if (str == "-inf" || str == "+inf" || str == "nan")
        return true;
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return true;    
    return false;
}

bool isAllDigits(const std::string& str)
{
    size_t itr = 0;
    if (str.empty()) return false;
    if (str[itr] == '-' || str[itr] == '+')
        ++itr;
    while (itr < str.length())
    {            
        if (!std::isdigit(static_cast<unsigned char>(str[itr])))
            return false;
        ++itr;
    }
    return true;
}

bool isValidFloat(const std::string& str)
{
    int dotCouter = 0;
    size_t itr = 0;
    int fCounter = 0;
    if (str[itr] == '-' || str[itr] == '+')
        ++itr;
    for (; itr < str.length(); ++itr)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[itr])))
        {
            if (str[itr] == 'f')
                fCounter++;
            else if (str[itr] == '.')
                dotCouter++;
            else 
                return false;
        }
    }
    if (dotCouter > 1 || fCounter > 1)
        return false;
    if (str[str.size() - 1] != 'f' && fCounter)
        return false;
    if (str[str.size() - 1] == 'f' && !dotCouter)
        return false;
    if (dotCouter == 1) 
    {
        size_t dotPos = str.find('.');
        if (dotPos == 0 || dotPos == str.length() - 1)
            return false;
        if (fCounter == 1 && dotPos == str.length() - 2)
            return false;
    }
    return true;
}

int getType(const std::string& str) 
{
    if (str.empty()) return CHAR;
    if (isSpecila(str)) return SPECIAL;
    if (str.length() == 1) 
    {
        if (!std::isdigit(static_cast<unsigned char>(str[0])))
            return CHAR;
        return INT;
    } 
    if (isAllDigits(str))
        return INT;
    if (isValidFloat(str))
    {
        if (str[str.size() - 1] == 'f')
            return FLOAT;
        return DOUBLE;
    }
    return ERROR;
}