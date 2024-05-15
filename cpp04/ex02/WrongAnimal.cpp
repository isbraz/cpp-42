#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << WHITE << "WrongAnimal constructor called" << RESET <<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copyConstructor){
	this->type = copyConstructor.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copyAssingment){
	this->type = copyAssingment.type;
	return (*this);
}

void WrongAnimal::makeSound() const{
	std::cout << "Class WrongAnimal doesnt make a sound!" << std::endl;
}

std::string WrongAnimal::getType() const{
	return("I dont have a type");
}

WrongAnimal::~WrongAnimal(){
	std::cout << WHITE << "WrongAnimal destructor called" << RESET << std::endl;
}