#include "Contact.hpp"

Contact::Contact(void)
{

}

void Contact::setContact(ContactValues type)
{
	std::string	set;

	switch (type)
	{
	case FIRST_NAME_ID:
		std::cout << "first name: ";
		getline(std::cin, set);
		this->first_name = set;
		break;
	case LAST_NAME_ID:
		std::cout << "last name: ";
		getline(std::cin, set);
		this->last_name = set;
		break;
	case PHONE_NUMBER_ID:
		std::cout << "phone number: ";
		getline(std::cin, set);
		this->phone_number = set;
		break;
	case NICKNAME_ID:
		std::cout << "nickname: ";
		getline(std::cin, set);
		this->nickname = set;
		break;
	case DARKEST_ID:
		std::cout << "darkest secret: ";
		getline(std::cin, set);
		this->dark_secret = set;
		break;
	default:
		break;
	}
}

std::string Contact::getInfo(ContactValues type)
{
	switch (type)
	{
	case FIRST_NAME_ID:
		return (this->first_name);
	case LAST_NAME_ID:
		return (this->last_name);
	case PHONE_NUMBER_ID:
		return (this->phone_number);
	case NICKNAME_ID:
		return (this->nickname);
	case DARKEST_ID:
		return (this->dark_secret);
	default:
		return (this->first_name);
	}
}
