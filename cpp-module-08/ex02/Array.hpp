#pragma once

#include <iostream>

template<typename T>
class Array {
    private:
        T* array;
        unsigned int _size;
    public:
        Array();
        ~Array();
        Array(unsigned int n);
        Array(const Array& obj);
        Array& operator=(const Array& obj);
        const T& operator[](unsigned int index) const;
        T& operator[](unsigned int index);
        unsigned int size() const;
};

template<typename T>
Array<T>::Array() : array(NULL), _size(0) {}

template<typename T>
Array<T>::~Array() { delete[] array; }

template<typename T>
Array<T>::Array(unsigned int n) : _size(n) {
    array = new T[n]; 
}

template<typename T>
Array<T>::Array(const Array<T>& obj) : _size(obj._size) {
    array = new T[_size];
    for (unsigned int i = 0; i < _size; i++) {
        array[i] = obj.array[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj) {
    if (this != &obj) {
        delete[] array;
        _size = obj._size;
        array = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            array[i] = obj.array[i];
        }         
    }
    return *this;
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");;
    return array[index];
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");;
    return array[index];
}

template<typename T>
unsigned int Array<T>::size() const {
    return _size;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr) {
    if (!arr.size())
        os << "{}." << std::endl;
    else {
        os << "{";
        for (unsigned int i = 0; i < arr.size(); i++) {
            os << arr[i];
            if (i != arr.size() - 1) 
                os << " ,"; 
        }
        os << "}.";
    } 
    return os;
}