#include "ScavTrap.hpp"

int main(void){
	ClapTrap a("Thor");
	ScavTrap b("Loki");

	// for(int i = 0; i < 50; i++)
	// 	b.attack("Loki");
	// std::cout << "-------------------------" << std::endl;

	a.setAttackDamage(8);
	a.attack("Loki");
	// b.takeDamage(8);
	
	//////////////////////
	std::cout << "-----------------------------------------------------------------" << std::endl;
	b.attack("target");
}
