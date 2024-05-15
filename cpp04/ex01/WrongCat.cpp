#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat(){
	this->type = "WrongCat";
	std::cout << WHITE << "WrongCat constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& copyConstructor) : WrongAnimal(copyConstructor){
	this->type = copyConstructor.type;
}

WrongCat& WrongCat::operator=(const WrongCat& copyAssignment){
	this->type = copyAssignment.type;
	return (*this);
}

std::string WrongCat::getType() const{
	return (this->type);
}

void WrongCat::makeSound() const{
	std::cout << "WrongCat: Meow" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << WHITE << "WrongCat destructor called" << RESET << std::endl;
}