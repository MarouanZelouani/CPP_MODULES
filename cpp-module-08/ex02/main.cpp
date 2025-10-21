#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#include <string>

int main (void) {
    
    unsigned int size = 4;
    Array<int> arr(size);
    std::srand(static_cast<unsigned int>(std::time(0))); 

    for (unsigned int i = 0; i < size; i++) {
        int randomNumber = std::rand() % 20;
        arr[i] = randomNumber;
    }

    std::cout << arr << std::endl;

    size = 6;
    std::string s_array[size] = {"one", "two", "three", "four", "five", "six"};
    Array<std::string> s_arr(size);
    
    for (unsigned int i = 0; i < size; i++) {
        s_arr[i] = s_array[i];
    }

    std::cout << s_arr << std::endl;

    // try to access an out of range index
    try {
        s_arr[10] = "marouan";
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout <<  arr[-1] << "\n";
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
