#include <Span.hpp>

int main () 
{
    std::cout << WHITE << "=== Span Test ===" << RESET << std::endl;
    std::cout << "Testing Span with provided main... (Add one number at a time)" << std::endl;
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // This should throw an exception
        sp.addNumber(42);
    }
    catch (const std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << GREEN << "Testing Span with range addition... (Add multiple numbers at once)" <<  RESET << std::endl;
    try {
        Span sp2(10);
        std::vector<int> nums;
        nums.push_back(1);
        nums.push_back(2);
        nums.push_back(3);
        nums.push_back(4);
        nums.push_back(5);
        sp2.addNumbers(nums.begin(), nums.end());
        std::cout << "Shortest span in sp2: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span in sp2: " << sp2.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    return 0;
}