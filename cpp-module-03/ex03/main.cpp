#include <iostream>
#include "Point.hpp"

int main()
{
    Point a(2, 3);
    Point b(6, 5);
    Point c(4, 8);

    const int NUM_TESTS = 14;
    Point tests[NUM_TESTS] = 
    {
        // Inside
        Point(4.5, 6),  
        Point(3, 5),    
        Point(2.5, 3.5),
        Point(5.5, 5.5),

        // Outside
        Point(0, 0),        
        Point(6.001, 5),
        Point(10, 10),
        Point(4, 7.999),

        // Vertex/Edge
        Point(2, 3),        
        Point(6, 5),        
        Point(4, 8),        
        Point(4, 4),        
        Point(5, 6.5),      
        Point(3, 5.5)       
    };

    for (int i = 0; i < NUM_TESTS; ++i) {
        bool result = bsp(a, b, c, tests[i]);
        std::string res("Outside");
        if (result)
            res = "Inside";
        std::cout << "Test " << (i + 1) << ": Point(" << tests[i].getX() << ", "
            << tests[i].getY() << ")"
            << ", Got " << res << std::endl;
    }

    return 0;
}