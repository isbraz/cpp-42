#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copyConstructor){
	this->name = copyConstructor.name;
	this->hitPoints = copyConstructor.hitPoints;
	this->energyPoints = copyConstructor.energyPoints;
	this->attackDamage = copyConstructor.attackDamage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copyAssignment){
	this->name = copyAssignment.name;
	this->hitPoints = copyAssignment.hitPoints;
	this->energyPoints = copyAssignment.energyPoints;
	this->attackDamage = copyAssignment.attackDamage;
	return (*this);
}

ScavTrap::ScavTrap(std::string name){
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->name = name;
	std::cout << "ScavTrap constructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (this->energyPoints > 0){
		std::cout << BLUE << "ScavTrap " << this->name << " attacks "  << target << ", causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << BLUE << "ScavTrap " << this->name << " don't have energy to attack!" << RESET << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called" << std::endl;
}
