/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:00:47 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/06 11:48:38 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <limits>
#include <string>
#include <iomanip>
#include <cmath>

class ScalarConverter
{
	private:
		
	
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter();

		ScalarConverter& operator=(const ScalarConverter& rhs);

		class NonPrintableChar : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class InvalidInput : public std::exception
		{
			public:
				const char* what() const throw();
		};

		static void		convert(const std::string& str);
		static void	_toChar(const std::string& str);
		static void	_toInt(const std::string& str);
		static void	_toDouble(const std::string& str);
		static void	_toFloat(const std::string& str);
};
