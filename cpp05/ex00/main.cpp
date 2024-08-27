#include "Bureaucrat.hpp"

int main(){
	try
	{
		std::cout << WHITE << "...TESTING..." << RESET << std::endl;
		std::cout << "✅✅✅✅✅✅✅✅✅✅✅✅✅" << std::endl;
		Bureaucrat a("Ismael", 10);
		std::cout << a << std::endl;
		std::cout << GREEN << "...Incrementing..." << RESET << std::endl;
		a.increment();
		std::cout << a << std::endl;
		std::cout << RED << "...Decrementing..." << RESET << std::endl;
		a.decrement();
		std::cout << a << std::endl;
		std::cout << "✅✅✅✅✅✅✅✅✅✅✅✅✅" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << "❌❌❌❌❌❌❌❌❌❌❌❌❌" << std::endl;
	}
	try
	{
		std::cout << WHITE << "...TESTING..." << RESET << std::endl;
		std::cout << "❌❌❌❌❌❌❌❌❌❌❌❌❌" << std::endl;
		Bureaucrat b("Silva", 1);
		std::cout << b << std::endl;
		std::cout << GREEN << "...Incrementing..." << RESET << std::endl;
		b.increment();
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "❌❌❌❌❌❌❌❌❌❌❌❌❌" << std::endl;
	}
}