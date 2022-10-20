

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_NUM 8

class PhoneBook
{
private:
	Contact contacts[MAX_NUM];

public:
	PhoneBook(void);
	~PhoneBook();

	int		add_contact(int index);
	int		search_contact(int index);
	void	print_all();
	void	print_one(int index);
};

#endif