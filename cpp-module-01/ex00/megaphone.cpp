#include <iostream>
#include <cctype> 

int main (int ac, char **av)
{
    for (int i = 1; av[i]; ++i)
        for (int j = 0; av[i][j]; ++j)
            std::cout << (char)std::toupper(av[i][j]);
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
}