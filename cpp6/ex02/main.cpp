#include "BaseChecker.hpp"
#include <cstdlib>
#include <ctime>

int main() {

    srand(static_cast<unsigned int>(time(NULL)));


    std::cout << RED
    << "Test 1: Random Generation" << RESET << std::endl;
    Base* b = BaseChecker::generate();
    
    BaseChecker::identify(b);         
    
    delete b;
    
    std::cout << std::endl;


    std::cout << GREEN << "Test 2: Identify Example" << RESET << std::endl;
    
    A a;
    B b2;
    C c;
    
    BaseChecker::identify(a);
    BaseChecker::identify(b2);
    BaseChecker::identify(c);
    
    std::cout << std::endl;

}