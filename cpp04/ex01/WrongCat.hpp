#pragma once

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
	private :
			std::string type;
	public:
			WrongCat();
			WrongCat(const WrongCat& copyConstructor);
			WrongCat& operator=(const WrongCat& copyAssignment);
			~WrongCat();
			////
			void makeSound() const;
			std::string getType() const;
};