/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:44:32 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/06 19:29:05 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	char		charArray[] = {'a', 'c', 't', 'I', 'N'};
	int			intArray[] = {12, 34, 56, 78, 91, 0};
	std::string	strArray[] = {"Hello", "World", "from", "Berlin"};
	double		douArray[] = {230.65, 100, 765.0, 90.5435, 42.42};

	iter(charArray, 5, printSpace);
	std::cout << std::endl;
	iter(intArray, 6, printSpace);
	std::cout << std::endl;
	iter(strArray, 4, printSpace);
	std::cout << std::endl;
	iter(douArray, 5, printSpace);
	std::cout << std::endl;
	return(0);
}