/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Humanb.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:29:07 by juzoanya          #+#    #+#             */
/*   Updated: 2022/12/15 16:24:47 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
}

HumanB::~HumanB()
{
	return;
}

void	HumanB::attack()
{
	if (!this->_weapon)
		return ;
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}