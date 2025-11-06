#include <Array.hpp>

int main() 
{
    // Test 1: Basic array manipulation
    try
    {
        std::cout << WHITE << "=== Test 1: Basic Array Manipulation ===" << RESET << std::endl;
        std::cout << "✅✅✅✅✅✅✅✅✅✅✅✅✅" << std::endl;
        Array<int> intArray(5);
        std::cout << "Integer array size: " << intArray.size() << std::endl;
        std::cout << "Filling array with values..." << std::endl;
        for (size_t i = 0; i < intArray.size(); i++) {
            intArray[i] = i * 10;
        }
        std::cout << "Array contents: ";
        for (size_t i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "✅✅✅✅✅✅✅✅✅✅✅✅✅\n" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
        std::cout << "❌❌❌❌❌❌❌❌❌❌❌❌❌\n" << std::endl;
    }

    // Test 2: Out of bounds access (should throw exception)
    try
    {
        std::cout << WHITE << "=== Test 2: Out of Bounds Access ===" << RESET << std::endl;
        std::cout << "❌❌❌❌❌❌❌❌❌❌❌❌❌" << std::endl;
        Array<int> arr(5);
        std::cout << RED << "Attempting to access index 10 in array of size 5..." << RESET << std::endl;
        arr[10] = 42; // This should throw
        std::cout << "This line should not be reached!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
        std::cout << "❌❌❌❌❌❌❌❌❌❌❌❌❌\n" << std::endl;
    }

    // Test 3: Different types
    try
    {
        std::cout << WHITE << "=== Test 3: Testing with Different Types ===" << RESET << std::endl;
        std::cout << "✅✅✅✅✅✅✅✅✅✅✅✅✅" << std::endl;
        
        Array<double> doubleArray(3);
        doubleArray[0] = 3.14;
        doubleArray[1] = 2.71;
        doubleArray[2] = 1.41;
        std::cout << "Double array: ";
        for (size_t i = 0; i < doubleArray.size(); i++) {
            std::cout << std::fixed << std::setprecision(2) << doubleArray[i] << " ";
        }
        std::cout << std::endl;

        Array<std::string> strArray(3);
        strArray[0] = "Hello";
        strArray[1] = "World";
        strArray[2] = "!";
        std::cout << "String array: ";
        for (size_t i = 0; i < strArray.size(); i++) {
            std::cout << strArray[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "✅✅✅✅✅✅✅✅✅✅✅✅✅\n" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
        std::cout << "❌❌❌❌❌❌❌❌❌❌❌❌❌\n" << std::endl;
    }

    std::cout << GREEN << "=== All tests completed! ===" << RESET << std::endl;
    
    return 0;
}