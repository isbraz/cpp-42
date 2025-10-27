#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    // Test 1: Intern creates ShrubberyCreationForm - Success
    try
    {
        std::cout << WHITE << "=== TEST 1: Interndd creates ShrubberyCreationForm ===" << RESET << std::endl;
        Intern someRandomIntern;
        AForm* form;
        
        form = someRandomIntern.makeForm("shrubbery creation", "home");
        if (form)
        {
            Bureaucrat bob("Bob", 130);
            std::cout << *form;
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl << std::endl;
    }

    // Test 2: Intern creates RobotomyRequestForm - Success
    try
    {
        std::cout << GREEN << "=== TEST 2: Intern creates RobotomyRequestForm ===" << RESET << std::endl;
        Intern someRandomIntern;
        AForm* form;
        
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        if (form)
        {
            Bureaucrat alice("Alice", 40);
            std::cout << *form;
            alice.signForm(*form);
            alice.executeForm(*form);
            delete form;
        }
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl << std::endl;
    }

    // Test 3: Intern creates PresidentialPardonForm - Success
    try
    {
        std::cout << YELLOW << "=== TEST 3: Intern creates PresidentialPardonForm ===" << RESET << std::endl;
        Intern someRandomIntern;
        AForm* form;
        
        form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        if (form)
        {
            Bureaucrat president("President", 1);
            std::cout << *form;
            president.signForm(*form);
            president.executeForm(*form);
            delete form;
        }
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl << std::endl;
    }

    // Test 4: Intern tries to create invalid form
    try
    {
        std::cout << RED << "=== TEST 4: Intern creates invalid form ===" << RESET << std::endl;
        Intern someRandomIntern;
        AForm* form;
        
        form = someRandomIntern.makeForm("tax evasion", "Criminal");
        if (form)
        {
            std::cout << *form;
            delete form;
        }
        else
        {
            std::cout << RED << "Form creation failed - NULL pointer returned" << RESET << std::endl;
        }
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl << std::endl;
    }

    // Test 5: Multiple forms created by same intern
    try
    {
        std::cout << WHITE << "=== TEST 5: Same Intern creates multiple forms ===" << RESET << std::endl;
        Intern internFactory;
        Bureaucrat boss("Boss", 1);
        
        AForm* form1 = internFactory.makeForm("shrubbery creation", "office");
        AForm* form2 = internFactory.makeForm("robotomy request", "employee");
        AForm* form3 = internFactory.makeForm("presidential pardon", "politician");
        
        if (form1)
        {
            boss.signForm(*form1);
            boss.executeForm(*form1);
            delete form1;
        }
        if (form2)
        {
            boss.signForm(*form2);
            boss.executeForm(*form2);
            delete form2;
        }
        if (form3)
        {
            boss.signForm(*form3);
            boss.executeForm(*form3);
            delete form3;
        }
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl << std::endl;
    }


    // Test 6: Form created but bureaucrat can't execute
    try
    {
        std::cout << GREEN << "=== TEST 7: Form created but bureaucrat can't execute ===" << RESET << std::endl;
        Intern someRandomIntern;
        AForm* form;
        
        form = someRandomIntern.makeForm("presidential pardon", "someone");
        if (form)
        {
            Bureaucrat lowGrade("LowGrade", 50);
            std::cout << *form;
            std::cout << GREEN << "Attempting to sign..." << RESET << std::endl;
            lowGrade.signForm(*form);
            delete form;
        }
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl << std::endl;
    }

}