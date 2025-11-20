#pragma once

#include <string>
#include <stack>
#include <iostream>
#include <sstream>

class RPN
{
private:
    std::stack<int> _stack;

    bool isOperator(const std::string& token) const;
    bool isNumber(const std::string& token) const;
    int performOperation(int a, int b, char op);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    int calculate(const std::string& expression);
};
