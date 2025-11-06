#pragma once


#include <iostream>
#include <algorithm>
#include <vector>


#define RED "\033[41m"
#define GREEN "\033[42m"
#define YELLOW "\033[43m"
#define WHITE "\033[47m"
#define RESET "\033[0m"

class Span 
{
    private:
        unsigned int maxSize;
        std::vector<int> numbers;
    public:
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        
        void addNumber(int number);
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan() const;
        int longestSpan() const;
};