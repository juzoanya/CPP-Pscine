/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:05:05 by juzoanya          #+#    #+#             */
/*   Updated: 2023/05/29 14:34:31 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << this->_type << " Default constructor called." << std::endl;
}

Dog::Dog(std::string type) : Animal()
{
	this->_type = type;
	std::cout << this->_type << " parameterized constructor called." << std::endl;
}

Dog::Dog(const Dog& src) : Animal()
{
	*this = src;
	std::cout << src._type << " copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	Animal::operator=(rhs);
	return(*this);
}

Dog::~Dog()
{
	std::cout << "Destructor called for " << this->_type << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}