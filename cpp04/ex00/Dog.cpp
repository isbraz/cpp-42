#include "Dog.hpp"

Dog::Dog(){
	this->type = "Dog";
	std::cout << WHITE << "Dog constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& copyConstructor) : Animal(copyConstructor){
	this->type = copyConstructor.type;
}

Dog& Dog::operator=(const Dog& copyAssignment){
	this->type = copyAssignment.type;
	return (*this);
}

Dog::~Dog(){
	std::cout << WHITE << "Dog destructor called" << RESET << std::endl;
}

std::string Dog::getType() const{
	return (this->type);
}

void Dog::makeSound() const{
	std::cout << "Dog: Woof-Woof" << std::endl;
}