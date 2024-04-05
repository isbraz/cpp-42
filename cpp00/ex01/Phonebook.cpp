#include "Phonebook.hpp"

PhoneBook::PhoneBook()
{

}

Contact &PhoneBook::getContact(int i)
{
	return (this->contacts[i]);
}