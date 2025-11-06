#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

#define RED "\033[41m"
#define GREEN "\033[42m"
#define YELLOW "\033[43m"
#define WHITE "\033[47m"
#define RESET "\033[0m"

template <typename T>
class Array 
{
private:
    T* elements;
    size_t arraySize;
public:
    Array() : elements(NULL), arraySize(0) {}
    Array(unsigned int n) : elements(new T[n]()), arraySize(n) {}
    Array(const Array& other) : elements(new T[other.arraySize]), arraySize(other.arraySize) {
        for (size_t i = 0; i < arraySize; ++i) {
            elements[i] = other.elements[i];
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] elements;
            arraySize = other.arraySize;
            elements = new T[arraySize];
            for (size_t i = 0; i < arraySize; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    ~Array() {
        delete[] elements;
    }

    T& operator[](size_t index) {
        if (index >= arraySize) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    const T& operator[](size_t index) const {
        if (index >= arraySize) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    size_t size() const {
        return arraySize;
    }
};