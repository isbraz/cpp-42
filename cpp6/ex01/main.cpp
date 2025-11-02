#include "Serializer.hpp"
#include <iostream>

int main()
{
    std::cout << GREEN << "Test 1 === Serializer Test ===" << RESET <<  std::endl;

    // Step 1: Create and initialize a Data structure
    std::cout << "1. Creating Data structure:" << std::endl;
    Data data;
    data.a = 42;
    data.b = 'A';
    data.c = reinterpret_cast<void*>(0xDEADBEEF);
    
    std::cout << "   Original Data address: " << &data << std::endl;
    std::cout << "   Values: a=" << data.a << ", b=" << data.b 
              << ", c=" << data.c << std::endl << std::endl;

    // Step 2: Serialize the pointer (convert pointer to uintptr_t)
    std::cout << "2. Serializing pointer to uintptr_t:" << std::endl;
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "   Serialized value: " << raw << std::endl;
    std::cout << "   (This is the memory address as an unsigned integer)" 
              << std::endl << std::endl;

    // Step 3: Deserialize back to pointer (convert uintptr_t back to pointer)
    std::cout << "3. Deserializing uintptr_t back to pointer:" << std::endl;
    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "   Deserialized address: " << deserializedData << std::endl << std::endl;

    // Step 4: Verify the addresses match
    std::cout << "4. Verification:" << std::endl;
    if (deserializedData == &data)
        std::cout << "   ✓ Addresses match! Serialization successful." << std::endl;
    else
        std::cout << "   ✗ Addresses don't match! Something went wrong." << std::endl;

    // Step 5: Verify the data is intact
    std::cout << "   Deserialized values: a=" << deserializedData->a 
              << ", b=" << deserializedData->b 
              << ", c=" << deserializedData->c << std::endl;
    
    if (deserializedData->a == data.a && 
        deserializedData->b == data.b && 
        deserializedData->c == data.c)
        std::cout << "   ✓ Data values match! Data integrity preserved." << std::endl;
    else
        std::cout << "   ✗ Data values don't match!" << std::endl;

    std::cout << std::endl;
    std::cout << RED << "Test 2 === Wrong Deserialization (Modified Value) ===" << RESET << std::endl;

    // Step 1: Create another Data structure
    std::cout << "1. Creating another Data structure:" << std::endl;
    Data data2;
    data2.a = 100;
    data2.b = 'Z';
    data2.c = reinterpret_cast<void*>(0xCAFEBABE);
    
    std::cout << "   Data2 address: " << &data2 << std::endl;
    std::cout << "   Values: a=" << data2.a << ", b=" << data2.b 
              << ", c=" << data2.c << std::endl << std::endl;

    // Step 2: Serialize data2
    std::cout << "2. Serializing data2 pointer:" << std::endl;
    uintptr_t raw2 = Serializer::serialize(&data2);
    std::cout << "   Serialized value: " << raw2 << std::endl << std::endl;

    // Step 3: Intentionally modify the serialized value
    std::cout << "3. Corrupting the serialized value (adding 1):" << std::endl;
    uintptr_t corruptedRaw = raw2 + 1;
    std::cout << "   Corrupted value: " << corruptedRaw << std::endl;
    std::cout << "   (This now points to a different memory location)" << std::endl << std::endl;

    // Step 4: Deserialize the corrupted value
    std::cout << "4. Deserializing the corrupted value:" << std::endl;
    Data* corruptedData = Serializer::deserialize(corruptedRaw);
    std::cout << "   Deserialized address: " << corruptedData << std::endl << std::endl;

    // Step 5: Verify - this should fail
    std::cout << "5. Verification:" << std::endl;
    if (corruptedData == &data2)
        std::cout << "   ✓ Addresses match!" << std::endl;
    else
        std::cout << "   ✗ Addresses don't match! (Expected - we corrupted it)" << std::endl;

    // Try to access the data (this is dangerous with corrupted pointer!)
    std::cout << "   Attempting to read corrupted data values..." << std::endl;
    std::cout << "   (WARNING: Reading from invalid memory location!)" << std::endl;
    std::cout << "   Values at corrupted address: a=" << corruptedData->a 
              << ", b=" << corruptedData->b 
              << ", c=" << corruptedData->c << std::endl;
    
    if (corruptedData->a == data2.a && 
        corruptedData->b == data2.b && 
        corruptedData->c == data2.c)
        std::cout << "   ✓ Data values match!" << std::endl;
    else
        std::cout << "   ✗ Data values don't match! (Expected - corrupted pointer)" << std::endl;

    return 0;
}