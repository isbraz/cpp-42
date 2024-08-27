#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

#define RED "\033[41m"
#define GREEN "\033[42m"
#define YELLOW "\033[43m"
#define WHITE "\033[47m"
#define RESET "\033[0m"

class Form;

class Bureaucrat{
	private:
		const std::string _name;
		int _grade;
		class GradeTooLowException : public std::exception{
				const char *what() const throw();
		};
		class GradeTooHighException : public std::exception{
				const char *what() const throw();
		};
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& copyConstructor);
		Bureaucrat& operator=(const Bureaucrat& copyAssignment);
		~Bureaucrat();

		const std::string& getName() const;
		int  getGrade() const;
		void increment();
		void decrement();
		void signForm(Form &test);

};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b);