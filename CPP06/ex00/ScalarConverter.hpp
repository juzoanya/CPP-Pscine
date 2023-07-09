/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:00:47 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/08 16:49:46 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <limits.h>
#include <float.h>
#include <string>
#include <iomanip>
#include <cmath>

class ScalarConverter
{
	private:
		static char	_sign;
		static char	_type;
	
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

		static void	convert(const std::string& str);
		static void	toChar(const std::string& str, const long long& nbr);
		static void	toInt(const std::string& str, const long long& nbr);
		static void	toDouble(const std::string& str, const long long& nbr);
		static void	toFloat(const std::string& str, const long long& nbr);
};
