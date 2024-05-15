#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Brain;

class Cat: public Animal{
	private:
			Brain *thougts;
	public:
			Cat();
			Cat(const Cat& copyConstructor);
			Cat& operator=(const Cat& copyAssignment);
			~Cat();
			////
			void makeSound() const;
			std::string getType() const;
			void setIdeas(std::string idea, int i);
			std::string getIdeas(int i);
};