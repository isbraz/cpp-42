#include "Form.hpp"
#include <iostream>
#include <string>

Form::Form(): _name("Default"), _execute(100), _required(90){

}

Form::Form(const std::string &name, int execute, int required) : _name(name), _execute(execute), _required(required), _sign(false){
	if (this->_required < 1 || this->_execute < 1){
		throw Form::GradeTooHighException();
	}
	else if (this->_required > 150 || this->_execute > 150){
		throw Form::GradeTooLowException();
	}
}

Form::Form(const Form& copyConstructor) : _name(copyConstructor._name),  
_execute(copyConstructor._execute), _required(copyConstructor._required), _sign(copyConstructor._sign){

}

Form& Form::operator=(const Form& copyAssignment){
	if (this == &copyAssignment) {
		return *this;
	}
	this->_sign = copyAssignment._sign;
	return(*this);
}

void Form::beSigned(Bureaucrat &b){
	if (b.getGrade() > this->_required){
		throw Form::GradeTooLowException();
	}
	this->_sign = true;
}

const char* Form::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

const char* Form::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const std::string Form::getName() const {
	return this->_name;
}

bool Form::getSign() const{
	return this->_sign;
}

int Form::getRequired() const{
	return this->_required;
}

int Form::getExecute() const{
	return this->_execute;
}

std::ostream& operator<<(std::ostream &os, const Form &f){

	std::string status;

	if (f.getSign())
		status = "signed";
	else
		status = "not signed";

	os << "Form name: " << f.getName() << std::endl
	<< "Required to execute: " << f.getExecute() << std::endl
	<< "Required to sign: " << f.getRequired() << std::endl
	<< "Currently: " << status << std::endl;
	return os;
}

Form::~Form(){

}