/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 00:31:32 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/28 01:44:50 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria ( void ) { std::cout << "AMateria :: Default constructor called\n"; }

AMateria::AMateria ( std::string const &type ) : _type(type) { std::cout << "AMateria :: Constructor called\n"; };

AMateria::~AMateria ( void ) { std::cout << "AMateria :: Destructor called"; }

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria :: use called but action toward " << target.getName() << " is not defined\n";
}
