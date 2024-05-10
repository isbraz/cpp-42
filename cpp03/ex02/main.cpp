#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void){
	ClapTrap a("Thor");
	ScavTrap b("Loki");
	FragTrap c("Zeus");

	// for(int i = 0; i < 50; i++)
	// 	b.attack("Loki");
	// std::cout << "-------------------------" << std::endl;

	a.setAttackDamage(8);
	a.attack("Loki");
	// b.takeDamage(8);
	
	b.attack("target");
	c.highFivesGuys();
}
