/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:53:14 by juzoanya          #+#    #+#             */
/*   Updated: 2023/01/26 16:49:25 by juzoanya         ###   ########.fr       */
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

Fixed::Fixed(const Fixed& nbr): _nbr(0)
{
	//this->_nbr = 0;
	std::cout << "Copy constructor called" << std::endl;
	*this = nbr;
}

Fixed& Fixed::operator=(const Fixed& nbr)
{
	std::cout << "Copy assignment operator called" << std::endl;

}