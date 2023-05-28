/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 00:31:30 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/28 02:10:35 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure :: Default constructor called\n";
}

Cure::~Cure() { std::cout << "Cure :: Destructor called\n"; }

Cure::Cure(const Cure &src) : AMateria("cure")
{
	std::cout << "Cure :: Copy constructor called\n";
	(void)src;
}

Cure &Cure::operator=(const Cure &src)
{
	std::cout << "Cure :: Assignation operator called\n";
	(void)src;
	return (*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}

AMateria *Cure::clone() const
{
	return (new Cure());
}