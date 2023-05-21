/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:53:14 by juzoanya          #+#    #+#             */
/*   Updated: 2023/05/21 20:58:05 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
	this->_nbr = nbr << _bit;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nbr)
{
	this->_nbr = roundf(nbr *(1 << _bit));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src): _nbr(src._nbr)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& nbr)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &nbr)
		_nbr = nbr._nbr;
	return (*this);
}

bool Fixed::operator>(const Fixed& rhs)
{
	return(this->_nbr > rhs._nbr);
}

bool Fixed::operator<(const Fixed& rhs)
{
	return (this->_nbr < rhs._nbr);
}

bool Fixed::operator>=(const Fixed& rhs)
{
	return (this->_nbr >= rhs._nbr);
}

bool Fixed::operator<=(const Fixed& rhs)
{
	return (this->_nbr <= rhs._nbr);
}

bool Fixed::operator==(const Fixed& rhs)
{
	return (this->_nbr == rhs._nbr);
}

bool Fixed::operator!=(const Fixed& rhs)
{
	return (this->_nbr != rhs._nbr);
}

Fixed Fixed::operator+(const Fixed& rhs)
{
	Fixed	result;
	result._nbr = _nbr + rhs._nbr;
	return (result);
}

Fixed Fixed::operator-(const Fixed& rhs)
{
	Fixed	result;
	result._nbr = _nbr - rhs._nbr;
	return (result);
}

Fixed Fixed::operator*(const Fixed& rhs)
{
	Fixed	result;
	result._nbr = (_nbr * rhs._nbr) >> this->_bit;
	return (result);
}

Fixed Fixed::operator/(const Fixed& rhs)
{
	Fixed	result;
	result._nbr = (_nbr << this->_bit) / rhs._nbr;
	return (result);
}

Fixed& Fixed::operator++()
{
	this->_nbr++;
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->_nbr--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++*this;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--*this;
	return temp;
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
	return (this->_nbr >> _bit);
}

float	Fixed::toFloat(void) const
{
	float value;
	value = static_cast<float>(this->_nbr);
	return (value / (1 << _bit));
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a._nbr < b._nbr)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a._nbr > b._nbr)
		return (a);
	return (b);
}

std::ostream& operator<<(std::ostream& obj, Fixed const & rhs)
{
	obj << rhs.toFloat();
	return (obj);
}