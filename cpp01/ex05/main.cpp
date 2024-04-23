#include "Harl.hpp"

int main(void)
{
	Harl test;

	std::cout << GREEN;
	test.complain("DEBUG");
	std::cout << RESET;
	test.complain("debug");

	std::cout << std::endl;

	std::cout << GREEN;
	test.complain("INFO");
	std::cout << RESET;
	test.complain("info");

	std::cout << std::endl;
	
	std::cout << GREEN;
	test.complain("WARNING");
	std::cout << RESET;
	test.complain("warning");

	std::cout << std::endl;

	std::cout << GREEN;
	test.complain("ERROR");
	std::cout << RESET;
	test.complain("error");
}
