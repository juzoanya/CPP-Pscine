/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:06:21 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/11 20:34:47 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	int	size = 10000;
	Span	spanFull(size);

	for (int i = 0; i < size; i++)
		spanFull.addNumber(rand());
	try
	{
		spanFull.addNumber(rand());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << spanFull.shortestSpan() << std::endl;
	std::cout << spanFull.longestSpan() << std::endl;
	std::cout << std::endl;

	Span spanRange(20);
	std::vector<int> vect(25, 25);
	try
	{
		spanRange.addNumber(vect.begin(), vect.end());
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	Span	newSpanRange(10);
	std::vector<int> newVect(10, 10);
	newVect.at(5) = 1342;
	newSpanRange.addNumber(newVect.begin(), newVect.end());
	std::cout << newSpanRange.shortestSpan() << std::endl;
	std::cout << newSpanRange.longestSpan() << std::endl;

	return(0);
}