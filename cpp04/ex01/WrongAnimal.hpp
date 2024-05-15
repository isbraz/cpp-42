#pragma once

#include <iostream>
#include <string>

#define RED "\033[41m"
#define GREEN "\033[42m"
#define YELLOW "\033[43m"
#define WHITE "\033[47m"
#define RESET "\033[0m"

class WrongAnimal{
	protected:
				std::string type;
	public:
			WrongAnimal();
			WrongAnimal(const WrongAnimal& copyConstructor);
			WrongAnimal& operator=(const WrongAnimal& copyAssignment);
			virtual ~WrongAnimal();
			//////
			void makeSound() const;
			virtual std::string getType() const;
};