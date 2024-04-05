#ifndef	CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <string>

typedef enum ContactCodes {
	FIRST_NAME_ID = 1,
	LAST_NAME_ID = 2,
	PHONE_NUMBER_ID = 3,
	NICKNAME_ID = 4,
	DARKEST_ID = 5,

} ContactValues;

class Contact {
	private:
			std::string first_name;
			std::string last_name;
			std::string phone_number;
			std::string nickname;
			std::string dark_secret;
	public:
			Contact(void); 
			std::string getInfo(ContactValues type);
			void setContact(ContactValues type);
};

#endif