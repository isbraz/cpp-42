#include <iter.hpp>

//this is cpp 98 no lambda

int main() {
    int    intArray[]    = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::string strArray[] = {"one", "two", "three", "four", "five"};

    // Test 1: Integer array
    std::cout << RED << "----- Testing with Integer Array -----" << RESET << std::endl;
    std::cout << "Integer array:" << std::endl;
    ::iter(intArray, 5, printElement<int>);

    // Test 2: Double array
    std::cout << GREEN << "\n----- Testing with Double Array -----" << RESET << std::endl;
    std::cout << "\nDouble array:" << std::endl;
    ::iter(doubleArray, 5, printElement<double>);

    // Test 3: String array
    std::cout << YELLOW << "\n----- Testing with String Array -----" << RESET << std::endl;
    std::cout << "\nString array:" << std::endl;
    ::iter(strArray, 5, printElement<std::string>);

    return 0;
}