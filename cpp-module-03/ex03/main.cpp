#include <iostream>
#include "Point.hpp"
#include <vector>

int main( void )
{    
    Point a(2, 3);
    Point b(6, 5);
    Point c(4, 8);
    
    std::vector<std::pair<Point, std::string>> tests = {
    // Inside the triangle
    {Point(4, 6), "Inside"},            // Inside the triangle
    {Point(3.5, 5), "Inside"},          // Inside the triangle
    {Point(4.2, 6), "Inside"},          // Inside the triangle
    {Point(3, 4), "Inside"},            // Inside the triangle

    // On the edge of the triangle
    {Point(5, 6), "Inside"},            // Near the edge but still inside
    {Point(2, 3), "Edge/Vertex"},       // Vertex of the triangle
    {Point(6, 5), "Edge/Vertex"},       // Vertex of the triangle
    {Point(4, 8), "Edge/Vertex"},       // Vertex of the triangle
    {Point(3, 4.5), "Edge/Vertex"},     // Point lies on the edge between A and B
    {Point(5, 6.5), "Edge/Vertex"},     // Point lies on the edge between B and C
    {Point(4, 5), "Edge/Vertex"},       // Point lies on the edge between A and C

    // Outside the triangle
    {Point(1, 1), "Outside"},           // Outside the triangle, far to the left
    {Point(6, 7), "Outside"},           // Outside the triangle, above vertex B
    {Point(4.5, 8.5), "Outside"},      // Outside the triangle, above vertex C
    {Point(6.1, 5), "Outside"},        // Outside the triangle, slightly to the right of vertex B
    {Point(0, 3), "Outside"}           // Outside the triangle, to the left of vertex A
};

    for (size_t i = 0; i < tests.size(); ++i) {
        std::cout << "Test " << i + 1 << " (" << tests[i].second << "): ";
        if (bsp(a, b, c, tests[i].first))
            std::cout << "Point is inside the triangle" << std::endl; 
        else
            std::cout << "Point is outside the triangle" << std::endl;
    } 

}