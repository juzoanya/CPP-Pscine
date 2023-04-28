/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:18:23 by juzoanya          #+#    #+#             */
/*   Updated: 2023/04/28 13:33:51 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i = -1;
	bool	state = false;
	std::string	mode[4] = {"DEBUG", "INFO", "WARNING", "ERROR" };
	
	void (Harl::*levels[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	while (++i < 4)
	{
		if (level == mode[i])
		{
			state = true;
			break;
		}
	}
	if (state == false)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
	{
		while (i < 4)
			(this->*(levels[i++]))();
	}
}