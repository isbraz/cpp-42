#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	this->attackDamage = 0;
	this->hitPoints = 10;
	this->energyPoints = 10;
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copyConstructor){
	this->name = copyConstructor.name;
	this->hitPoints = copyConstructor.hitPoints;
	this->energyPoints = copyConstructor.energyPoints;
	this->attackDamage = copyConstructor.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copyAssignment){
	this->name = copyAssignment.name;
	this->hitPoints = copyAssignment.hitPoints;
	this->energyPoints = copyAssignment.energyPoints;
	this->attackDamage = copyAssignment.attackDamage;	
	return (*this);
}

ClapTrap::ClapTrap(std::string name){
	this->attackDamage = 0;
	this->hitPoints = 10;
	this->energyPoints = 10;
	std::cout << "ClapTrap constructor called" << std::endl;
	this->name = name;
}

void ClapTrap::attack(const std::string& target){
	if (this->energyPoints > 0){
		std::cout << GREEN << "ClapTrap " << this->name << " attacks "  << target << ", causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << "I don't have energy to attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->hitPoints < 0)
	{
		std::cout << RED << this->name << " is already dead!" << RESET << std::endl;
		std::cout << GREEN << "VIVA O SPORTING!" << RESET << std::endl;
		return ;
	}
	else if (this->hitPoints > 0){
		this->hitPoints -= amount;
	}
	if (this->hitPoints < 0){
		std::cout << RED << this->name << " is dead!" << RESET << std::endl;
		std::cout << GREEN << "VIVA O SPORTING!" << RESET << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->energyPoints > 0){
		this->hitPoints += amount;
		std::cout << this->name << " repairs himself" << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << "I don't have energy to repair myself!" << std::endl;
}

void ClapTrap::setAttackDamage(int damage){
	this->attackDamage = damage;
}

int ClapTrap::getDamage(){
	return (this->attackDamage);
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap destructor called" << std::endl;
}