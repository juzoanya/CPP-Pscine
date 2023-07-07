/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:00:41 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/07 12:46:03 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

void	ScalarConverter::_toChar(const std::string& str)
{
	if (str.size() == 3 && (str.at(0) == '\'' && str.at(str.length() - 1) == '\''))
	{
		char	cValue = str[1];
		std::cout << "char: " << cValue << std::endl;
	}
	else if (str.size() == 1)
	{
		char	cValue = str[0];
		if (!isprint(cValue))
			throw ScalarConverter::NonPrintableChar();
		else if (!isdigit(cValue))
			std::cout << "char: " << cValue << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	char cValue = str[0];
	std::cout << static_cast<int>(cValue) << std::endl;
}

void	ScalarConverter::_toInt(const std::string& str)
{
	int	iValue;
	std::istringstream	iss(str);

	if (iss >> iValue)
		std::cout << "int: " << iValue << std::endl;
	else
		std::cerr << "int: impossible" << std::endl;
}

void	ScalarConverter::_toDouble(const std::string& str)
{
	long	lValue;
	double	dValue;
	std::stringstream	iss(str);

	iss >> lValue;
	dValue = static_cast<double>(lValue);
	std::cout << "long: " << lValue << std::endl;
	// if (iss >> dValue)
	// {
	// 	if (dValue == std::floor(dValue))
	// 	{
	// 		std::cout << "F-double: " << dValue << std::endl;
	// 		std::ostringstream	oss;
	// 		oss << std::fixed << std::setprecision(1) << dValue;
	// 		std::string appendValue = oss.str();
	// 		std::istringstream	appendIss(appendValue);
	// 		appendIss >> dValue;
	// 	}
		std::cout << "double: " << dValue << std::endl;
	// }
	// else
	//	std::cerr << "double: impossible" << std::endl;
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

void	ScalarConverter::convert(const std::string& str)
{
	double			lValue;
	//bool			allDigit = false;
	std::stringstream	iss(str);

	lValue = 3456789023;
	if (str.empty() || !checkDigits(str))
	{
		throw ScalarConverter::InvalidInput();
		return;
	}
	//std::cout << checkDigits(str) << std::endl;
	std::cout << lValue << std::endl;
	// double tryD = std::stod(str);
	// std::cout << tryD << std::endl;
	std::cout << "try: " << static_cast<double>(lValue) << std::endl;
	ScalarConverter::_toChar(str);
	ScalarConverter::_toInt(str);
	ScalarConverter::_toDouble(str);
	// ScalarConverter::_toFloat(str);
	
}

const char*	ScalarConverter::InvalidInput::what() const throw()
{
	return("Invalid Input");
}

const char* ScalarConverter::NonPrintableChar::what() const throw()
{
	return ("char: Non displayable");
}

/*
class ScalarConverter {
public:
	static void convert(const std::string& literal) {
		if (literal.empty()) {
			std::cout << "Invalid literal." << std::endl;
			return;
		}

		char firstChar = literal[0];

		if (literal.length() == 1) {
			if (isPrintableChar(firstChar)) {
				std::cout << "char: " << firstChar << std::endl;
				return;
			}
			else {
				std::cout << "Invalid char literal." << std::endl;
				return;
			}
		}

		std::istringstream iss(literal);

		if (firstChar == '\'' && literal[literal.length() - 1] == '\'') {
			char charLiteral;
			iss >> std::noskipws >> charLiteral;
			std::cout << "char: " << charLiteral << std::endl;
		}
		else if (literal.find_first_of("f") != std::string::npos) {
			float floatLiteral;
			iss >> floatLiteral;
			if (std::isnan(floatLiteral) || std::isinf(floatLiteral)) {
				std::cout << "float: " << floatLiteral << std::endl;
			}
			else {
				std::cout << "float: " << std::fixed << floatLiteral << std::endl;
			}
		}
		else {
			double doubleLiteral;
			iss >> doubleLiteral;
			if (std::isnan(doubleLiteral) || std::isinf(doubleLiteral)) {
				std::cout << "double: " << doubleLiteral << std::endl;
			}
			else {
				std::cout << "double: " << std::fixed << doubleLiteral << std::endl;
			}
		}
	}

private:
	static bool isPrintableChar(char c) {
		return c >= 32 && c <= 126;
	}
};

int main() {
	ScalarConverter::convert("'c'");
	ScalarConverter::convert("42");
	ScalarConverter::convert("-4.2f");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("nan");
	
	return 0;
}*/