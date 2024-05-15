#pragma once

#include "Animal.hpp"

class Dog: public Animal{
	public:
			Dog();
			Dog(const Dog& copyConstructor);
			Dog& operator=(const Dog& copyAssignment);
			~Dog();
			std::string getType() const;
			void makeSound() const;
};