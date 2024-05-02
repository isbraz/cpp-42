#pragma once

#include <iostream>
#include <string>

class Fixed{
	private :
			int fixedPoint;
			static const int fracBits= 8;
	public :
			Fixed();
			~Fixed();
			Fixed(const Fixed& copyConstructor);
			Fixed& operator=(const Fixed& copyAssignment);

			void setRawBits(int const raw);
			int getRawBits(void) const;

};
