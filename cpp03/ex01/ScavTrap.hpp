#pragma once

#include "ClapTrap.hpp"

#define RED "\033[41m"
#define GREEN "\033[42m"
#define RESET "\033[0m"
#define BLUE "\033[44m"

class ScavTrap: public ClapTrap{
	public:
			ScavTrap();
			ScavTrap(std::string name);
			ScavTrap(const ScavTrap& copyConstructor);
			ScavTrap& operator=(const ScavTrap& copyAssignment);
			~ScavTrap();
			void guardGate();
			void attack(const std::string& target);
};