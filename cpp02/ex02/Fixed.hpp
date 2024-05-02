#pragma once

#include <iostream>
#include <string>
#include <math.h>

class Fixed{
	private :
			int fixedPoint;
			static const int fracBits= 8;
	public :
			Fixed();
			~Fixed();
			Fixed(const int n);
			Fixed(float n);
			Fixed(const Fixed& copyConstructor);
			////////decrement/increment//////
			Fixed& operator=(const Fixed& copyAssignment);
			Fixed& operator++(void);
			Fixed operator++(int);
			Fixed& operator--(void);
			Fixed operator--(int);
			//////////////////////////////////
			////comparison operators/////////
			bool operator==(const Fixed& other) const;
			bool operator!=(const Fixed& other) const;
			bool operator>=(const Fixed& other) const;
			bool operator<=(const Fixed& other) const;
			bool operator>(const Fixed& other) const;
			bool operator<(const Fixed& other) const;
			//////////////////////////////////////////
			/////arithmetic operators////////////////
			Fixed operator+(const Fixed& other) const;
			Fixed operator-(const Fixed& other) const;
			Fixed operator*(const Fixed& other) const;
			Fixed operator/(const Fixed& other) const;
			/////////////////////////////////////////
			//static member functions
			static Fixed& max(Fixed& a, Fixed& b);
			static const Fixed& max(const Fixed& a, const Fixed& b);
			static Fixed& min(Fixed& a, Fixed& b);
			static const Fixed& min(const Fixed& a, const Fixed& b);
			////////////////////////////////////////
			void setRawBits(int const raw);
			int getRawBits(void) const;
			int toInt() const;
			float toFloat() const;
			
};

std::ostream &operator << (std::ostream &out, Fixed const &number);

