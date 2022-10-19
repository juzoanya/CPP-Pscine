
#include "PhoneBook.hpp"

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
		{
			phoneBook.add_contact(index);
			index++;
		}
		if (buff == "SEARCH")
			phoneBook.search_contact();
		if (buff == "EXIT")
		{
			std::cout << "Programme Terminated!" << std::endl;
			run = false;
		}
	}
	return (0);
}