#pragma once

#include <iostream>

template<typename T>
void iter(T* arr, size_t size, void (*func)(T const &)) {
    if (!arr || !func) return ;
    for (size_t i = 0; i < size; i++) {
        func(arr[i]);
    }
}

template<typename T>
void iter(T* arr, size_t size, void (*func)(T &)) {
    if (!arr || !func) return ;
    for (size_t i = 0; i < size; i++) {
        func(arr[i]);
    }
}