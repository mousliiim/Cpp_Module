/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:22:15 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/23 22:32:01 by mmourdal         ###   ########.fr       */
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

unsigned int ClapTrap::getHitPoints ( void ) const 
{
	return (this->_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints ( void ) const 
{
	return (this->_energyPoints);
}

unsigned int ClapTrap::getAttackDamage ( void ) const 
{
	return (this->_attackDamage);
}

/* SETTER */

void ClapTrap::setName ( std::string &name )
{
	this->_name = name;
}

void ClapTrap::setHitPoints ( unsigned int hitPoints )
{
	if (this->ifPossible())
		this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints ( unsigned int energyPoints )
{
	if (this->ifPossible())
		this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage ( unsigned int attackDamage )
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

ClapTrap	&ClapTrap::operator= (const ClapTrap &clap)
{
	this->_name = clap.getName();
	this->_hitPoints = clap.getHitPoints();
	this->_energyPoints = clap.getEnergyPoints();
	this->_attackDamage = clap.getAttackDamage();
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
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", " "causing " << this->getAttackDamage()  << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage (unsigned int amount)
{
	if (this->ifPossible())
		std::cout << "ClapTrap " << this->_name << " take " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired (unsigned int amount)
{
	if (this->ifPossible())
		std::cout << "ClapTrap " << this->_name << " be repaired of " << amount << " points of damage!" << std::endl;
}
