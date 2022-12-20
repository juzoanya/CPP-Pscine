/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:29:25 by juzoanya          #+#    #+#             */
/*   Updated: 2022/12/20 11:02:48 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
	std::cout << "Weapon " << this->_type << " is created" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon " << this->_type << " is destroyed" << std::endl;
}

std::string	const &Weapon::getType()
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}