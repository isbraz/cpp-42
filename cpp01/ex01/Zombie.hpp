#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>

#define RED "\033[41m"

class Zombie{
	private:
		std::string name;
	public:
		Zombie();
		void setName(std::string name);
		void announce(void);
		~Zombie();
};

	Zombie* zombieHorde( int N, std::string name );


#endif