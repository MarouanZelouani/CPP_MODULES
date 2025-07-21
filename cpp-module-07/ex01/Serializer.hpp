#ifndef _SERIALIZER_HPP__
#define _SERIALIZER_HPP__

#include <iostream>
#include <cstdint>

struct Data {
    int x, y;
};

class Serializer {
    public:
        Serializer();
        ~Serializer();
        Serializer(const Serializer& obj);
        Serializer& operator=(const Serializer& obj);
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif