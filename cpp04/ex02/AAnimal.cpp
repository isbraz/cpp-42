#include "AAnimal.hpp"

AAnimal::AAnimal(){
	std::cout << WHITE << "AAnimal constructor called" << RESET <<std::endl;
}

AAnimal::AAnimal(const AAnimal& copyConstructor){
	this->type = copyConstructor.type;
}

AAnimal& AAnimal::operator=(const AAnimal& copyAssingment){
	this->type = copyAssingment.type;
	return (*this);
}

void AAnimal::makeSound() const{
	std::cout << "Class AAnimal doesnt make a sound!" << std::endl;
}

std::string AAnimal::getType() const{
	return("I dont have a type");
}

AAnimal::~AAnimal(){
	std::cout << RED << "AAnimal destructor called" << RESET << std::endl;
}