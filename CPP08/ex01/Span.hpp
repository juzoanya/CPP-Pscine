/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:19:13 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/10 22:30:24 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_vect;
	
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& src);
		~Span();

		Span& operator=(const Span& rhs);

		void	addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);

		void	addNumber(unsigned int nbr);
		int		shortestSpan();
		int		longestSpan();

		class SpanSizeExceededException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Span is full, size cannot be exceeded.");
				}
		};

		class OperationNotPossibleException : public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return("Operation not possible, size too small.");
			}
		};
};
