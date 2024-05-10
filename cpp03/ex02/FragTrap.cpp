#include "FragTrap.hpp"


FragTrap::FragTrap(){
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copyConstructor){
	this->name = copyConstructor.name;
	this->hitPoints = copyConstructor.hitPoints;
	this->energyPoints = copyConstructor.energyPoints;
	this->attackDamage = copyConstructor.attackDamage;
}

FragTrap&  FragTrap::operator=(const FragTrap& copyAssignment){
	this->name = copyAssignment.name;
	this->hitPoints = copyAssignment.hitPoints;
	this->energyPoints = copyAssignment.energyPoints;
	this->attackDamage = copyAssignment.attackDamage;
	return (*this);
}

FragTrap::FragTrap(std::string name){
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	this->name = name;
	std::cout << "FragTrap constructor called" << std::endl;
}

void FragTrap::highFivesGuys(void){
	std::cout << RED << "FragTrap " << this->name << " requested a high five" << RESET << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called" << std::endl;
}

