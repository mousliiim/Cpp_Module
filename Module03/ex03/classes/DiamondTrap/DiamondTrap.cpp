/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:01:58 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/25 00:24:19 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap( void ) : FragTrap(), ScavTrap()
{
	this->_name = "Default name";
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	this->_hitPoints = 100;
	std::cout << "DiamondTrap :: Default Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap( const std::string &name ) : ClapTrap(name + "_clap_name"), FragTrap(name + "_frag_name"), ScavTrap(name + "_scav_trap")
{
	this->_name = name;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	this->_hitPoints = 100;
	std::cout << "DiamondTrap :: Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &src )
{
	*this = src;
	std::cout << "DiamondTrap :: Copy Constructor Called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap :: Destructor Called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &DiamondTrap::operator=( DiamondTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
		std::cout << "DiamondTrap :: Assignement constructor Called" << std::endl;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	DiamondTrap::getNameDt ( void )
{
	return (this->_name);
}

void DiamondTrap::whoAmI( void )
{
	std::cout << "DiamondTrap :: My name is " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack ( const std::string &target )
{
	ScavTrap::attack(target);
}

/* ************************************************************************** */