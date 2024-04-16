#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
}

void HumanB::setWeapon(Weapon &type)
{
	this->armB = &type;
}

void HumanB::attack()
{
	std::cout << this->_name << " attack with their " << this->armB->getType() << std::endl; 
}

