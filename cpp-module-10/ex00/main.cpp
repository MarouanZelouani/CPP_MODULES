#include "BitcoinExchange.hpp"

int main (int ac, char** av) {
    (void)ac;
    
    try {
        BitcoinExchange bex;
        bex.exchange(av[1]);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}