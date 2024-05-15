#include "Dog.hpp"

Dog::Dog(){
	this->type = "Dog";
	this->thougts = new Brain();
	std::cout << WHITE << "Dog constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& copyConstructor) : Animal(copyConstructor){
	this->type = copyConstructor.type;
	this->thougts = new Brain(*copyConstructor.thougts);
}

Dog& Dog::operator=(const Dog& copyAssignment){
	if (this != &copyAssignment){
		this->type = copyAssignment.type;
		delete this->thougts;
		this->thougts = new Brain(*copyAssignment.thougts);
	}
	return (*this);
}

Dog::~Dog(){
	delete this->thougts;
	std::cout << RED << "Dog destructor called" << RESET << std::endl;
}

std::string Dog::getType() const{
	return (this->type);
}

void Dog::makeSound() const{
	std::cout << "Dog: Woof-Woof" << std::endl;
}

void Dog::setIdeas(std::string ideas, int i){
	this->thougts->setIdeas(ideas, i);
}

std::string Dog::getIdeas(int i){
	return (this->thougts->getIdeas(i));
}