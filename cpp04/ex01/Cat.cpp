#include "Cat.hpp"

Cat::Cat(){
	this->type = "Cat";
	this->thougts = new Brain();
	std::cout << WHITE << "Cat constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& copyConstructor) : Animal(copyConstructor){
	this->type = copyConstructor.type;
	this->thougts = new Brain(*copyConstructor.thougts);
}

Cat& Cat::operator=(const Cat& copyAssignment){
	if (this != &copyAssignment){
		this->type = copyAssignment.type;
		delete this->thougts;
		this->thougts = new Brain(*copyAssignment.thougts);
	}
	return (*this);
}

std::string Cat::getType() const{
	return (this->type);
}

Cat::~Cat(){
	delete this->thougts;
	std::cout << RED << "Cat destructor called" << RESET << std::endl;
}

void Cat::makeSound() const{
	std::cout << "Cat: Meow" << std::endl;
}

void Cat::setIdeas(std::string ideas, int i){
	this->thougts->setIdeas(ideas, i);
}

std::string Cat::getIdeas(int i){
	return (this->thougts->getIdeas(i));
}