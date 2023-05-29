/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:05:14 by juzoanya          #+#    #+#             */
/*   Updated: 2023/05/29 14:14:43 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << this->_type << " Default constructor called." << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal()
{
	this->_type = type;
	std::cout << this->_type << " parameterized constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal()
{
	*this = src;
	std::cout << this->_type << " copy constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	WrongAnimal::operator=(rhs);
	return(*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor called for " << this->_type << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}