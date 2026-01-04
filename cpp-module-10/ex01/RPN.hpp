#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <cctype>

class RPN {
private:
    std::string _input;
    std::stack<int> _stack;
public:
    RPN(std::string input);
    ~RPN();
    RPN(const RPN& obj);
    RPN& operator=(const RPN& obj);

    void result();

private:
    int executeOper(int val1, int val2, char op);
};