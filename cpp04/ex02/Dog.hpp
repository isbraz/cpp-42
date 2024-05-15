#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Brain;

class Dog: public AAnimal{
	private:
			Brain *thougts;
	public:
			Dog();
			Dog(const Dog& copyConstructor);
			Dog& operator=(const Dog& copyAssignment);
			~Dog();
			///////
			std::string getType() const;
			void makeSound() const;
			void setIdeas(std::string idea, int i);
			std::string getIdeas(int i);
};