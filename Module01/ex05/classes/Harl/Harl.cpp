/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:07:47 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/11 00:25:16 by mmourdal         ###   ########.fr       */
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

void Harl::debug ( void )
{
	std::cout << "You called the function debug()" << std::endl;
}

void Harl::info ( void )
{
	std::cout << "You called the function info()" << std::endl;
}

void Harl::warning ( void )
{
	std::cout << "You called the function warning()" << std::endl;
}

void Harl::error ( void )
{
	std::cout << "You called the function error()" << std::endl;
}