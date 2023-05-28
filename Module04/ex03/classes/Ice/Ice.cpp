/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 00:31:28 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/28 02:18:21 by mmourdal         ###   ########.fr       */
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
	std::cout << "Ice :: Copy constructor called\n";
	(void)src;
}

Ice &Ice::operator=(const Ice &src)
{
	std::cout << "Ice :: Assignation operator called\n";
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