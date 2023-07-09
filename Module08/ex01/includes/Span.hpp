/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:57:34 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/09 22:15:07 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <list>

typedef std::vector <int>::iterator it_v;

class Span
{
	public:
		Span ( void );
		Span ( const unsigned int N );
		Span ( const Span &src );
		Span &operator= ( const Span &src );
		~Span ( void );
		unsigned int getN( void ) const;
		std::vector <int> getArray( void ) const;
		void addNumber( int n );
		void displayArray ( void );
		int shortestSpan( void );
		int longestSpan( void );

	private:
		unsigned int _size;
		std::vector <int> _array;
};

#endif