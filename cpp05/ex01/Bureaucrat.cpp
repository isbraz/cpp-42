#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150){
	// std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade){
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copyAssignment){
	if (this == &copyAssignment)
		return *this;
	this->_grade = copyAssignment._grade;
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat& copyConstructor)
: _name(copyConstructor._name), _grade(copyConstructor._grade) {
}

Bureaucrat::~Bureaucrat(){
	// std::cout << "Bureaucrat destructor called" << std::endl;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const std::string& Bureaucrat::getName() const{
	return (this->_name);
}

int Bureaucrat::getGrade() const{
	return (this->_grade);
}

void Bureaucrat::increment(){
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrement(){
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(Form &f){
	try
	{
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " coudn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b){
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}