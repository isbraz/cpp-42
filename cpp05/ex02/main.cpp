#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
    // Test 1: ShrubberyCreationForm - Successful signing and execution
    try
    {
        std::cout << WHITE << "=== TEST 1: ShrubberyCreationForm - Success ===" << RESET << std::endl;
        Bureaucrat lowBureaucrat("TreePlanter", 130);
        ShrubberyCreationForm shrub("Garden");
        
        std::cout << lowBureaucrat;
        std::cout << shrub;
        std::cout << WHITE << "Attempting to sign..." << RESET << std::endl;
        lowBureaucrat.signForm(shrub);
        std::cout << shrub;
        std::cout << WHITE << "Attempting to execute..." << RESET << std::endl;
        lowBureaucrat.executeForm(shrub);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl << std::endl;
    }

    // Test 2: ShrubberyCreationForm - Failed signing (grade too low)
    try
    {
        std::cout << RED << "=== TEST 2: ShrubberyCreationForm - Failed Signing ===" << RESET << std::endl;
        Bureaucrat veryLowBureaucrat("Intern", 150);
        ShrubberyCreationForm shrub("FailedGarden");
        
        std::cout << veryLowBureaucrat;
        std::cout << shrub;
        std::cout << RED << "Attempting to sign..." << RESET << std::endl;
        veryLowBureaucrat.signForm(shrub);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl << std::endl;
    }

    // Test 3: RobotomyRequestForm - Successful signing and execution
    try
    {
        std::cout << GREEN << "=== TEST 3: RobotomyRequestForm - Success ===" << RESET << std::endl;
        Bureaucrat midBureaucrat("Roboticist", 40);
        RobotomyRequestForm robot("Bender");
        
        std::cout << midBureaucrat;
        std::cout << robot;
        std::cout << GREEN << "Attempting to sign..." << RESET << std::endl;
        midBureaucrat.signForm(robot);
        std::cout << (robot);
        std::cout << GREEN << "Attempting to execute..." << RESET << std::endl;
        midBureaucrat.executeForm(robot);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl << std::endl;
    }

    // Test 4: RobotomyRequestForm - Failed execution (grade too low for execution)
    try
    {
        std::cout << YELLOW << "=== TEST 4: RobotomyRequestForm - Failed Execution ===" << RESET << std::endl;
        Bureaucrat signerBureaucrat("Signer", 50);  // Can sign (50 < 72) but can't execute (50 > 45)
        RobotomyRequestForm robot("Wall-E");
        
        std::cout << signerBureaucrat;
        std::cout << robot;
        std::cout << YELLOW << "Attempting to sign..." << RESET << std::endl;
        signerBureaucrat.signForm(robot);
        std::cout << (robot);
        std::cout << YELLOW << "Attempting to execute..." << RESET << std::endl;
        signerBureaucrat.executeForm(robot);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl << std::endl;
    }

    // Test 5: PresidentialPardonForm - Successful signing and execution
    try
    {
        std::cout << WHITE << "=== TEST 5: PresidentialPardonForm - Success ===" << RESET << std::endl;
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Criminal");
        
        std::cout << president;
        std::cout << (pardon);
        std::cout << WHITE << "Attempting to sign..." << RESET << std::endl;
        president.signForm(pardon);
        std::cout << (pardon);
        std::cout << WHITE << "Attempting to execute..." << RESET << std::endl;
        president.executeForm(pardon);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl << std::endl;
    }

    // Test 6: PresidentialPardonForm - Failed signing (grade too low)
    try
    {
        std::cout << RED << "=== TEST 6: PresidentialPardonForm - Failed Signing ===" << RESET << std::endl;
        Bureaucrat lowGrade("Secretary", 30);
        PresidentialPardonForm pardon("Innocent");
        
        std::cout << lowGrade;
        std::cout << pardon;
        std::cout << RED << "Attempting to sign..." << RESET << std::endl;
        lowGrade.signForm(pardon);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl << std::endl;
    }

    // Test 7: PresidentialPardonForm - Failed execution (grade too low for execution)
    try
    {
        std::cout << YELLOW << "=== TEST 7: PresidentialPardonForm - Failed Execution ===" << RESET << std::endl;
        Bureaucrat highGrade("VicePresident", 10);  // Can sign (10 < 25) but can't execute (10 > 5)
        PresidentialPardonForm pardon("Suspect");
        
        std::cout << highGrade;
        std::cout << pardon;
        std::cout << YELLOW << "Attempting to sign..." << RESET << std::endl;
        highGrade.signForm(pardon);
        std::cout << (pardon);
        std::cout << YELLOW << "Attempting to execute..." << RESET << std::endl;
        highGrade.executeForm(pardon);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl << std::endl;
    }

    // Test 8: Attempting to execute unsigned form
    try
    {
        std::cout << GREEN << "=== TEST 8: Execute Unsigned Form ===" << RESET << std::endl;
        Bureaucrat topBureaucrat("Boss", 1);
        ShrubberyCreationForm unsignedForm("UnsignedTree");
        
        std::cout << topBureaucrat;
        std::cout << unsignedForm;
        std::cout << GREEN << "Attempting to execute without signing..." << RESET << std::endl;
        topBureaucrat.executeForm(unsignedForm);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl << std::endl;
    }
}