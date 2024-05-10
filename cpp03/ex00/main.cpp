#include "ClapTrap.hpp"

int main(void){
	ClapTrap a("Sporting");
	ClapTrap b("Benfica");

	// for(int i = 0; i < 10; i++)
	// 	a.attack("Benfica");
	// std::cout << "-------------------------" << std::endl;
	// a.attack("Benfica");

	a.setAttackDamage(8);
	a.attack("Benfica");
	b.takeDamage(a.getDamage());
	b.beRepaired(8);
	//////////////////////
	std::cout << "-----------------------------------------------------------------" << std::endl;
	a.setAttackDamage(11);
	a.attack("Benfica");
	b.takeDamage(a.getDamage());
	b.takeDamage(a.getDamage());
}
