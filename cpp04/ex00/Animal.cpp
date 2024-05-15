#include "Animal.hpp"

Animal::Animal(){
	std::cout << WHITE << "Animal constructor called" << RESET <<std::endl;
}

Animal::Animal(const Animal& copyConstructor){
	this->type = copyConstructor.type;
}

Animal& Animal::operator=(const Animal& copyAssingment){
	this->type = copyAssingment.type;
	return (*this);
}

void Animal::makeSound() const{
	std::cout << "Class Animal doesnt make a sound!" << std::endl;
}

std::string Animal::getType() const{
	return("I dont have a type");
}

Animal::~Animal(){
	std::cout << WHITE << "Animal destructor called" << RESET << std::endl;
}