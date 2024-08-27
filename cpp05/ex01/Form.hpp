#pragma once 

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private:
		const std::string _name;
		const int _execute;
		const int _required;
		bool _sign;
		class GradeTooLowException : public std::exception{
			const char *what() const throw();
		};
		class GradeTooHighException : public std::exception{
			const char *what() const throw();
		};
	public:
		Form();
		Form(const std::string &name, int execute, int required);
		Form(const Form& copyConstructor);
		Form& operator=(const Form& copyAssignment);
		~Form();
		void beSigned(Bureaucrat &teste);
		bool getSign() const;
		const std::string getName() const;
		int getRequired() const;
		int getExecute() const;
};

std::ostream& operator<<(std::ostream &os, const Form &b);
