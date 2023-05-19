/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 00:19:34 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/19 22:25:27 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b;

	b.setRawBits(5);
	std::cout << "b = " << b.getRawBits() << std::endl;
	a.setRawBits(5);
	std::cout << "a = " << a.getRawBits() << std::endl;
	std::cout << "Result = " << a + b << std::endl;
	return (0);
}