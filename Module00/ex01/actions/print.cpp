/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:10:50 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/03 02:03:56 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

void PrintProgramStart(void)
{
	std::cout << std::endl;
	std::cout << RED << "+-------------------------------+" << RESET << std::endl;
	std::cout << RED << "|" << RESET << "    Welcome to PhoneBook 📞    " << RED << "|" << RESET << std::endl;
	std::cout << RED << "+-------------------------------+" << RESET << std::endl;
	std::cout << RED << "|" << RESET << "     Available commands :      " << RED << "|" << RESET << std::endl;
	std::cout << RED << "|" << RESET << "  ADD (FOR ADD NEW CONTACT)    " << RED << "|" << RESET << std::endl;
	std::cout << RED << "|" << RESET << "   SEARCH (SEARCH CONTACT)     " << RED << "|" << RESET << std::endl;
	std::cout << RED << "|" << RESET << "    EXIT (EXIT PROGRAMM)       " << RED << "|" << RESET << std::endl;
	std::cout << RED << "+-------------------------------+" << RESET << std::endl;
	std::cout << std::endl;
}