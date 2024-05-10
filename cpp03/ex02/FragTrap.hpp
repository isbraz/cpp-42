#pragma once

#include "ClapTrap.hpp"

#define RED "\033[41m"
#define GREEN "\033[42m"
#define RESET "\033[0m"
#define BLUE "\033[44m"

class FragTrap: public ClapTrap{
	public:
			FragTrap();
			FragTrap(const FragTrap& copyConstructor);
			FragTrap& operator=(const FragTrap& copyAssingnment);
			FragTrap(std::string name);
			void highFivesGuys(void);
			~FragTrap();
};