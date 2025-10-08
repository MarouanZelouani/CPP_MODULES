#ifndef _SERIALIZER_HPP__
#define _SERIALIZER_HPP__

#include <iostream>

typedef unsigned long uintptr_t;

struct Data {
    int x, y;
};

class Serializer {
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer& obj);
        Serializer& operator=(const Serializer& obj);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif