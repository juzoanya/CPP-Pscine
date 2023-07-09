/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:00:41 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/09 18:32:17 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char	ScalarConverter::_type;
char	ScalarConverter::_sign;

ScalarConverter::ScalarConverter()
{};

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	(void)src;
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
	(void)rhs;
	return (*this);
}

void	ScalarConverter::toChar(const std::string& str, const long long& nbr)
{
	char	cValue;

	if (ScalarConverter::_type == 'c')
	{
		cValue = static_cast<char>(str[0]);
		if (str.size() == 1 && isprint(cValue))
			std::cout << "char: '" << cValue << "'" << std::endl;
		else if (cValue == '0')
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else if (ScalarConverter::_type == 'i' || ScalarConverter::_type == 'd' || ScalarConverter::_type == 'f')
	{
		if (nbr >= 1 && nbr <= 256)
		{
			cValue = static_cast<char>(std::floor(nbr));
			if (isprint(cValue))
				std::cout << "char: '" << cValue << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
			return;
		}
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
}

void	ScalarConverter::toInt(const std::string& str, const long long& nbr)
{
	int	iValue;
	std::istringstream	iss(str);

	if (ScalarConverter::_type == 'c')
	{
		iValue = static_cast<int>(str[0]);
		
		std::cout << "int: " << iValue << std::endl;
	}
	else if (nbr >= INT_MIN && nbr <= INT_MAX)
	{
		iValue = static_cast<int>(nbr);
		std::cout << "int: " << iValue << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;
}

void	ScalarConverter::toDouble(const std::string& str, const long long& nbr)
{
	double	dValue;

	if (ScalarConverter::_type == 'c')
	{
		dValue = static_cast<double>(str[0]);
		std::cout << "double: " << std::fixed << std::setprecision(1) << dValue << std::endl;
	}
	else if (nbr >= DBL_MIN && nbr <= DBL_MAX)
	{
		dValue = static_cast<double>(nbr);
		std::cout << "double: " << std::fixed << std::setprecision(1) << dValue << std::endl;
	}
	else
		std::cout << "double: impossible" << std::endl;
}

void	ScalarConverter::toFloat(const std::string& str, const long long& nbr)
{
	float	fValue;

	if (ScalarConverter::_type == 'c')
	{
		fValue = static_cast<float>(str[0]);
		std::cout << "float: " << std::fixed << std::setprecision(1) << fValue << "f" << std::endl;
	}
	else if (nbr >= FLT_MIN && nbr <= FLT_MAX)
	{
		fValue = static_cast<float>(nbr);
		std::cout << "float: " << std::fixed << std::setprecision(1) << fValue << "f" << std::endl;

	}
	else
		std::cout << "float: impossible" << std::endl;
}

void	pseudoConvert(const std::string& str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "nan" || str == "+inf" || str == "-inf")
	{
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
	else
	{
		std::cout << "float: " << str << std::endl;
		std::string popedStr = str.substr(0, str.size() - 1);
		std::cout << "double: " << popedStr << std::endl;
	}
}

bool	checkDigits(const std::string& str)
{
	int	trueCase = 0;
	
	for (int i = 0; i < static_cast<int>(str.size()); i++)
	{
		if (isdigit(str[i]))
			trueCase++;
	}
	if (trueCase == static_cast<int>(str.size()))
		return(true);
	return(false);
}

char	checkType(const std::string& str)
{
	int	size = str.size();

	if (size == 1 && isascii(str[0]))
		return('c');
	else if (size == 2 && str[0] == '\\')
		return('c');
	else if (size > 1 && checkDigits(str))
		return('i');
	else if (size > 1 && (str.find('.') != std::string::npos))
	{
		if (str.find('f') != std::string::npos)
			return('f');
		else
			return('d');
	}
	else if (str == "nan" || str == "nanf" || str == "-inf" || str == "-inff" || str == "+inf" || str == "+inff")
		return('p');
	return('u');
}

void	ScalarConverter::convert(const std::string& str)
{
	long long	nbr = 0;

	ScalarConverter::_type = checkType(str);
	std::cout << "--------" << str << "--------" << std::endl;
	std::cout << "--------" << ScalarConverter::_type << "--------" << std::endl;
	std::cout << str.size() << std::endl;
	if (str.empty() || ScalarConverter::_type == 'u')
	{
		throw ScalarConverter::InvalidInput();
		return;
	}
	if (ScalarConverter::_type == 'i' || ScalarConverter::_type == 'd' || ScalarConverter::_type == 'f')
	{
		std::stringstream	iss(str);
		iss >> nbr;
	}
	if (ScalarConverter::_type == 'p')
	{
		pseudoConvert(str);
		return;
	}
	ScalarConverter::toChar(str, nbr);
	ScalarConverter::toInt(str, nbr);
	ScalarConverter::toFloat(str, nbr);
	ScalarConverter::toDouble(str, nbr);
	
}

const char*	ScalarConverter::InvalidInput::what() const throw()
{
	return("Invalid Input");
}

const char* ScalarConverter::NonPrintableChar::what() const throw()
{
	return ("char: Non displayable");
}