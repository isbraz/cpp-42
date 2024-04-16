#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &armA):_armA(armA)
{
	this->_name = name;
}

void HumanA::attack()
{
	std::cout << this->_name << " attack with their " << this->_armA.getType() << std::endl; 
}