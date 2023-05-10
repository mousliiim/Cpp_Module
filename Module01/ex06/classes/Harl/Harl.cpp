/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:07:47 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/11 01:35:03 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl ( void ) 
{
	_tabFunc[0] = &Harl::debug;
	_name[0] = "DEBUG";
	_tabFunc[1] = &Harl::info;
	_name[1] = "INFO";
	_tabFunc[2] = &Harl::warning;
	_name[2] = "WARNING";
	_tabFunc[3] = &Harl::error;
	_name[3] = "ERROR";
}

void Harl::setLevel ( std::string level )
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_name[i] == level)
		{
			this->_level = i + 1;
			break ;
		}
	}
}

void Harl::complain ( std::string level )
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_name[i] == level)
		{
			(this->*_tabFunc[i])();
			break ;
		}
	}
}

void Harl::displayLevel ( void )
{
	switch (this->_level)
	{
		case 1:
		{
			std::cout << "[ DEBUG ]" << std::endl;
			(this->*_tabFunc[0])();
			std::cout << std::endl;
		}
		case 2:
		{
			std::cout << "[ INFO ]" << std::endl;
			(this->*_tabFunc[1])();
			std::cout << std::endl;
		}
		case 3:
		{
			std::cout << "[ WARNING ]" << std::endl;
			(this->*_tabFunc[2])();
			std::cout << std::endl;
		}
		case 4:
		{
			std::cout << "[ ERROR ]" << std::endl;
			(this->*_tabFunc[3])();
			std::cout << std::endl;
		}
		default:
			std::cout << std::endl;
			break ;
	}
}


void Harl::debug ( void )
{
	std::cout << "You called the function debug()";
}

void Harl::info ( void )
{
	std::cout << "You called the function info()";
}

void Harl::warning ( void )
{
	std::cout << "You called the function warning()";
}

void Harl::error ( void )
{
	std::cout << "You called the function error()";
}