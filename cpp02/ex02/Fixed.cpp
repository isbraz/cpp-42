#include "Fixed.hpp"

Fixed::Fixed(void){
	this->fixedPoint = 0;
}

Fixed::Fixed(const int n){
	this->fixedPoint = n << this->fracBits;
}

Fixed::Fixed(float n){
	this->fixedPoint = n * (1 << this->fracBits);
}

Fixed::Fixed(const Fixed& copyConstructor){
	this->fixedPoint = copyConstructor.fixedPoint;
}

Fixed& Fixed::operator=(const Fixed& copyAssignment){
	this->fixedPoint = copyAssignment.fixedPoint;
	return (*this);
}
/////////////////////////////////////////
////increment/decrement
Fixed& Fixed::operator++(void){
	this->fixedPoint++;
	return (*this);
}

Fixed Fixed::operator++(int){
	Fixed temp = *this;
	++(*this);
	return (temp);
}

Fixed& Fixed::operator--(void){
	this->fixedPoint--;
	return (*this);
}

Fixed Fixed::operator--(int){
	Fixed temp = *this;
	--(*this);
	return (temp);
}
/////////////////////////////////////////
////Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const{
	return (Fixed(this->toFloat() / other.toFloat()));	
}
////////////////////////////////////////
////Comparison operators
bool Fixed::operator==(const Fixed& other) const{
	return (this->fixedPoint == other.fixedPoint);
}

bool Fixed::operator!=(const Fixed& other) const{
	return (this->fixedPoint != other.fixedPoint);
}

bool Fixed::operator>=(const Fixed& other) const{
	return (this->fixedPoint >= other.fixedPoint);
}

bool Fixed::operator<=(const Fixed& other) const{
	return (this->fixedPoint <= other.fixedPoint);
}

bool Fixed::operator>(const Fixed& other) const{
	return (this->fixedPoint > other.fixedPoint);
}

bool Fixed::operator<(const Fixed& other) const{
	return (this->fixedPoint < other.fixedPoint);
}
////////////////////////////////////
void Fixed::setRawBits(int const raw){
	this->fixedPoint = raw;
}

int Fixed::getRawBits(void) const{
	return(this->fixedPoint);
}

int Fixed::toInt() const {
	return ((this->fixedPoint >> this->fracBits));
}

float Fixed::toFloat() const {
	float floatPoint =  (float)fixedPoint / (1 << this->fracBits);
	return (floatPoint);
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
	return ((a > b) ? a : b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
	return ((a < b) ? a : b);
}

const Fixed& Fixed::max(const Fixed& a,const Fixed& b){
	return ((a > b) ? a : b);
}

const Fixed& Fixed::min(const Fixed& a,const Fixed& b){
	return ((a < b) ? a : b);
}

Fixed::~Fixed(void){

}

std::ostream & operator << ( std::ostream &out, Fixed const &number ) {
	out << number.toFloat();
	return out;
}