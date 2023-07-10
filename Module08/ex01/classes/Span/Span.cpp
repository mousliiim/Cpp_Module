/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:18:01 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/10 02:16:11 by mmourdal         ###   ########.fr       */
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
		_size = src.getN();
		_array = src.getArray();
	}
	return (*this);
}

Span::~Span ( void ) { }

unsigned int Span::getN( void ) const
{
	return (_size);
}

std::multiset <int> Span::getArray( void ) const
{
	return (_array);
}

void Span::addNumber( int n )
{
	if (_array.size() == _size)
		throw std::out_of_range("Error :: Out of range");
	_array.insert(n);
}

void Span::addNumber( int n, int m )
{
	if (_array.size() + m > _size)
		throw std::out_of_range("Error :: Out of range");
	for (int i = 0; i < m; i++)
		_array.insert(n);
}

void Span::addNumber( it_ms begin, it_ms end )
{
	if (_array.size() + std::distance(begin, end) > _size)
		throw std::out_of_range("Error :: Out of range");
	_array.insert(begin, end);
}

void Span::displaySpan ( void )
{
	for (it_ms it = _array.begin(); it != _array.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int Span::shortestSpan( void )
{
	if (_array.size() <= 1)
		throw std::runtime_error("Error :: Array is empty or has only one element");
	
	int shortest = -1;
	for (it_ms it = _array.begin(); it != --_array.end(); it++)
	{
		it_ms it2 = it;
		it2++;
		if (shortest == -1 || *it2 - *it < shortest)
			shortest = *it2 - *it;
	}
	return (shortest);
}

int Span::longestSpan( void )
{
	if (_array.size() <= 1)
		throw std::runtime_error("Error :: Array is empty or has only one element");
	int min = *(_array.begin());
	int max = *(--_array.end());
	return (max - min);
}