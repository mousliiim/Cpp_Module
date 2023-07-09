/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:20:25 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/09 21:01:11 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <list>

class NoFindOccurrence: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Error :: No occurence found !");
		}
};

template <typename T>
void easyfind (T &container, int number)
{
	if (std::find(container.begin(), container.end(), number) == container.end())
		throw NoFindOccurrence();
	else
		std::cout << "Occurence : " << number << " found !" << std::endl; 
}

#endif