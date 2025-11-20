#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <sys/time.h>
#include <exception>
#include <iomanip>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int> _deq;
    
    double _vecTime;
    double _deqTime;

    void parseInput(int argc, char **argv);
    void validateNumber(const std::string& str);
    
    void sortVector();
    void sortDeque();
    
    std::vector<int> mergeInsertSortVec(std::vector<int>& arr);
    std::deque<int> mergeInsertSortDeq(std::deque<int>& arr);
    
    std::vector<int> generateJacobsthalVec(size_t n);
    std::deque<int> generateJacobsthalDeq(size_t n);
    
    template<typename T>
    size_t binarySearch(const T& sorted, int value, size_t end);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void run(int argc, char **argv);
    void displayResults() const;
    
    class InvalidInputException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

#endif
