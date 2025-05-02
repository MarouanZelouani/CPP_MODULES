#include <iostream>
#include "Point.hpp"
#include <vector>

int main() {
    // Define the triangle vertices
    Point a(2, 3);
    Point b(6, 5);
    Point c(4, 8);

    Point p1(4.2, 6);
    // Define 10 test cases in a fixed-size array
    const int NUM_TESTS = 10;
    std::pair<Point, std::string> tests[NUM_TESTS];

    // Initialize array elements explicitly
    tests[0] = std::pair<Point, std::string>(p1, std::string("Inside"));
    tests[1] = std::pair<Point, std::string>(Point(3, 5), std::string("Inside"));
    tests[2] = std::pair<Point, std::string>(Point(0, 0), std::string("Outside"));
    tests[3] = std::pair<Point, std::string>(Point(10, 10), std::string("Outside"));
    tests[4] = std::pair<Point, std::string>(Point(2, 3), std::string("Vertex"));
    tests[5] = std::pair<Point, std::string>(Point(6, 5), std::string("Vertex"));
    tests[6] = std::pair<Point, std::string>(Point(4, 8), std::string("Vertex"));
    tests[7] = std::pair<Point, std::string>(Point(4, 4), std::string("Edge"));
    tests[8] = std::pair<Point, std::string>(Point(5, 6.5), std::string("Edge"));
    tests[9] = std::pair<Point, std::string>(Point(3, 5.5), std::string("Edge"));

    // Test each point
    // int passed = 0;
    for (int i = 0; i < NUM_TESTS; ++i) {
        std::cout << tests[i].first.getX() << std::endl;
        std::cout << tests[i].second << std::endl;
        
        // bool result = bsp(a, b, c, tests[i].first);
        // std::string expected = tests[i].second;
        // bool isInsideExpected = (expected == "Inside");
        // bool passedTest = (result == isInsideExpected);

        // // Print test details
        // std::cout << "Test " << (i + 1) << ": Point(" << tests[i].first.getX() << ", "
        //           << tests[i].first.getY() << "): Expected " << expected
        //           << ", Got " << (result ? "Inside" : "Outside")
        //           << " -> " << (passedTest ? "PASSED" : "FAILED") << "\n";

        // if (passedTest) {
        //     ++passed;
        // }
    }

    // Summary
    // std::cout << "\nTest Summary: " << passed << "/" << NUM_TESTS << " tests passed\n";
    // if (passed == NUM_TESTS) {
    //     std::cout << "All tests passed!\n";
    // } else {
    //     std::cout << "Some tests failed.\n";
    // }

    return 0;
}


// int main( void )
// {    
//     // Point a(2, 3);
//     // Point b(6, 5);
//     // Point c(4, 8);
    
//     // Point p1(4, 6); // Inside
//     // Point p2(6, 5); // On endge
//     // Point p3(4.5, 8.5); // Outside

//     Fixed x (0.7f);
//     Fixed y (0.6f);

//     std::cout << x + y;

//     // if (bsp(a, b, c, p2))
//     //     std::cout << "Point is inside the triangle" << std::endl; 
//     // else
//     //     std::cout << "Point is outside the triangle" << std::endl;
// }