/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:15:41 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/11 04:33:20 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << WHITE_B << "Error :: " << RESET << "Wrong number of arguments, usage : ./btc [file]" << std::endl;
		return (1);
	}
	else 
	{
		try
		{
			BitcoinExchange A(argv[1]);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}