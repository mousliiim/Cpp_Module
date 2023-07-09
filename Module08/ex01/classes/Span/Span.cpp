/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:18:01 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/09 22:18:54 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Span.hpp"

Span::Span ( void ) { }

Span::Span ( const unsigned int N ) : _size(N) { }

Span::Span ( const Span &src )
{
	*this = src;
}

Span &Span::operator= ( const Span &src )
{
	if (this != &src)
	{
		_size = src._size;
		_array = src._array;
	}
	return (*this);
}

Span::~Span ( void ) { }

unsigned int Span::getN( void ) const
{
	return (_size);
}

std::vector <int> Span::getArray( void ) const
{
	return (_array);
}

void Span::addNumber( int n )
{
	if (_array.size() == _size)
		throw std::out_of_range("Error :: Array is full");
	_array.push_back(n);
}

void Span::displayArray ( void )
{
	for (it_v it = _array.begin(); it != _array.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int Span::shortestSpan( void )
{
	if (_array.size() <= 1)
		throw std::out_of_range("Error :: Array is empty or has only one element");
}

int Span::longestSpan( void )
{
	if (_array.size() <= 1)
		throw std::out_of_range("Error :: Array is empty or has only one element");
}