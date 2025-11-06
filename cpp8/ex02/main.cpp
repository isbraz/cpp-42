#include <MutantStack.hpp>
#include <list>

#define RED "\033[41m"
#define GREEN "\033[42m"
#define YELLOW "\033[43m"
#define WHITE "\033[47m"
#define RESET "\033[0m"

int main()
{
    std::cout << WHITE << "=== MutantStack Test ===" << RESET << std::endl;
    std::cout << "Testing MutantStack with the provided main..." << std::endl;
    
    try {
        MutantStack<int> mstack;
        
        mstack.push(5);
        mstack.push(17);
        
        std::cout << "Top element: " << mstack.top() << std::endl;
        
        mstack.pop();
        
        std::cout << "Size after pop: " << mstack.size() << std::endl;
        
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        
        std::cout << "\nIterating through MutantStack:" << std::endl;
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        
        ++it;
        --it;
        
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        
        std::stack<int> s(mstack);
        std::cout << "Successfully created std::stack from MutantStack" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }
    
    std::cout << GREEN << "\n=== Comparing with std::list ===" << RESET << std::endl;
    
    try {
        std::list<int> lst;
        
        lst.push_back(5);
        lst.push_back(17);
        
        std::cout << "Back element: " << lst.back() << std::endl;
        
        lst.pop_back();
        
        std::cout << "Size after pop: " << lst.size() << std::endl;
        
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);
        
        std::cout << "\nIterating through std::list:" << std::endl;
        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator ite = lst.end();
        
        ++it;
        --it;
        
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    catch (const std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }
    
    return 0;
}

