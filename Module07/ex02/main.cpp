/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:51:02 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/07 23:18:21 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	try
	{
		std::cout << std::endl << "Array of 5 int";
		Array<int> a(5);
		std::cout << std::endl << "Before : " << a << std::endl;
		a[0] = 1;
		a[1] = 2;
		a[2] = 3;
		a[3] = 4;
		a[4] = 5;
		std::cout << "After : " << a << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Array<float> a(5);
		std::cout << std::endl << "Array of 5 float";
		std::cout << std::endl << "Before : " << a << std::endl;
		a[0] = 1.1;
		a[1] = 2.2;
		a[2] = 3.3;
		a[3] = 4.4;
		a[4] = 5.5;
		std::cout << "After : " << a << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Array<std::string> a(5);
		std::cout << std::endl << "Array of 5 string (test with out of limits)";
		std::cout << std::endl << "Before : " << a << std::endl;
		a[0] = "ab";
		a[1] = "cd";
		a[2] = "ef";
		a[3] = "gh";
		a[4] = "ij";
		a[5] = "kl"; // out of limits
		std::cout << "After : " << a << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	return 0;
}