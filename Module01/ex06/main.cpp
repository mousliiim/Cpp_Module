/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:06:39 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/11 01:30:46 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << std::endl << RED << "You must pass one of the four severity levels as a parameter." << std::endl;
		std::cerr << "   | Level in order : Debug | Info | Warning | Error |" << RESET << std::endl << std::endl;
		return (0);
	}
	enum e_level {DEBUG, INFO, WARNING, ERROR};
	std::string level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (size_t i = 0; i < 4; i++)
	{
		if (level[i] == argv[1])
		{
			Harl harlfilter;
			harlfilter.setLevel(argv[1]);
			harlfilter.displayLevel();
			break ;
		}
	}
}