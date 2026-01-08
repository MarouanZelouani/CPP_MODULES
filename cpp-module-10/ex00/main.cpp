#include "BitcoinExchange.hpp"

int main (int ac, char** av) {
    if (ac != 2) {
        std::cerr << "Error: no input provided!" << std::endl;
        return 1;
    }
    
    try {
        BitcoinExchange exchange;
        exchange.processInput(av[1]);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}