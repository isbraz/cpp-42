#include "Fixed.hpp"

Fixed::Fixed(void){
	this->fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n){
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = n << this->fracBits;
}

Fixed::Fixed(float n){
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = n * (1 << this->fracBits);
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

int Fixed::toInt() const {
	return ((this->fixedPoint >> this->fracBits));
}

float Fixed::toFloat() const {
	float floatPoint =  (float)fixedPoint / (1 << this->fracBits);
	return (floatPoint);
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}

std::ostream & operator << ( std::ostream &out, Fixed const &number ) {
	out << number.toFloat();
	return out;
}