

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook();

	int	adContact();
	int	searchContact();
};

#endif