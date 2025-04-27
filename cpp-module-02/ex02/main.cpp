#include <iostream>
#include <string>

int main ()
{
    std::string str("HI THIS IS BRAIN");
    
    std::string *stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "str address : " << &str << std::endl;
    std::cout << "the address held by stingPTR : " << stringPTR << std::endl;
    std:: cout << "the address held by stringREF : " << &stringREF << std::endl; 

    std::cout << "str value : " << str << std::endl;
    std::cout << "the value pointed to by stingPTR : " << *stringPTR << std::endl;
    std:: cout << "the value pointed to by stringREF : " << stringREF << std::endl; 
}