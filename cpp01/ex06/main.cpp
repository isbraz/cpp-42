#include "Harl.hpp"

int main(int ac, char **av)
{
	////////////////////PROTECTION/////////////////////////////////////
	if (ac != 2){
		std::cout << "Wrong number of arguments!" << std::endl;
		return (0);
	}
	//////////////////////////////////////////////////////////////////

	Harl test;

	test.complain(av[1]);
	
}