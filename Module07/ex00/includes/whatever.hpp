/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:51:29 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/07 21:10:50 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <string>
#include <iostream>
#include <cstdlib>

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T &a, T &b)
{
	if ( a == b )
		return b;
	T min;
	a < b ? min = a : min = b;
	return min;
}

template <typename T>
T max(T &a, T &b)
{
	if ( a == b )
		return b;
	T max;
	a > b ? max = a : max = b;
	return max;
}

#endif