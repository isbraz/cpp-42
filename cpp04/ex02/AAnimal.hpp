#pragma once

#include <iostream>
#include <string>

#define RED "\033[41m"
#define GREEN "\033[42m"
#define YELLOW "\033[43m"
#define WHITE "\033[47m"
#define RESET "\033[0m"

class AAnimal{
	protected:
			std::string type;
	public:
			AAnimal();
			AAnimal(const AAnimal& copyConstructor);
			AAnimal& operator=(const AAnimal& copyAssignment);
			virtual ~AAnimal();
			//////
			virtual void makeSound() const = 0;
			virtual std::string getType() const;
};