#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vecTime(0), _deqTime(0) {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
        _vecTime = other._vecTime;
        _deqTime = other._deqTime;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

const char* PmergeMe::InvalidInputException::what() const throw() {
    return "Error";
}

void PmergeMe::validateNumber(const std::string& str) {
    if (str.empty())
        throw InvalidInputException();
    
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i]))
            throw InvalidInputException();
    }
    
    std::stringstream ss(str);
    long num;
    ss >> num;
    
    if (num < 0 || num > 2147483647)
        throw InvalidInputException();
}

void PmergeMe::parseInput(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        std::string arg(argv[i]);
        validateNumber(arg);
        
        int num = atoi(arg.c_str());
        _vec.push_back(num);
        _deq.push_back(num);
    }
    
    if (_vec.empty())
        throw InvalidInputException();
}

std::vector<int> PmergeMe::generateJacobsthalVec(size_t n) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    while (true) {
        size_t size = jacobsthal.size();
        int next = jacobsthal[size - 1] + 2 * jacobsthal[size - 2];
        if (static_cast<size_t>(next) >= n)
            break;
        jacobsthal.push_back(next);
    }
    
    return jacobsthal;
}

std::deque<int> PmergeMe::generateJacobsthalDeq(size_t n) {
    std::deque<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    while (true) {
        size_t size = jacobsthal.size();
        int next = jacobsthal[size - 1] + 2 * jacobsthal[size - 2];
        if (static_cast<size_t>(next) >= n)
            break;
        jacobsthal.push_back(next);
    }
    
    return jacobsthal;
}

template<typename T>
size_t PmergeMe::binarySearch(const T& sorted, int value, size_t end) {
    size_t left = 0;
    size_t right = end;
    
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (sorted[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    
    return left;
}

std::vector<int> PmergeMe::mergeInsertSortVec(std::vector<int>& arr) {
    if (arr.size() <= 1)
        return arr;
    
    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = hasStraggler ? arr.back() : 0;
    
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        int a = arr[i];
        int b = arr[i + 1];
        if (a > b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    
    for (size_t i = 1; i < pairs.size(); i++) {
        std::pair<int, int> key = pairs[i];
        int j = i - 1;
        
        while (j >= 0 && pairs[j].first > key.first) {
            pairs[j + 1] = pairs[j];
            j--;
        }
        pairs[j + 1] = key;
    }
    
    std::vector<int> mainChain;
    std::vector<int> pending;
    
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
        pending.push_back(pairs[i].second);
    }
    
    if (!pending.empty())
        mainChain.insert(mainChain.begin(), pending[0]);
    
    std::vector<int> jacobsthal = generateJacobsthalVec(pending.size());
    std::vector<bool> inserted(pending.size(), false);
    inserted[0] = true;
    
    for (size_t i = 2; i < jacobsthal.size(); i++) {
        int currentIndex = jacobsthal[i];
        int previousIndex = jacobsthal[i - 1];
        
        for (int j = currentIndex; j > previousIndex && j > 0; j--) {
            if (static_cast<size_t>(j) < pending.size() && !inserted[j]) {
                int value = pending[j];
                size_t pos = binarySearch(mainChain, value, mainChain.size());
                mainChain.insert(mainChain.begin() + pos, value);
                inserted[j] = true;
            }
        }
    }
    
    for (size_t i = 1; i < pending.size(); i++) {
        if (!inserted[i]) {
            int value = pending[i];
            size_t pos = binarySearch(mainChain, value, mainChain.size());
            mainChain.insert(mainChain.begin() + pos, value);
        }
    }
    
    if (hasStraggler) {
        size_t pos = binarySearch(mainChain, straggler, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, straggler);
    }
    
    return mainChain;
}

std::deque<int> PmergeMe::mergeInsertSortDeq(std::deque<int>& arr) {
    if (arr.size() <= 1)
        return arr;
    
    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = hasStraggler ? arr.back() : 0;
    
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        int a = arr[i];
        int b = arr[i + 1];
        if (a > b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    
    for (size_t i = 1; i < pairs.size(); i++) {
        std::pair<int, int> key = pairs[i];
        int j = i - 1;
        
        while (j >= 0 && pairs[j].first > key.first) {
            pairs[j + 1] = pairs[j];
            j--;
        }
        pairs[j + 1] = key;
    }
    
    std::deque<int> mainChain;
    std::deque<int> pending;
    
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
        pending.push_back(pairs[i].second);
    }
    
    if (!pending.empty())
        mainChain.insert(mainChain.begin(), pending[0]);
    
    std::deque<int> jacobsthal = generateJacobsthalDeq(pending.size());
    std::vector<bool> inserted(pending.size(), false);
    inserted[0] = true;
    
    for (size_t i = 2; i < jacobsthal.size(); i++) {
        int currentIndex = jacobsthal[i];
        int previousIndex = jacobsthal[i - 1];
        
        for (int j = currentIndex; j > previousIndex && j > 0; j--) {
            if (static_cast<size_t>(j) < pending.size() && !inserted[j]) {
                int value = pending[j];
                size_t pos = binarySearch(mainChain, value, mainChain.size());
                mainChain.insert(mainChain.begin() + pos, value);
                inserted[j] = true;
            }
        }
    }
    
    for (size_t i = 1; i < pending.size(); i++) {
        if (!inserted[i]) {
            int value = pending[i];
            size_t pos = binarySearch(mainChain, value, mainChain.size());
            mainChain.insert(mainChain.begin() + pos, value);
        }
    }
    
    if (hasStraggler) {
        size_t pos = binarySearch(mainChain, straggler, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, straggler);
    }
    
    return mainChain;
}

void PmergeMe::sortVector() {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    _vec = mergeInsertSortVec(_vec);
    
    gettimeofday(&end, NULL);
    _vecTime = (end.tv_sec - start.tv_sec) * 1000000.0;
    _vecTime += (end.tv_usec - start.tv_usec);
}

void PmergeMe::sortDeque() {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    _deq = mergeInsertSortDeq(_deq);
    
    gettimeofday(&end, NULL);
    _deqTime = (end.tv_sec - start.tv_sec) * 1000000.0;
    _deqTime += (end.tv_usec - start.tv_usec);
}

void PmergeMe::run(int argc, char **argv) {
    parseInput(argc, argv);
    
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size() && i < 5; i++)
        std::cout << _vec[i] << " ";
    if (_vec.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;
    
    sortVector();
    sortDeque();
}

void PmergeMe::displayResults() const {
    std::cout << "After:  ";
    for (size_t i = 0; i < _vec.size() && i < 5; i++)
        std::cout << _vec[i] << " ";
    if (_vec.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " 
              << std::fixed << std::setprecision(5) << _vecTime << " us" << std::endl;
    
    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque : " 
              << std::fixed << std::setprecision(5) << _deqTime << " us" << std::endl;
}
