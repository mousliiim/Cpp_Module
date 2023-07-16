/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 02:50:54 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/16 20:41:36 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main ( int argc, char **argv )
{
	try
	{
		argc > 2 ? (parsingArgument(argv, argc) ? ERROR_ALREADY_SORTED : true ) : ERROR_NB_ARGS;
		PmergeMe sortMe(argv);
	}
	catch ( std::exception &error )
	{
		std::cout << error.what() << std::endl;
	}
}