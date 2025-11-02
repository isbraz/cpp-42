#include "BaseChecker.hpp"

BaseChecker::BaseChecker() {
}

BaseChecker::~BaseChecker() {
}

BaseChecker::BaseChecker( const BaseChecker& toCopy ) {
    (void)toCopy;
}

BaseChecker& BaseChecker::operator=( const BaseChecker& toCopy ) {
    (void)toCopy;
    return *this;
}

Base* BaseChecker::generate() {
    int randNum = rand() % 3;
    if (randNum == 0) {
        return new A();
    } else if (randNum == 1) {
        return new B();
    } else {
        return new C();
    }
}

void BaseChecker::identify( Base* p ) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown Type" << std::endl;
    }
}

void BaseChecker::identify( Base& p ) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    std::cout << "Unknown Type" << std::endl;
}