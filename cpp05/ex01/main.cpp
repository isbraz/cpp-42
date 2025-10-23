#include "Bureaucrat.hpp"
#include "Form.hpp"


int main(){
	
	
	// Test 1: Creating a Bureaucrat and a Form, then signing the form
	try
	{
		Bureaucrat b("Ismael", 4);
		Form f("Formulary", 10, 4);

		std::cout << WHITE << "________________BEFORE________________" <<  RESET << std::endl;
		std::cout << f;
		std::cout << WHITE << "_______________SIGNING________________" << RESET << std::endl;
		b.signForm(f);
		std::cout << WHITE << "________________AFTER_________________" <<  RESET << std::endl;
		std::cout << f;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// Test 2: Creating a Bureaucrat that cannot sign the form due to low grade
	try 
	{
		Bureaucrat b("LowGradeBureaucrat", 150);
		Form f("Formulary", 10, 4);

		std::cout << RED << "________________BEFORE________________" <<  RESET << std::endl;
		std::cout << f;
		std::cout << RED << "_______________SIGNING________________" << RESET << std::endl;
		b.signForm(f);
		std::cout << RED << "________________AFTER_________________" <<  RESET << std::endl;
		std::cout << f;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// Test 3: Creating a Form that cannot be signed due to high grade requirement
	try
	{
		Bureaucrat b("HighGradeBureaucrat", 1);
		Form f("Formulary", 10, 1);

		std::cout << GREEN << "________________BEFORE________________" <<  RESET << std::endl;
		std::cout << f;
		std::cout << GREEN << "_______________SIGNING________________" << RESET << std::endl;
		b.signForm(f);
		std::cout << GREEN << "________________AFTER_________________" <<  RESET << std::endl;
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// Test 4: Creating a Form with invalid grade requirements
	try 
	{
		std::cout << YELLOW << "Creating invalid form" <<  RESET <<std::endl;
		Form f("InvalidForm", 151, 4);
		std::cout << f;
	}
	catch(const std::exception& e)
	{
		std::cerr << RESET << e.what() << std::endl;
	}
}