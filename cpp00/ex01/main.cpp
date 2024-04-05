#include "Phonebook.hpp"

void set_menu()
{
	std::cout << "┌──────────────────────┐" << std::endl;
    std::cout << "│      PHONEBOOK       │" << std::endl;
    std::cout << "├──────────────────────┤" << std::endl;
    std::cout << "│  1. ADD              │" << std::endl;
    std::cout << "│  2. SEARCH           │" << std::endl;
    std::cout << "│  3. EXIT             │" << std::endl;
    std::cout << "└──────────────────────┘" << std::endl;
    std::cout << "Enter your choice: ";

}

void ft_add(int i, PhoneBook *list)
{
	// if (i > 8)
	// {

	// }
	list->getContact(i).setContact(FIRST_NAME_ID);
	list->getContact(i).setContact(LAST_NAME_ID);
	list->getContact(i).setContact(PHONE_NUMBER_ID);
	list->getContact(i).setContact(NICKNAME_ID);
	list->getContact(i).setContact(DARKEST_ID);
}

int	main(void)
{
	PhoneBook list;
	std::string input;

	while (1)
	{
		set_menu();
		getline(std::cin, input);
		if (input != "ADD" && input != "SEARCH" && input != "EXIT")
			std::cout << "Invalid command!" << std::endl;
		if (input == "ADD")
			ft_add(0, &list);
		// if (input == "SEARCH")
		// {
		// 	//search
		// }
		if (input == "EXIT")
			return (0);
	}
}
