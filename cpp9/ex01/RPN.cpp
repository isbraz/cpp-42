#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
    _stack = other._stack;
}

RPN::~RPN()
{
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        _stack = other._stack;
    }
    return *this;
}

bool RPN::isOperator(const std::string& token) const
{
    return token.length() == 1 && 
           (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}

bool RPN::isNumber(const std::string& token) const
{
    if (token.empty())
        return false;
    
    size_t start = 0;
    if (token[0] == '-' || token[0] == '+')
        start = 1;
    
    if (start >= token.length())
        return false;
    
    for (size_t i = start; i < token.length(); i++)
    {
        if (token[i] < '0' || token[i] > '9')
            return false;
    }
    return true;
}

int RPN::performOperation(int a, int b, char op)
{
    switch (op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: division by zero");
            return a / b;
        default:
            throw std::runtime_error("Error: invalid operator");
    }
}

int RPN::calculate(const std::string& expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isNumber(token))
        {
            std::istringstream converter(token);
            int num;
            converter >> num;
            _stack.push(num);
        }
        else if (isOperator(token))
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error: insufficient operands");
            
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();
            
            int result = performOperation(a, b, token[0]);
            _stack.push(result);
        }
        else
        {
            throw std::runtime_error("Error: invalid token");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid expression");
    
    return _stack.top();
}
