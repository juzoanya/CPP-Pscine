
#include "PhoneBook.hpp"

int	main(int argc, char *argv[])
{
	PhoneBook	phonebook;
	std::string	buff;
	bool		run = true;

	(void)argv;
	if (argc != 1)
		return (1);
	while (run)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, buff))
			return (0);
		if (buff == "ADD")
			std::cout << "Let's add something new here!" << std::endl;
		if (buff == "SEARCH")
			std::cout << "Let's Search something new here!" << std::endl;
		if (buff == "EXIT")
		{
			std::cout << "Programme Terminated!" << std::endl;
			run = false;
		}
	}
	return (0);
}