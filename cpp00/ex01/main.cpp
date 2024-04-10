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

bool is_empty(int i, PhoneBook *list)
{
	int j = 1;

	while (j < 6)
	{
		if (list->getContact(i).getInfo((ContactValues)j).empty())
			return (true);
		j++;
	}
	return (false);
}

void ft_add(int i, PhoneBook *list)
{
	list->getContact(i).setContact(FIRST_NAME_ID);
	list->getContact(i).setContact(LAST_NAME_ID);
	list->getContact(i).setContact(PHONE_NUMBER_ID);
	list->getContact(i).setContact(NICKNAME_ID);
	list->getContact(i).setContact(DARKEST_ID);
}

void ft_search(int i, PhoneBook *list)
{
	static int temp;
	int	aux;

	if (i == 8)
		temp = 8;
	if (temp == 8)
		i = 8;
	//////////////////////////////////////////////////CREATE TABLE///////////////////////////////////////////////////////
	std::cout << "+-------------------------------------------+" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (int j = 0; j < i; j++)
    {
        std::cout << "|" << std::setw(10) << j << "|";
		if (list->getContact(j).getInfo(FIRST_NAME_ID).size() > 10)
            std::cout << std::setw(9) << list->getContact(j).getInfo(FIRST_NAME_ID).substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << list->getContact(j).getInfo(FIRST_NAME_ID).substr(0, 9) << "|";
        if (list->getContact(j).getInfo(LAST_NAME_ID).size() > 10)
            std::cout << std::setw(9) << list->getContact(j).getInfo(LAST_NAME_ID).substr(0, 9) << "." << "|";
		else 
			std::cout << std::setw(10) << list->getContact(j).getInfo(LAST_NAME_ID).substr(0, 9) << "|";
		if (list->getContact(j).getInfo(NICKNAME_ID).size() > 10)
            std::cout << std::setw(9) << list->getContact(j).getInfo(NICKNAME_ID).substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << list->getContact(j).getInfo(NICKNAME_ID).substr(0, 9) << "|";
		std::cout << std::endl;
		aux = j;
    }
	std::cout << "+-------------------------------------------+" << std::endl;
	///////////////////////////////////////////////////GET INFO/////////////////////////////////////////////////////////
	std::string input;
	std::cout << "type an index: "; 
	getline(std::cin, input);
	if ((atoi(input.c_str()) >= 0 && atoi(input.c_str()) <= 7) && atoi(input.c_str()) <= aux && !input.empty())
		list->getContact(atoi(input.c_str())).show_info();
	else 
		std::cout << "invalid index!" << std::endl;
}

int	main(void)
{
	PhoneBook list;
	std::string input;
	int i = 0;
	while (1)
	{
		set_menu();
		getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "\n\nINVALID COMMAND!" << std::endl;
			return (0);
		}
		if (input != "ADD" && input != "SEARCH" && input != "EXIT")
			std::cout << "Invalid command!" << std::endl;
		if (input == "ADD")
		{
			if (i > 7)
				i = 0;
			ft_add(i, &list);
			if (is_empty(i, &list))
				std::cout << "Invalid Contact!" << std::endl;
			else
				i++;
			std::cout << "Press enter to continue!" << std::endl; 
			std::cin.ignore(1, '\n');
			system("clear");
		}
		if (input == "SEARCH" && i > 0)
		{
			ft_search(i, &list);	
			std::cout << "\nPress enter to continue!" << std::endl; 
			std::cin.ignore(1, '\n');
			system("clear");
		}
		if (input == "EXIT")
			return (0);
	}
	
}
