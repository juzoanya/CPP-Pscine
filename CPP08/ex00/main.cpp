/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:48:25 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/09 22:07:22 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"

int	main(void)
{
	std::vector<int>	numbers;
	//std::list<int>	lst;

	for (int i = 0; i < 12; i++)
		numbers.push_back(i + 3);
	try
	{
		std::vector<int>::iterator res = easyFind(numbers, 3);
		std::cout << *res << std::endl;
	}
	catch(ValueNotFoundException& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return(0);
}