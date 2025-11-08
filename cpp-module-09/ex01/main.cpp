#include "Span.hpp"

int main() {
    
    try {
        Span sp = Span(5);
    
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

    
        Span sp1(6);
        int arr[] = {1, 2, 3, 4, 5, 6};
        std::vector<int> vect(arr, arr + 6);
        
        sp1.addRange(vect.begin(), vect.end());
        std::cout << sp1.shortestSpan() << std::endl;
        std::cout << sp1.longestSpan() << std::endl;

        sp1.addNumber(12);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    
    return 0;
}