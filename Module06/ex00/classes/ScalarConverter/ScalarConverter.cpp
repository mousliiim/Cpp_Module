/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:22:15 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/27 02:05:21 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter ( void ) { std::cout << "ScalarConverter :: Constructor\n"; }

ScalarConverter::ScalarConverter ( std::string const &str )
{
	std::cout << "ScalarConverter :: Constructor\n";
	std::cout << "str = " << str << std::endl;
	this->_str = str;
	std::cout << "type : " << this->determineType() << std::endl;
}

ScalarConverter::~ScalarConverter ( void ) { std::cout << "ScalarConverter :: Destructor\n"; }

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
    
	if (*fin == '\0' && this->_str.size() > 0 && nb >= INT_MIN && nb <= INT_MAX)
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
		return T_INT;
	if (isDouble())
		return T_DOUBLE;
	if (isChar())
		return T_CHAR;
	if (isFloat())
		return T_FLOAT;
	// CHECK NANF AND INFF WITH - AND +
	return T_ERROR;
}