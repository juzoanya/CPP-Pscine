/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:28:05 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/10 22:33:05 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0)
{}

Span::Span(unsigned int N) : _maxSize(N)
{}

Span::Span(const Span& src) : _maxSize(src._maxSize), _vect(src._vect)
{}

Span&	Span::operator=(const Span& rhs)
{
	this->_maxSize = rhs._maxSize;
	for (unsigned int i = 0; i < this->_maxSize; i++)
		this->_vect[i] = rhs._vect[i];
	return(*this);
}

Span::~Span()
{}

void	Span::addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	unsigned int range = std::distance(begin, end);
	if (this->_vect.size() + range > this->_maxSize)
		throw Span::SpanSizeExceededException();
	this->_vect.insert(this->_vect.end(), begin, end);
}

void	Span::addNumber(unsigned int nbr)
{
	if (this->_vect.size() >= this->_maxSize)
		throw Span::SpanSizeExceededException();
	else
		this->_vect.push_back(nbr);
}

int	Span::shortestSpan()
{
	if (this->_vect.size() < 2)
		throw Span::OperationNotPossibleException();
	else
	{
		std::sort(this->_vect.begin(), this->_vect.end());
		int	minSpan = this->_vect[1] - this->_vect[0];
		for (unsigned int i = 2; i < this->_vect.size(); i++)
		{
			int	span = this->_vect[i] - this->_vect[i - 1];
			if (span < minSpan)
				minSpan = span;
		}
		return(minSpan);
	}
	return(-1);
}

int	Span::longestSpan()
{
	if (this->_vect.size() < 2)
		throw Span::OperationNotPossibleException();
	else
	{
		int max = *std::max_element(this->_vect.begin(), this->_vect.end());
		int min = *std::min_element(this->_vect.begin(), this->_vect.end());
		return(max - min);
	}
	return(-1);
}