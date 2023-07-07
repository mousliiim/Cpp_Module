/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:51:02 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/07 21:15:30 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{
	float a = 5.5;
	float b = 10.5;
	int c = 42;
	int d = 43;
	char e = '$';
	char f = '*';
	std::string g = "hello";
	std::string h = "world";
	int i = 42;
	int j = 42;

	std::cout << "\n****** START VALUE ******\n";
	std::cout << "a = " << a << " b = " << b << std::endl;
	std::cout << "c = " << c << " d = " << d << std::endl;
	std::cout << "e = " << e << " f = " << f << std::endl;
	std::cout << "g = " << g << " h = " << h << std::endl;
	std::cout << "**************************\n\n";

	std::cout << "****** SWAP TEST ******\n";
	std::cout << "swap(a, b)" << std::endl;
	swap(a, b);
	std::cout << "a = " << a << " b = " << b << std::endl;
	std::cout << "swap(c, d)" << std::endl;
	swap(c, d);
	std::cout << "c = " << c << " d = " << d << std::endl;
	std::cout << "swap(e, f)" << std::endl;
	swap(e, f);
	std::cout << "e = " << e << " f = " << f << std::endl;
	std::cout << "swap(g, h)" << std::endl;
	swap(g, h);
	std::cout << "g = " << g << " h = " << h << std::endl;
	std::cout << "***********************\n\n";

	std::cout << "****** MIN MAX TEST ******\n";
	std::cout << "min(a, b) = " << min(a, b) << std::endl;
	std::cout << "min(c, d) = " << min(c, d) << std::endl;
	std::cout << "min(e, f) = " << min(e, f) << std::endl;
	std::cout << "min(g, h) = " << min(g, h) << std::endl;
	std::cout << "min(i, j) = " << min(i, j) << std::endl;

	std::cout << "max(a, b) = " << max(a, b) << std::endl;
	std::cout << "max(c, d) = " << max(c, d) << std::endl;
	std::cout << "max(e, f) = " << max(e, f) << std::endl;
	std::cout << "max(g, h) = " << max(g, h) << std::endl;
	std::cout << "max(i, j) = " << max(i, j) << std::endl;
	std::cout << "**************************\n";
}