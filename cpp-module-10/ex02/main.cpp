#include "PmergeMe.hpp"

int main(int ac, char **av) {
    try {
        PmergeMe sorter;
        
        sorter.parseData(ac, av);
        
        sorter.displayBefore();
        
        // Measure time and sort
        // clock_t start = clock();
        sorter.sort();
        // clock_t end = clock();
        
        if (sorter.isSorted())
            std::cout << "OK\n";
        else 
            std::cout << "KO\n";

        // sorter.displayAfter();
        
        // // Calculate time in microseconds
        // double timeUsed = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
        
        // // Display timing
        // std::cout << "Time to process a range of " 
        //           << sorter.getData().size() 
        //           << " elements with std::vector : " 
        //           << timeUsed << " us" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}