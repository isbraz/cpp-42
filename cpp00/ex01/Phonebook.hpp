#ifndef	PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <iomanip>
# include <cstdlib>
# include "Contact.hpp"

class PhoneBook {
	private:
			Contact contacts[8];
	public:
			PhoneBook();
			Contact &getContact(int i);
};

#endif