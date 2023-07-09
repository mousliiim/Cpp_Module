/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:08:43 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/09 22:03:32 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main ( void )
{
	try
	{
		Span array(3);
		array.addNumber(45);
		array.addNumber(77);
		array.addNumber(52);
		array.displayArray();
	}
	catch ( std::exception &e )
	{
		std::cout << e.what() << std::endl;
	}
}