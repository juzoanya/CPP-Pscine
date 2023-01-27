/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:53:14 by juzoanya          #+#    #+#             */
/*   Updated: 2023/01/27 16:50:12 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_nbr = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int nbr): _nbr(0)
{
	std::cout << "Int constructor called" << std::endl;
	this->_nbr = nbr << this->_bit;
	return;
}

Fixed::Fixed(const float nbr): _nbr(0)
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& nbr): _nbr(0)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = nbr;
}

Fixed& Fixed::operator=(const Fixed& nbr)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &nbr)
		_nbr = nbr.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_nbr);
}

void	Fixed::setRawBits(int const raw)
{
	_nbr = raw;
}

int	Fixed::toInt(void) const
{
	
}

float	Fixed::toFloat(void) const
{
	
}

const int	Fixed::_bit = 8;