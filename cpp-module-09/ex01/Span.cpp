#include "Span.hpp"

Span::Span(int size) : N(size)
{}

Span::~Span() 
{}

Span::Span(const Span& obj) : N(obj.N) {
    *this = obj;
}

Span& Span::operator=(const Span& obj) {
    if (this != &obj) {
        this->N = obj.N;
        this->vect = obj.vect;
    }
    return *this;
}

void Span::addNumber(int value) {
    if (vect.size() == N)
        throw std::runtime_error("Span is full!");
    vect.push_back(value);
}

int Span::shortestSpan() const {
    if (N < 3)
        throw std::runtime_error("Error: can't calculate shotest span!");
    
    std::vector<int> sorted_vect = vect;
    std::sort(sorted_vect.begin(), sorted_vect.end());

    int shortest_span = *(sorted_vect.begin() + 1) - *sorted_vect.begin();
    std::vector<int>::iterator itr;
    
    for (itr = sorted_vect.begin(); itr != sorted_vect.end() - 1; itr++) {
        int tmp = *(itr + 1) - *itr;
        if (tmp < shortest_span) shortest_span = tmp;
    }
    
    return shortest_span;
}

int Span::longestSpan() const {
    if (vect.empty() || N == 1)
        throw std::runtime_error("Error: can't calculate longest span!");
    int max_value = *std::max_element(vect.begin(), vect.end());
    int min_value = *std::min_element(vect.begin(), vect.end());
    return max_value - min_value;
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    size_t range = std::distance(begin, end);
    
    if (vect.size() + range > N)
        throw std::runtime_error("Error: can't add range!");
    
    vect.insert(vect.end(), begin, end);
}