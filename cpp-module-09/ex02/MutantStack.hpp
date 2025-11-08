#pragma once

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

public:
    MutantStack();
    ~MutantStack();
    MutantStack(const MutantStack& obj);
    MutantStack& operator=(const MutantStack& obj);

    typedef typename std::stack<T>::container_type::iterator iterator;
    // typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin();
    iterator end();

    // const_iterator begin();
    // const_iterator end();
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() 
{}

template <typename T>
MutantStack<T>::~MutantStack() 
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& obj) : std::stack<T>(obj) 
{}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& obj) {
    if (this != &obj)
        std::stack<T>::opreator=(obj);
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}