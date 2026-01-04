#include "RPN.hpp"

RPN::RPN(std::string input) : _input(input) {}

RPN::~RPN() {}

RPN::RPN(const RPN& obj) {
    *this = obj;
}

RPN& RPN::operator=(const RPN& obj) {
    if (this != &obj) {
        _input = obj._input;
        _stack = obj._stack;
    }   
    return *this;
}

void RPN::result() {
    std::string opers = "+-/*";

    if (_input.empty()) {
        std::cerr << "Error" << std::endl;
        return ;
    }
    
    for (size_t i = 0 ; i < _input.size(); ++i) {
        if (std::isdigit(_input[i]))
                _stack.push(_input[i] - '0'); 
        else if (opers.find(_input[i]) != std::string::npos) {
            
            if (_stack.size() < 2) {
                std::cerr << "Error" << std::endl;
                return;
            }
            
            int tmp2 = _stack.top();
            _stack.pop();
            int tmp1 = _stack.top();
            _stack.pop();
            
            if (_input[i] == '/' && tmp2 == 0) {
                std::cerr << "Error" << std::endl;
                return;
            }

            _stack.push(executeOper(tmp1, tmp2, _input[i]));
        }
        else if (_input[i] == ' ')
            continue;
        else {
            std::cerr << "Error" << std::endl;
            return;
        }
    }

    if (_stack.size() != 1) {
        std::cerr << "Error" << std::endl;
        return;
    }

    std::cout << _stack.top() << std::endl;
}

int RPN::executeOper(int val1, int val2, char op) {
    int result = val1 + val2;
    
    if (op == '-') result = val1 - val2;
    else if (op == '*') result = val1 * val2;
    else if (op == '/') result = val1 / val2;

    return result;
}