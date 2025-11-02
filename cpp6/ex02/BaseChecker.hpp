#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"


class Base;
class A;
class B;
class C;


class BaseChecker
{
    private: 
        BaseChecker();
        BaseChecker(const BaseChecker& other);
        BaseChecker& operator=(const BaseChecker& other);
        ~BaseChecker();
    public :
        static Base* generate();
        static void identify( Base* p );
        static void identify( Base& p );

};