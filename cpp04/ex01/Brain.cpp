#include "Brain.hpp"

Brain::Brain(){
	std::cout << WHITE << "Brain constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain& copyConstructor){
	for (int i = 0; i < 100; i++){
		this->ideas[i] = copyConstructor.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& copyAssignment){
	for (int i = 0; i < 100; i++){
		this->ideas[i] = copyAssignment.ideas[i];
	}
	return (*this);
}

Brain::~Brain(){
	
	std::cout << RED << "Brain destructor called" << RESET << std::endl;
}

void Brain::setIdeas(std::string idea, int i){
	if (i >= 100)
		return ;
	this->ideas[i] = idea;
}

std::string Brain::getIdeas(int i){
	if (i >= 100)
		return ("It is not on my brain!");
	return (this->ideas[i]);
}