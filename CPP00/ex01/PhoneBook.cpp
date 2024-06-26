/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:47:40 by juzoanya          #+#    #+#             */
/*   Updated: 2022/12/12 19:47:44 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook(void) {}

void	print_string(std::string str)
{
	if (str.length() > 10)
		std::cout << "|" << str.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << str;
}

int	is_numbers(std::string str)
{
	for (int i = 0; str[i] != '\0'; i++){
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	PhoneBook::add_contact(int index)
{
	std::string	str;

	std::cout << "> Enter First Name: ";
	while (std::getline(std::cin, str) && str.empty())
		std::cout << "> Enter First Name: ";
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
	while ((std::getline(std::cin, str) && str.empty()) || (!str.empty() && !is_numbers(str)))
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
	{
		if (str.length() > 1 || str[0] < '0' || str[0] > '9' || str[0] > (index + 48 - 1))
		{
			std::cout << "Index is invalid!" << std::endl;
			std::cout << "> Enter Index: ";
		}
		else
		{
			print_one(str[0] + '0');
			break;
		}
	}
	return (0);
}

void	PhoneBook::print_one(int index)
{
	std::cout << "First Name: " << contacts[index % MAX_NUM].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index % MAX_NUM].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index % MAX_NUM].getNickName() << std::endl;
	std::cout << "Phone Number: " << contacts[index % MAX_NUM].getPhoneNumber() << std::endl;
	std::cout << "Dark Secret: " << contacts[index % MAX_NUM].getDarkestSecret() << std::endl;
}