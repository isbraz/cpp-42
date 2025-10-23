#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern 
{
    public:
        Intern();
        Intern(const Intern& copyConstructor);
        Intern& operator=(const Intern& copyAssignment);
        ~Intern();

        AForm* makeForm(const std::string& formName, const std::string& target);
        
    private:
        AForm* createShrubberyCreationForm(const std::string& target);
        AForm* createRobotomyRequestForm(const std::string& target);
        AForm* createPresidentialPardonForm(const std::string& target);
        class InvalidFormExpection : public std::exception{
            public:
                const char *what() const throw();
        };
};
