/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:22:15 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/24 21:21:22 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* CONSTRUCTOR AND DESTRUCTOR */

ClapTrap::ClapTrap	( void ) : _name("Default name"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap :: Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap ( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap :: Constructor Called" << std::endl;

}

ClapTrap::ClapTrap ( const ClapTrap &src )
{
	this->_attackDamage = src._attackDamage;
	this->_energyPoints = src._energyPoints;
	this->_hitPoints = src._hitPoints;
	this->_name = src._name;
	std::cout << "ClapTrap :: Copy Constructor Called" << std::endl;
}

ClapTrap::~ClapTrap ( void )
{
	std::cout << "ClapTrap :: Destructor Called" << std::endl;
}

/* GETTER */

std::string ClapTrap::getName ( void ) const
{
	return (this->_name);
}

int ClapTrap::getHitPoints ( void ) const 
{
	return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints ( void ) const 
{
	return (this->_energyPoints);
}

int ClapTrap::getAttackDamage ( void ) const 
{
	return (this->_attackDamage);
}

/* SETTER */

void ClapTrap::setName ( std::string &name )
{
	this->_name = name;
}

void ClapTrap::setHitPoints ( int hitPoints )
{
	if (this->ifPossible())
		this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints ( int energyPoints )
{
	if (this->ifPossible())
		this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage ( int attackDamage )
{
	if (this->ifPossible())
		this->_attackDamage = attackDamage;
}

void ClapTrap::getAllInfo ( void )
{
	std::cout << "Name : " << this->_name << std::endl;
	std::cout << "HitPoints : " << this->_hitPoints << std::endl;
	std::cout << "EnergyPoints : " << this->_energyPoints << std::endl;
	std::cout << "AttackDamage : " << this->_attackDamage << std::endl;
}

/* METHOD IN CLASS */

ClapTrap &ClapTrap::operator= ( ClapTrap const &rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
		std::cout << "ClapTrap :: Assignement constructor Called" << std::endl;
	}
	return (*this);
}

bool ClapTrap::ifPossible( void )
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
	{
		std::cout << _name << " : I don't have enough energy or hit." << std::endl;
		return (false);
	}
	return (true);
}

void ClapTrap::attack ( const std::string& target )
{
	if (this->ifPossible())
	{
		std::cout << "ClapTrap : " << this->_name << " attacks " << target << ", " "causing " << this->getAttackDamage()  << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void ClapTrap::takeDamage (int amount)
{
	this->_hitPoints = (this->_hitPoints - amount < 0) ? 0 : this->_hitPoints - amount;
	std::cout << "ClapTrap : " << this->_name << " take " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired (int amount)
{
	if (this->ifPossible())
	{
		std::cout << "ClapTrap : " << this->_name << " be repaired of " << amount << " points of damage!" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
}
