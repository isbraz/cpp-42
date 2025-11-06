#pragma once 

#include <iostream>
#include <iomanip>
#include <string>

#define RED "\033[41m"
#define GREEN "\033[42m"
#define YELLOW "\033[43m"
#define WHITE "\033[47m"
#define RESET "\033[0m"

template <typename T>
void printElement(const T& element) {
    std::cout << "Element: " << element << std::endl;
}

template <typename T, typename Func>
void iter(T* array, size_t length, Func func) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}