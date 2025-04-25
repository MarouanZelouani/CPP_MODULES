#include <iostream>
#include <cctype> 

int main (int ac, char **av)
{
    int i, j;

    i = 1;
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        while (av[i])
        {
            j = 0;
            if (i != 1)
                std::cout << " ";
            while (av[i][j])
            {
                std::cout << (char)std::toupper(av[i][j]);
                j++;
            }
            i++;
        }
        std::cout << std::endl;
    }
}