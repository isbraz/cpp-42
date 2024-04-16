#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *group = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		group[i].set_name(name);
		group[i].announce();
	}
	return (group);
}
