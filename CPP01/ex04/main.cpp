/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:43:45 by juzoanya          #+#    #+#             */
/*   Updated: 2023/01/19 20:53:29 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>


int	stringReplace(std::string file, std::string s1, std::string s2)
{
	std::size_t		pos;
	std::size_t		spos;
	std::string		buffer;
	std::string		newStr;
	std::ifstream	inputFile;
	std::ofstream	outputFile;

	inputFile.open(file.c_str(), std::ios::in);
	if (!inputFile.is_open())
	{
		std::cerr << "Error: failed to open " << file << std::endl;
		return (1);
	}
	std::string	outFile = file.append(".replace");
	outputFile.open(outFile.c_str(), std::ios::out);
	if (!outputFile.is_open())
	{
		std::cerr << "Error: failed to create " << file.append(".replace") << std::endl;
		return (1);
	}
	spos = 0;
	while (std::getline(inputFile, buffer))
	{
		while ((pos = buffer.find(s1)) != std::string::npos)
		{
			buffer.erase(spos, s1.size());
			buffer.insert(spos, s2);
		}
		outputFile << buffer;
		if (inputFile.eof())
			outputFile << std::endl;
	}
	inputFile.close();
	outputFile.close();
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