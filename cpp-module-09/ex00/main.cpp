#include "easyfind.hpp"
#include <vector>

int main () {

    std::vector<int> vect;
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);
    vect.push_back(5);

    try {
        std::cout << *::easyfind(vect, 1) << " -> found!" << std::endl;
        std::cout << *::easyfind(vect, 10) << " -> found!" << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}