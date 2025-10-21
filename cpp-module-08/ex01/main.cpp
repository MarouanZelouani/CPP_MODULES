#include "iter.hpp"
#include <string>

template<typename T>
void displayElement(const T& x) {
    std::cout << "-> " << x << std::endl;
}

void toUp(std::string& s) {
    for (size_t i = 0; i < s.length(); ++i) {
        s[i] -= 32;
    }
}

int main(void) {

    int size = 4;
    int arr[size] = {1, 2, 3, 4}; 
    std::cout << "INT ARRAY :\n"; 
    iter(arr, size, displayElement);

    size = 6;
    std::string s_array[size] = {"one", "two", "three", "four", "five", "six"};
    
    std::cout << "STRING ARRAY :\n"; 
    iter(s_array, size, displayElement);
    iter(s_array, size, toUp);
    std::cout << "---------------\n";
    iter(s_array, size, displayElement);

    return 0;
}