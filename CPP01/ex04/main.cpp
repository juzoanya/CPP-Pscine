/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:43:45 by juzoanya          #+#    #+#             */
/*   Updated: 2023/01/12 16:24:08 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>


int	stringReplace(std::string file, std::string s1, std::string s2)
{
	std::ifstream	inputFile;
	std::ofstream	outputFile;

	return (0);
}

int	main(int argc, char *argv[])
{
	std::string	filename;
	std::string	s1;
	std::string	s2;

	if (argc != 4)
		std::cout << "Error: programme usage: ./replace [file] [s1] [s2]" << std::endl;
	else
	{
		filename = argv[1];
		s1 = argv[2];
		s2 = argv[3];
		if (s1.empty())
		{
			std::cout << "Error: string s1 cannot be empty!" << std::endl;
			return (1);
		}
		if(stringReplace(filename, s1, s2))
			return (1);
	}
	return (0);
}