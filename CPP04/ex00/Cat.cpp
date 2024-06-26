/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:58:51 by juzoanya          #+#    #+#             */
/*   Updated: 2023/05/29 14:17:57 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << this->_type << " Default constructor called." << std::endl;
}

Cat::Cat(std::string type) : Animal()
{
	this->_type = type;
	std::cout << this->_type << " parameterized constructor called." << std::endl;
}

Cat::Cat(const Cat& src) : Animal()
{
	*this = src;
	std::cout << src._type << " copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	Animal::operator=(rhs);
	return(*this);
}

Cat::~Cat()
{
	std::cout << "Destructor called for " << this->_type << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}