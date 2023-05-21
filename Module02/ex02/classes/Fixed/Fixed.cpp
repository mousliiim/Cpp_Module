/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:22:08 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/21 23:42:50 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed ( void ): _nb(0) {}

Fixed::Fixed ( const Fixed &src )
{
	this->operator = ( src );
}

Fixed::Fixed ( const int nb )
{
	this->_nb = nb << this->_bits;
}

Fixed::Fixed ( const float nb )
{
	this->_nb = roundf(nb * (1 << this->_bits));
}

Fixed::~Fixed ( void ) {}

Fixed	&Fixed::operator=( const Fixed& fix )
{
	this->_nb = fix.getRawBits();
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
	return (this->_nb);
}

void	Fixed::setRawBits( int const raw )
{
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

// Operators arithmetic

Fixed	&Fixed::operator+(const Fixed &fix)
{
	this->_nb += fix.getRawBits();
	return (*this);
}

Fixed	&Fixed::operator-(const Fixed &fix)
{
	this->_nb -= fix.getRawBits();
	return (*this);
}

Fixed	&Fixed::operator*(const Fixed &fix)
{
    this->_nb = (this->_nb * fix.getRawBits()) >> _bits;
    return (*this);
}

Fixed	&Fixed::operator/(const Fixed &fix)
{
	this->_nb =  (this->_nb << this->_bits) / fix.getRawBits();
    return (*this);
}

// Operators comparison

bool	Fixed::operator>(const Fixed &fix)
{
	return (this->_nb > fix.getRawBits());
}

bool	Fixed::operator<(const Fixed &fix)
{
	return (this->_nb < fix.getRawBits());
}

bool	Fixed::operator>=(const Fixed &fix)
{
	return (this->_nb >= fix.getRawBits());
}

bool	Fixed::operator<=(const Fixed &fix)
{
	return (this->_nb <= fix.getRawBits());
}

bool	Fixed::operator==(const Fixed &fix)
{
	return (this->_nb == fix.getRawBits());
}

bool	Fixed::operator!=(const Fixed &fix)
{
	return (this->_nb != fix.getRawBits());
}

// Operators incrementation

Fixed	&Fixed::operator++(void)
{
	this->_nb++;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->_nb--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

// Min Max

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
