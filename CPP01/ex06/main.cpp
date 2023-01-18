/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:36:49 by juzoanya          #+#    #+#             */
/*   Updated: 2023/01/18 14:42:14 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl		harl;
	std::string	level;

	if (argc != 2)
		std::cout << "Usage ./HarlFilter [Level]" << std::endl;
	else
	{
		level = argv[1];
		harl.complain(level);
	}
	return (0);
}