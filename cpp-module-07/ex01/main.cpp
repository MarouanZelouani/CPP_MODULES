#include "Serializer.hpp"

int main (void) {
    
    Data data;
    data.x = 1;
    data.y = 2;

    Serializer sr;

    uintptr_t raw = sr.serialize(&data);
    Data* newData = sr.deserialize(raw);

    std::cout << "Original address: " << &data << std::endl;
    std::cout << "Deserialized address: " << newData << std::endl;

    std::cout << "Original x: " << data.x << ", Deserialized x: " << newData->x << std::endl;
    std::cout << "Original y: " << data.y << ", Deserialized y: " << newData->y << std::endl;

    return 0;
}