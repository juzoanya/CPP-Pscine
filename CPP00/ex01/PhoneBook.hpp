

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_NUM 8

class PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook();

	int		add_contact();
	int		search_contact();
	void	print_all();
	void	print_one(int index);
};

#endif