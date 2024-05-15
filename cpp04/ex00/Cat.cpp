#include "Cat.hpp"

Cat::Cat(){
	this->type = "Cat";
	std::cout << WHITE << "Cat constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& copyConstructor) : Animal(copyConstructor){
	this->type = copyConstructor.type;
}

Cat& Cat::operator=(const Cat& copyAssignment){
	this->type = copyAssignment.type;
	return (*this);
}

std::string Cat::getType() const{
	return (this->type);
}

void Cat::makeSound() const{
	std::cout << "Cat: Meow" << std::endl;
}

Cat::~Cat(){
	std::cout << WHITE << "Cat destructor called" << RESET << std::endl;
}