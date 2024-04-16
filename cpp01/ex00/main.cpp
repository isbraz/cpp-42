#include "Zombie.hpp"

int main(void)
{
	Zombie test("Isma");
	test.announce();

	Zombie *heapMem = newZombie("Braz");
	heapMem->announce();

	randomChump("Silva");
	
	delete heapMem;
}
