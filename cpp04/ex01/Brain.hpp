#pragma once

#include "Cat.hpp"
#include "Dog.hpp"

class Brain{
	private:
			std::string ideas[100];
	public:
			Brain();
			Brain(const Brain& copyConstructor);
			Brain& operator=(const Brain& copyassignment);
			~Brain();
			//////
			void setIdeas(std::string idea, int i);
			std::string getIdeas(int i);
};
