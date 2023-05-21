/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 00:21:59 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/21 23:16:06 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	public:
		Fixed ( void );
		Fixed ( const Fixed &src );
		Fixed ( const int nb );
		Fixed ( const float nb );
		~Fixed ( void );

        Fixed &operator=(const Fixed &fix);
        Fixed &operator+(const Fixed &rhs);
        Fixed &operator-(const Fixed &rhs);
        Fixed &operator*(const Fixed &rhs);
        Fixed &operator/(const Fixed &rhs);

		bool	operator>(const Fixed &fix);
		bool	operator<(const Fixed &fix);
		bool	operator>=(const Fixed &fix);
		bool	operator<=(const Fixed &fix);
		bool	operator==(const Fixed &fix);
		bool	operator!=(const Fixed &fix);

		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float 	toFloat( void ) const;
		int 	toInt( void ) const;
		static Fixed	&min(Fixed &a, Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
	private:
		int _nb;
		static const int _bits = 8;
};

std::ostream	&operator<<( std::ostream &out, const Fixed &fix );

#endif