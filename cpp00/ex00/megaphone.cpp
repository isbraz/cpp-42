#include <iostream>
#include <ctype.h>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; av[i]; i++)
	{
		for (int j = 0; av[i][j]; j++)
		{
			if (islower(av[i][j]))
				std::cout << (char)toupper(av[i][j]);
			else
				std::cout << av[i][j];
		}
		if (i < ac - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}
