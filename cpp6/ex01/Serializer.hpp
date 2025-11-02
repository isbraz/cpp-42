#pragma once

#include <cstdint>
#include "Data.hpp"


#define RED "\033[41m"
#define GREEN "\033[42m"
#define YELLOW "\033[43m"
#define WHITE "\033[47m"
#define RESET "\033[0m"

class Serializer
{
    private: 
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        ~Serializer();
    public :
        static uintptr_t serialize( Data* ptr );
        static Data* deserialize( uintptr_t raw );

};

