#include "Fixed.hpp"

Fixed::Fixed(void){
	this->fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copyConstructor){
	this->fixedPoint = copyConstructor.fixedPoint;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copyAssignment){
	this->fixedPoint = copyAssignment.fixedPoint;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

void Fixed::setRawBits(int const raw){
	this->fixedPoint = raw;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->fixedPoint);
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << this->fixedPoint << std::endl;
}
