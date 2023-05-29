/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:57:31 by juzoanya          #+#    #+#             */
/*   Updated: 2023/05/29 14:16:30 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("")
{
	std::cout << "Animal Default constructor called." << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << "Animal " << this->_type << " constructor called." << std::endl;
}

Animal::Animal(const Animal& src)
{
	*this = src;
	std::cout << "Animal copy contructor called on " << src._type << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
	this->_type = rhs._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called for " << this->_type << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal Default Sound" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->_type);
}