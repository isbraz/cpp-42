#pragma once

#include <iostream>
#include <string>

#define RED "\033[41m"
#define GREEN "\033[42m"
#define YELLOW "\033[43m"
#define WHITE "\033[47m"
#define RESET "\033[0m"

class Animal{
	protected:
				std::string type;
	public:
			Animal();
			Animal(const Animal& copyConstructor);
			Animal& operator=(const Animal& copyAssignment);
			virtual ~Animal();
			//////
			virtual void makeSound() const;
			virtual std::string getType() const;
};