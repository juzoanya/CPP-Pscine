

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook(void) {}

int	PhoneBook::add_contact(void)
{
	std::cout << "Function to add contact" << std::endl;
	return (0);
}

int	PhoneBook::search_contact(void)
{
	std::cout << "Function to search contact" << std::endl;
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