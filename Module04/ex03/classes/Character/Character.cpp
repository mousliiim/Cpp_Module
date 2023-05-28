/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:28:04 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/28 01:49:36 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default")
{
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character (const std::string &name) : _name(name)
{
	std::cout << "Character constructor called" << std::endl;
}

// Character::Character(const Character &src)
// {
// 	std::cout << "Character copy constructor called" << std::endl;
// 	this->_name = src._name;
// }

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
}

Character& Character::operator=(const Character& src)
{
	std::cout << "Character assignation operator called" << std::endl;
	(void)src;
	return (*this);
}

std::string const &Character::getName() const
{
	return (_name);
}

