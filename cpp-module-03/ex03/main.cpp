#include <iostream>
#include "Point.hpp"
#include <vector>

int main( void )
{    
    Point a(2, 3);
    Point b(6, 5);
    Point c(4, 8);
    
    Point p1(4, 6); // Inside
    Point p2(6, 5); // On endge
    Point p3(4.5, 8.5); // Outside

    if (bsp(a, b, c, p2))
        std::cout << "Point is inside the triangle" << std::endl; 
    else
        std::cout << "Point is outside the triangle" << std::endl;
}