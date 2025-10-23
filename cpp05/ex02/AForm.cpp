#include "AForm.hpp"

AForm::AForm(): _name("Default"), _execute(100), _required(90){

}

AForm::AForm(const std::string &name, int execute, int required) : _name(name), _execute(execute), _required(required), _sign(false){
	if (this->_required < 1 || this->_execute < 1){
		throw AForm::GradeTooHighException();
	}
	else if (this->_required > 150 || this->_execute > 150){
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(const AForm& copyConstructor) : _name(copyConstructor._name),  
_execute(copyConstructor._execute), _required(copyConstructor._required), _sign(copyConstructor._sign){

}

AForm& AForm::operator=(const AForm& copyAssignment){
	if (this == &copyAssignment) {
		return *this;
	}
	this->_sign = copyAssignment._sign;
	return(*this);
}

void AForm::beSigned(Bureaucrat &b){
	if (b.getGrade() > this->_required){
		throw AForm::GradeTooLowException();
	}
	this->_sign = true;
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "form is not signed";
}

const std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getSign() const{
	return this->_sign;
}

int AForm::getRequired() const{
	return this->_required;
}

int AForm::getExecute() const{
	return this->_execute;
}

std::ostream& operator<<(std::ostream &os, const AForm &f){

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

AForm::~AForm(){

}