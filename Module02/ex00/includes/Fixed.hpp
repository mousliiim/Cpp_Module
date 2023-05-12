/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 00:21:59 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/13 01:26:14 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	public:
		Fixed ( void );
		Fixed ( const Fixed &src );
		~Fixed ( void );
		
		Fixed	&operator=(const Fixed& fix);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	private:
		int _nb;
		static const int _bits = 8;
};

#endif