/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:36:49 by juzoanya          #+#    #+#             */
/*   Updated: 2023/01/18 08:41:48 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl		harl;
	std::string	input;

	std::cout << "Choose a complain level {debug, info, warning, error}" << std::endl;
	if(!std::getline(std::cin, input))
		return (1);
	harl.complain(input);
}