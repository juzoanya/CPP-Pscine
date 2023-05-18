/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:44:36 by juzoanya          #+#    #+#             */
/*   Updated: 2023/05/04 22:30:22 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	
	std::cout << "Default ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;

	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src): ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called for " << src._name << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &rhs)
{
	ClapTrap::operator=(rhs);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << this->_name << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
	if (this->_energyPoint > 0 && this->_hitPoint > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacked " << target << ", cuasing " << this->_hitPoint << " point of damage" << std::endl;
		this->_energyPoint--;
	}
	else
	{
		if (this->_energyPoint < 1)
			std::cout << "ScavTrap " << this->_name << " cannot attack. No more energy points!" << std::endl;
		if (this->_hitPoint < 1)
			std::cout << "ScavTrap " << this->_name << " attack is worthless. Aborted!" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	if (this->_energyPoint > 0 && this->_hitPoint > 0)
		std::cout << "ScavTrap " << this->_name << ": Gate Keeper mode activated." << std::endl;
}