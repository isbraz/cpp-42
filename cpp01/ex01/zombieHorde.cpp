#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 0)
	{
		std::cout << RED << "terminate called after throwing an instance of 'std::bad_alloc' \n what():  std::bad_alloc \n[1]    8839 IOT instruction (core dumped)  ./zombie" << std::endl;
		return (0);
	}
	Zombie *group = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		group[i].setName(name);
		group[i].announce();
	}
	return (group);
}
