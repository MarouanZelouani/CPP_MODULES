#include "iter.hpp"
#include <string>

template<typename T>
void displayElement(T x) {
    std::cout << "-> " << x << std::endl;
}

int main(void) {

    int size = 4;
    int arr[]  = {1, 12, 3, 4};

    std::cout << "INT ARRAY :\n"; 
    iter(arr, size, displayElement);

    size = 6;
    std::string s_array[size] = {"one", "two", "three", "four", "five", "six"};
    
    std::cout << "STRING ARRAY :\n"; 
    iter(s_array, size, displayElement);

    return 0;
}