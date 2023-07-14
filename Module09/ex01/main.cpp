/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:41:28 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/14 02:08:54 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main ( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cerr << WHITE_BOLD << "Error ::" << RESET << " correct usage : ./RPN \"expression\"" << std::endl;
		return ERROR;
	}
	else
	{
		try
		{
			RPN rpn(argv[1]);
		}
		catch ( std::exception &e )
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (SUCCESS);
}