/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:00:36 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/07 12:41:04 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char* argv[])
{
	if (argc > 1)
	{
		std::string	str = argv[1];
		try
		{
			ScalarConverter::convert(str);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
		std::cout << "Provide an item to be converted!" << std::endl;
	return(0);
}