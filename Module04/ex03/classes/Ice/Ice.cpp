/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 00:31:28 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/30 20:58:06 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice :: Default constructor called\n";
}

Ice::~Ice() { std::cout << "Ice :: Destructor called\n"; }

Ice::Ice(const Ice &src) : AMateria("ice")
{
	(void)src;
}

Ice &Ice::operator=(const Ice &src)
{
	(void)src;
	return (*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

AMateria *Ice::clone() const
{
	return (new Ice());
}