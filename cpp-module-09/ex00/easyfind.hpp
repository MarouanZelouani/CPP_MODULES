#pragma once

#include <iostream>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &container, int value) {
    typedef typename T::iterator Iter;
    Iter it = find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("not found!");
    return it;
}
