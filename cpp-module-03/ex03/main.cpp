#include <iostream>
#include "Point.hpp"

int main( void )
{    
    Point a(2, 3);
    Point b(6, 5);
    Point c(4, 8);
    Point p(4, 6); 

    if (bsp(a, b, c, p)) 
        std::cout << "Point is inside the triangle" << std::endl;
    else 
        std::cout << "Point is outside the triangle" << std::endl;
}