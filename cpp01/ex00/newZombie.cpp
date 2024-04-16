#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie *goToHeap = new Zombie(name);

	return (goToHeap);
}