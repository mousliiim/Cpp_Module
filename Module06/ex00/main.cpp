/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:39 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/24 18:46:17 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main ( int argc, char **argv )
{
	if (argc == 2)
		ScalarConverter test (argv[1]);
	else
		std::cout << "ScalarConverter :: Need 1 Argument for this program\n";
}