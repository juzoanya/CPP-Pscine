/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:36:49 by juzoanya          #+#    #+#             */
/*   Updated: 2023/01/17 16:46:38 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl		harl;
	std::string	input;

	std::cout << "Choose one of the following complain levels (debug, info, warning, error)";
	if(!std::getline(std::cin, input))
		return (1);
	harl.complain(input);
}