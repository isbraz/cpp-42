#pragma once

#include <iostream>
#include <string>
#include <math.h>

class Fixed{
	private :
			int fixedPoint;
			static const int fracBits= 4;
	public :
			Fixed();
			~Fixed();
			Fixed(const int n);
			Fixed(float n);
			Fixed(const Fixed& copyConstructor);
			Fixed& operator=(const Fixed& copyAssignment);
			void setRawBits(int const raw);
			int getRawBits(void) const;
			int toInt() const;
			float toFloat() const;

};

std::ostream &operator << (std::ostream &out, Fixed const &number);
