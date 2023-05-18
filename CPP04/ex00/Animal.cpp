/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:57:31 by juzoanya          #+#    #+#             */
/*   Updated: 2023/05/12 13:42:07 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Default constructor called." << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << "Animal " << this->_type << " constructor called." << std::endl;
}

Animal::Animal(Animal const &src): _type(src._type)
{
	std::cout << "Animal copy contructor called on " << src._type << std::endl;
}

Animal& Animal::operator=(Animal const &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called for " << this->_type << std::endl;
}

void	Animal::makeSound()
{
	std::cout << "Animal Default Sound" << std::endl;
}

std::string	Animal::getType()
{
	return (this->_type);
}