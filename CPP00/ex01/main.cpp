
#include "PhoneBook.hpp"

int	prep_ad_contact(PhoneBook *phoneBook, int *index)
{
	if (!phoneBook->add_contact((*index) % 8))
		return (1);
	if ((*index) + 1 < 16)
		(*index)++;
	else
		(*index) = 8;
	return (0);
}

int	main(int argc, char *argv[])
{
	PhoneBook	phoneBook;
	std::string	buff;
	bool		run = true;
	int			index;

	(void)argv;
	index = 0;
	if (argc != 1)
		return (1);
	while (run)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, buff))
			return (0);
		if (buff == "ADD")
			if (prep_ad_contact(&phoneBook, &index))
				break;
		if (buff == "SEARCH")
			phoneBook.search_contact(index);
		if (buff == "EXIT")
		{
			std::cout << "Programme Terminated!" << std::endl;
			run = false;
		}
	}
	return (0);
}