#pragma once

#include <iostream>
#include <string>

#define RED "\033[41m"
#define GREEN "\033[42m"
#define RESET "\033[0m"

class ClapTrap{
	protected:
			std::string name;
			int hitPoints;
			int energyPoints;
			int attackDamage;
	public:
			ClapTrap();
			ClapTrap(const ClapTrap& copyConstructor);
			ClapTrap& operator=(const ClapTrap& copyAssignment);
			ClapTrap(std::string name);
			void attack(const std::string& target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);
			void setAttackDamage(int damage);
			int getDamage();
			~ClapTrap();
};
