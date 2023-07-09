/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:18:59 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/09 21:01:29 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	try
	{
		std::cout << std::endl << "Test with container vector contain 77, 75, 42, 17 | Search 42" << std::endl;
		std::vector <int> nb;
		nb.push_back(77);
		nb.push_back(75);
		nb.push_back(42);
		nb.push_back(17);
		easyfind(nb, 42);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Test with container list contain 77, 75, 42, 17 | Search 17" << std::endl;
		std::list <int> nb;
		nb.push_back(77);
		nb.push_back(75);
		nb.push_back(42);
		nb.push_back(17);
		easyfind(nb, 17);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Test with container vector contain 77, 75, 42, 17 | Search 0" << std::endl;
		std::vector <int> nb;
		nb.push_back(77);
		nb.push_back(75);
		nb.push_back(42);
		nb.push_back(17);
		easyfind(nb, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	try
	{
		std::cout << "Test with container list contain 77, 75, 42, 17 | Search 0" << std::endl;
		std::list <int> nb;
		nb.push_back(77);
		nb.push_back(75);
		nb.push_back(42);
		nb.push_back(17);
		easyfind(nb, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
}
