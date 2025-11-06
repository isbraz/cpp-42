#include <easyfind.hpp>

int main ()
{
    std::cout << WHITE << "=== Easyfind Test ===" << RESET << std::endl;

    try {
        std::vector<int> vec;
        for (int i = 0; i < 10; ++i) {
            vec.push_back(i * 10);
        }

        std::cout << "Vector contents: ";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        int valueToFind = 50;
        std::cout << "Searching for value: " << valueToFind << std::endl;
        std::vector<int>::iterator it = easyfind(vec, valueToFind);
        std::cout << GREEN << "Value " << *it << " found in vector!" << RESET << std::endl;

        valueToFind = 100;
        std::cout << "Searching for value: " << valueToFind << std::endl;
        it = easyfind(vec, valueToFind); 
        std::cout << "This line should not be reached!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    return 0;
}