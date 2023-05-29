/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:28:04 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/29 23:10:59 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default"), _nbMateria(0), _collector(NULL)
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 5; i++)
		_inventory[i] = NULL;
}

Character::Character (const std::string &name) : _name(name), _nbMateria(0), _collector(NULL)
{
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 5; i++)
		_inventory[i] = NULL;
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	else if (_nbMateria < 4)
	{
		_inventory[_nbMateria] = m;
		_nbMateria++;
	}
	else
	{
		std::cout << "Character :: Inventory is full" << std::endl;
		delete m;
		return ;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 4)
		return ;
	else if (_inventory[idx])
	{
		if (_collector)
		{
			_garbage *tmp = _collector;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new _garbage;
			tmp->next->aItem = _inventory[idx];
			tmp->next->next = NULL;
		}
		else
		{
			_collector = new _garbage;
			_collector->aItem = _inventory[idx];
			_collector->next = NULL;
		}
		_inventory[idx] = NULL;
		_nbMateria--;
	}
	else if (!_inventory[idx])
		std::cout << "Character :: Inventory is empty" << std::endl;
	else
		std::cout << "Character :: Invalid index" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 4)
		return ;
	else if (_inventory[idx])
		_inventory[idx]->use(target);
	else if (!_inventory[idx])
		std::cout << "Character :: Inventory is empty" << std::endl;
	else
		std::cout << "Character :: Invalid index" << std::endl;
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

