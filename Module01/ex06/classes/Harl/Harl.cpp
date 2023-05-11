/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:07:47 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/11 18:54:30 by mmourdal         ###   ########.fr       */
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

void Harl::displayLevel ( void )
{
	switch (this->_level)
	{
		case 1:
		{
			std::cout << "[ DEBUG ]" << std::endl;
			(this->*_tabFunc[0])();
			std::cout << std::endl << std::endl;
		}
		case 2:
		{
			std::cout << "[ INFO ]" << std::endl;
			(this->*_tabFunc[1])();
			std::cout << std::endl << std::endl;
		}
		case 3:
		{
			std::cout << "[ WARNING ]" << std::endl;
			(this->*_tabFunc[2])();
			std::cout << std::endl << std::endl;
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
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do !";
}

void Harl::info ( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !";
}

void Harl::warning ( void )
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month.";
}

void Harl::error ( void )
{
	std::cout << "This is unacceptable ! I want to speak to the manager now.";
}