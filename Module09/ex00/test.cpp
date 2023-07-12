/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:36:15 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/12 18:53:04 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map>

int main ( void )
{
	std::map<std::string, double> map;
	map["Mouss"] = 42;
	map["Mouss2"] = 43;
	map["Mouss3"] = 44;
	map["Mouss6"] = 45;
	map["Mouss5"] = 46;

	std::string str = "Mouss4";
	if (map.find(str) == map.end())
	{
		std::map<std::string, double>::iterator map_it = map.begin();
		std::string tmp = map_it->first;
		for (; map_it != map.end(); map_it++)
		{
			if (map_it->first > tmp && map_it->first < str)
				tmp = map_it->first;
		}
		std::cout << tmp << std::endl;
	}
	else
		std::cout << map.find(str)->first << std::endl;
	return (0);
}