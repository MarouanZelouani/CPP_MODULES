#include "PmergeMe.hpp"

int main(int ac, char **av) {
    try {
        PmergeMe sorter;
        
        sorter.parseData(ac, av);
        
        sorter.sort();

        sorter.displayResult();  
        
        // if (sorter.isVectorSorted() && sorter.isDequeSorted())
        //     std::cout << "=======> OK\n";
        // else 
        //     std::cout << "=======> KO!\n";
        
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}