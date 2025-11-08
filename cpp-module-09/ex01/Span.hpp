#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

class Span {
private:
    unsigned int N;
    std::vector<int> vect;
public:
    Span(int size);
    ~Span();
    Span(const Span& obj);
    Span& operator=(const Span& obj);
    void addNumber(int value);
    int shortestSpan() const;
    int longestSpan() const;
    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};