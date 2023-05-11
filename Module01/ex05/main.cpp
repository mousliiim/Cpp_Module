/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:06:39 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/11 18:56:15 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void )
{
	Harl test;
	std::cout << "Call method complain of Harl with argument \"WARNING\"" << std::endl;
	test.complain("WARNING");
	std::cout << std::endl << "Call method complain of Harl with argument \"ERROR\"" << std::endl;
	test.complain("ERROR");
	std::cout << std::endl << "Call method complain of Harl with argument \"INFO\"" << std::endl;
	test.complain("INFO");
	std::cout << std::endl << "Call method complain of Harl with argument \"DEBUG\"" << std::endl;
	test.complain("DEBUG");
	std::cout << std::endl << "Call method complain of Harl with argument \"RANDOM\"";
	std::cout << " (should not call any method)" << std::endl;
	test.complain("RANDOM");
}