/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:49:51 by juzoanya          #+#    #+#             */
/*   Updated: 2023/01/12 09:05:06 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "Variable Address = " << &str << std::endl;
	std::cout << "stringPTR Address = " << stringPTR << std::endl;
	std::cout << "stringREF Address = " << &stringREF << std::endl;

	std::cout << "------------------------------------" << std::endl;

	std::cout << "variable Value = " << str << std::endl;
	std::cout << "stringPTR Value = " << *stringPTR << std::endl;
	std::cout << "stringREF Value = " << stringREF << std::endl;

	return (0);
}