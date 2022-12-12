/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:47:24 by juzoanya          #+#    #+#             */
/*   Updated: 2022/12/12 19:47:28 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	prep_ad_contact(PhoneBook *phoneBook, int *index)
{
	if (!phoneBook->add_contact((*index) % MAX_NUM))
		return (1);
	if ((*index) + 1 < MAX_NUM)
		(*index)++;
	else
		(*index) = MAX_NUM;
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
		{
			if (prep_ad_contact(&phoneBook, &index))
				break;
		}
		else if (buff == "SEARCH")
		{
			if (phoneBook.search_contact(index))
				break;
		}
		else if (buff == "EXIT")
		{
			std::cout << "Programme Terminated!" << std::endl;
			run = false;
		}
	}
	return (0);
}