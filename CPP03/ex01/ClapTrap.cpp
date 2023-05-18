/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:53:53 by juzoanya          #+#    #+#             */
/*   Updated: 2023/05/04 18:41:01 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src): _name(src._name), _hitPoint(src._hitPoint), _energyPoint(src._energyPoint), _attackDamage(src._attackDamage)
{
	std::cout << "ClapTrap copy constructor called for " << src._name << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &rhs)
{
	_name = rhs._name;
	_hitPoint = rhs._hitPoint;
	_energyPoint = rhs._energyPoint;
	_attackDamage = rhs._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << this->_name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoint > 0 && this->_hitPoint > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacked " << target << ", cuasing " << this->_hitPoint << " point of damage" << std::endl;
		this->_energyPoint--;
	}
	else
	{
		if (this->_energyPoint < 1)
			std::cout << "ClapTrap " << this->_name << " cannot attack. No more energy points!" << std::endl;
		if (this->_hitPoint < 1)
			std::cout << "ClapTrap " << this->_name << " attack is worthless. Aborted!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoint > 0)
	{
		this->_hitPoint -= amount;
		if (this->_hitPoint < 0)
			this->_hitPoint = 0;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage and has " << this->_hitPoint << " points remaining." << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoint > 0 && this->_hitPoint > 0)
	{
		this->_hitPoint += amount;
		std::cout << "ClapTrap " << this->_name << " has recovered " << amount << " hitpoints." << std::endl;
		this->_energyPoint--;
	}
	else
	{
		if (this->_energyPoint < 1)
			std::cout << "ClapTrap " << this->_name << " cannot be repaired. Not enough energy points." << std::endl;
		if (this->_hitPoint < 1)
			std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
	}
}