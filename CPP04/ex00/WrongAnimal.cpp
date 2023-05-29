/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:04:47 by juzoanya          #+#    #+#             */
/*   Updated: 2023/05/29 14:31:06 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->_type = "";
	std::cout << this->_type << " Default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->_type = type;
	std::cout << this->_type << " parameterized constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	*this = src;
	std::cout << this->_type << " copy constructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	this->_type = rhs._type;
	return(*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called for " << this->_type << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Default WrongAnimal Sound." << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return(this->_type);
}