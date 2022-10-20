

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook(void) {}

void	print_string(std::string str)
{
	std::string	temp;

	if (str.length() > 10)
	{
		temp = str.substr(0, 9);
		std::cout << "|" << std::setw(10) << temp << ".";
	}
	else
		std::cout << "|" << std::setw(10) << str;
}

int	PhoneBook::add_contact(int index)
{
	std::string	str;

	std::cout << "> Enter First Name: ";
	while (std::getline(std::cin, str) && str.empty())
		std::cout << "> Enter First Name: ";
	//std::cout << "$" << str << "$" << std::endl;
	this->contacts[index].setFirstName(str);
	std::cout << "> Enter Last Name: ";
	while (std::getline(std::cin, str) && str.empty())
		std::cout << "> Enter Last Name: ";
	this->contacts[index].setLastName(str);
	std::cout << "> Enter Nickname: ";
	while (std::getline(std::cin, str) && str.empty())
		std::cout << "> Enter Nickname: ";
	this->contacts[index].setNickName(str);
	std::cout << "> Enter Phone Name: ";
	while (std::getline(std::cin, str) && str.empty())
		std::cout << "> Enter Phone Name: ";
	this->contacts[index].setPhoneNumber(str);
	std::cout << "> Enter Dark Secret: ";
	while (std::getline(std::cin, str) && str.empty())
		std::cout << "> Enter Dark Secret: ";
	this->contacts[index].setDarkestSecret(str);
	return (1);
}

int	PhoneBook::search_contact(int index)
{
	std::string	str;
	int			id = 0;

	if (index == 0)
	{
		std::cout << "No Contact in Phonebook!" << std::endl;
		return (0);
	}
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < index; i++)
	{
		std::cout << "|" << std::setw(10) << i;
		print_string(contacts[i].getFirstName());
		print_string(contacts[i].getLastName());
		print_string(contacts[i].getNickName());
		std::cout << "|" << std::endl;
	}
	std::cout << "> Enter Index: ";
	while (std::getline(std::cin, str))
		std::cout << "> Enter Index: ";
	print_one(id);
	std::cout << id << std::endl;
	return (0);
}

void	PhoneBook::print_all()
{
	std::cout << "Function to print all contact" << std::endl;
}

void	PhoneBook::print_one(int index)
{
	(void)index;
	std::cout << "Function to print specific contact" << std::endl;
}