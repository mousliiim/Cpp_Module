/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:57:34 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/10 02:15:14 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <set>

typedef std::multiset<int>::iterator it_ms;

class Span
{
	public:
		Span ( void );
		Span ( const unsigned int N );
		Span ( const Span &src );
		Span &operator= ( const Span &src );
		~Span ( void );

		void addNumber( int n );
		void addNumber( int n, int m );
		void addNumber( it_ms begin, it_ms end );
		void displaySpan ( void );
		int shortestSpan( void );
		int longestSpan( void );
		unsigned int getN( void ) const;
		std::multiset <int> getArray( void ) const;

	private:
		unsigned int _size;
		std::multiset <int> _array;
};

#endif