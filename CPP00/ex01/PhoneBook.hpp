/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:47:48 by juzoanya          #+#    #+#             */
/*   Updated: 2022/12/12 19:47:54 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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