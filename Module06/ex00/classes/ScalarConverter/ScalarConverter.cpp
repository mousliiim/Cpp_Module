/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:22:15 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/22 19:43:19 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter ( void ) { std::cout << "ScalarConverter :: Constructor\n"; }

ScalarConverter::ScalarConverter ( std::string const &str )
{
	std::cout << "ScalarConverter :: Constructor\n";
	std::cout << "str = " << str << std::endl;
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
		this->_char = rhs._char;
		this->_int = rhs._int;
		this->_float = rhs._float;
		this->_double = rhs._double;
	}
	return (*this);
}