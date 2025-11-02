#include "Serializer.hpp"
#include <iostream>


int main ()
{
    Data data;
    data.a = 42;
    data.b = 'A';
    data.c = reinterpret_cast<void*>(0xDEADBEEF);

    std::cout << "Original Data address: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized Data (uintptr_t): " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data address: " << deserializedData << std::endl;

    std::cout << "Deserialized Data values:" << std::endl;
    std::cout << "a: " << deserializedData->a << std::endl;
    std::cout << "b: " << deserializedData->b << std::endl;
    std::cout << "c: " << deserializedData->c << std::endl;

}