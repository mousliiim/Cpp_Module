/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:22:15 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/28 18:55:12 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter ( void ) { }

ScalarConverter::ScalarConverter ( std::string const &str )
{
	this->_str = str;
	if (_str == "nanf" || _str == "nan" || _str == "inff" || _str == "inf" || _str == "+inff" || _str == "+inf" || _str == "-inff" || _str == "-inf")
	{
		this->printSpecial();
		return ;
	}
	this->_originalType = determineType();
	if (this->_originalType != IMPOSSIBLE)
		this->convert(str);
	else
		this->convert("impossible");
}

void ScalarConverter::printSpecial ( void )
{
	if (_str == "nanf" || _str == "nan")
	{
		std::cout << "char : impossible\n";
		std::cout << "int : impossible\n";
		std::cout << "float : nanf\n";
		std::cout << "double : nan\n";
	}
	else if (_str == "inff" || _str == "inf")
	{
		std::cout << "char : impossible\n";
		std::cout << "int : impossible\n";
		std::cout << "float : inff\n";
		std::cout << "double : inf\n";
	}
	else if (_str == "+inff" || _str == "+inf")
	{
		std::cout << "char : impossible\n";
		std::cout << "int : impossible\n";
		std::cout << "float : +inff\n";
		std::cout << "double : +inf\n";
	}
	else if (_str == "-inff" || _str == "-inf")
	{
		std::cout << "char : impossible\n";
		std::cout << "int : impossible\n";
		std::cout << "float : -inff\n";
		std::cout << "double : -inf\n";
	}
}

ScalarConverter::~ScalarConverter ( void ) { }

ScalarConverter::ScalarConverter ( ScalarConverter const &src )
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator= (ScalarConverter const &rhs)
{
	if (this != &rhs)
	{
		this->_str = rhs._str;
		this->_originalType = rhs._originalType;
	}
	return (*this);
}

bool ScalarConverter::isInt ( void )
{
    char *fin;
	long nb = std::strtol(this->_str.c_str(), &fin, 10);
	
	if (nb >= INT_MIN && nb <= INT_MAX)
		this->_overflow = false;
	else
		this->_overflow = true;
	if (*fin == '\0' && this->_str.size() > 0)
		return true;
	return false;
}

bool ScalarConverter::isDouble ( void )
{
	char* fin;
	const char *point = std::strchr(this->_str.c_str(), '.');
	int start = (this->_str[0] == '+' || this->_str[0] == '-') ? 1 : 0;

	std::strtod(this->_str.c_str(), &fin);
    if (*fin == '\0' && point != NULL && std::isdigit(this->_str[start]))
	{
		if (point != NULL && std::isdigit(*(point + 1)) && this->_str.size() > 1)
			return true;
	}
	return false;
}

bool ScalarConverter::isChar ( void )
{
	if (this->_str.size() == 1)
		return true;
	return false;
}

bool ScalarConverter::isFloat ( void )
{
	int start = (this->_str[0] == '+' || this->_str[0] == '-') ? 1 : 0;
	const char *point = std::strchr(this->_str.c_str(), '.');
	size_t pos = this->_str.find('.');

	if (point == NULL && this->_str.size() > 1 && std::isdigit(this->_str[start]) && this->_str[this->_str.size() - 1] == 'f')
		return true;
	else if (point != NULL && this->_str.size() > 1 && std::isdigit(this->_str[start]) && this->_str[this->_str.size() - 1] == 'f')
	{
		if (std::isdigit(*(point + 1)) && this->_str.find_first_not_of("0123456789f", pos + 1) == std::string::npos)
			return true;
		else
			return false;
	}
	return false;
}

short ScalarConverter::determineType ( void )
{
	if (isInt())
		return INT;
	if (isDouble())
		return DOUBLE;
	if (isChar())
		return CHAR;
	if (isFloat())
		return FLOAT;
	return IMPOSSIBLE;
}

void ScalarConverter::convert(std::string const &literal )
{
	if (literal == "impossible")
	{
		std::cout << "char : impossible\n";
		std::cout << "int : impossible\n";
		std::cout << "float : impossible\n";
		std::cout << "double : impossible\n";
		return ;
	}
	else
	{
		if (this->_originalType == CHAR)
			this->convertChar();
		else if (this->_originalType == INT)
			this->convertInt();
		else if (this->_originalType == FLOAT)
			this->convertFloat();
		else if (this->_originalType == DOUBLE)
			this->convertDouble();
	}
}

void ScalarConverter::convertChar ( void )
{
	char c = this->_str[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	std::cout << "char : '" << c << "'\n";
	std::cout << "int : " << i << "\n";
	std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f\n";
	std::cout << "double : " << std::fixed << std::setprecision(1) << d << "\n";
}

void ScalarConverter::convertInt ( void )
{
	double i = std::atol(this->_str.c_str());
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	std::cout << "char : ";
	if (std::isprint(c))
		std::cout << "'" << c << "'\n";
	else
		std::cout << "Non displayable\n";
	if (this->_overflow == false)
		std::cout << "int : " << i << "\n";
	else
		std::cout << "int : impossible\n";
	std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f\n";
	std::cout << "double : " << std::fixed << std::setprecision(1) << d << "\n";
}

void ScalarConverter::convertFloat ( void )
{
	float f = std::atof(this->_str.c_str());
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	std::cout << "char : ";
	if (std::isprint(c))
		std::cout << "'" << c << "'\n";
	else
		std::cout << "Non displayable\n";
	std::cout << "int : ";
	if (this->_overflow == false)
		std::cout << i << "\n";
	else
		std::cout << "impossible\n";
	std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f\n";
	std::cout << "double : " << std::fixed << std::setprecision(1) << d << "\n";
}

void ScalarConverter::convertDouble ( void )
{
	double d = std::atof(this->_str.c_str());
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	std::cout << "char : ";
	if (d >= 0 && d <= 127)
		std::cout << "'" << c << "'\n";
	else
		std::cout << "Non displayable\n";
	std::cout << "int : ";
	if (this->_overflow == false)
		std::cout << i << "\n";
	else
		std::cout << "impossible\n";
	std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f\n";
	std::cout << "double : " << std::fixed << std::setprecision(1) << d << "\n";
}