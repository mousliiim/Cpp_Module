/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:22:08 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/19 22:26:55 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed ( void ): _nb(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( const Fixed &src )
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator = ( src );
}

Fixed::Fixed ( const int nb )
{
	std::cout << "Int constructor called" << std::endl;
	this->_nb = nb << this->_bits;
}

Fixed::Fixed ( const float nb )
{
	std::cout << "Float constructor called" << std::endl;
	this->_nb = roundf(nb * (1 << this->_bits));
}

Fixed::~Fixed ( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=( const Fixed& fix )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_nb = fix.getRawBits();
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
	return (this->_nb);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_nb = raw;
}

float 	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_nb) / (1 << this->_bits));
}

int 	Fixed::toInt( void ) const
{
	return (this->_nb >> this->_bits);
}

std::ostream	&operator<<( std::ostream &out, const Fixed &fix )
{
	out << fix.toFloat();
	return (out);
}

Fixed	Fixed::operator+(const Fixed &fix) const
{
	Fixed tmp;
	tmp.setRawBits(this->_nb + fix.getRawBits());
	return (tmp);
}
