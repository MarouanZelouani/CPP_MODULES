#include "RPN.hpp"

int main (int ac, char **av) {

    if (ac > 1) {
        RPN rpn(av[1]);
        rpn.result();
    }
    return 0;
}