#include <iostream>
#include <string>

int main(void)
{
	std::string test = "HI THIS IS BRAIN";
	std::string *stringPTR = &test;
	std::string &stringREF = test;

	////////////////////////MEMORY_ADDRESS///////////////////////////////////
	std::cout << "address of the string test -> " << &test << std::endl;
	std::cout << "address of the stringPTR -> " << stringPTR << std::endl;
	std::cout << "address of the stringREF -> " << &stringREF << std::endl;

	///////////////////////////VALUE////////////////////////////////////////
	std::cout << "value of the string test -> " << test << std::endl;
	std::cout << "value of the stringPTR -> " << *stringPTR << std::endl;
	std::cout << "value of the stringREF -> " << stringREF << std::endl;
}
