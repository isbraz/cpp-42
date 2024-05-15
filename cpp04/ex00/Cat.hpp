#pragma once

#include "Animal.hpp"

class Cat: public Animal{
	public:
			Cat();
			Cat(const Cat& copyConstructor);
			Cat& operator=(const Cat& copyAssignment);
			~Cat();
			////
			void makeSound() const;
			std::string getType() const;
};