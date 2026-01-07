#include "PmergeMe.hpp"

int main(int ac, char **av) {
    try {
        PmergeMe sorter;
        
        sorter.parseData(ac, av);
        
        sorter.sort();

        sorter.displayResult();    
        
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}