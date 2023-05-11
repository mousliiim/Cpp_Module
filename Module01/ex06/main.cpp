/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:06:39 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/11 18:51:39 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << std::endl << RED << "You must pass only one of the four severity levels as a parameter." << std::endl;
		std::cerr << "   | Level in order : DEBUG | INFO | WARNING | ERROR |" << RESET << std::endl << std::endl;
		return (1);
	}
	std::string level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	bool found = false;
	for (size_t i = 0; argv[1][i]; i++)
		argv[1][i] = toupper(argv[1][i]);
	for (size_t i = 0; i < 4; i++)
	{
		if (level[i] == argv[1])
		{
			found = true;
			Harl harlfilter;
			harlfilter.setLevel(argv[1]);
			harlfilter.displayLevel();
			break ;
		}
	}
	if (!found)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return (0);
}