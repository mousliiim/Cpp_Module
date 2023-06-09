/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:28:04 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/31 20:28:12 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default"), _nbMateria(0), _collector(NULL)
{
	std::cout << "Character :: Default constructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++)
		_inventory[i] = NULL;
}

Character::Character (const std::string &name) : _name(name), _nbMateria(0), _collector(NULL)
{
	std::cout << "Character :: Constructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++)
		_inventory[i] = NULL;
	
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	else if (_nbMateria < MAX_MATERIA)
	{
		_inventory[_nbMateria] = m;
		_nbMateria++;
	}
	else
	{
		std::cout << "Character :: " << this->getName() << " Inventory is full" << std::endl;
		delete m;
		return ;
	}
}

Character::Character(const Character &src) : _collector(NULL)
{
	*this = src;
}

Character &Character::operator=(const Character &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_nbMateria = src._nbMateria;
		for (int i = 0; i < MAX_MATERIA; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = src._inventory[i]->clone();
		}
	}
	return (*this);
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
		std::cout << "Character :: " << this->getName() << " item unequiped from slot " << idx << std::endl;
	}
	else if (!_inventory[idx])
		std::cout << "Character :: " << this->getName() << " item is already unequiped from this slot" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 4)
		return ;
	else if (_inventory[idx])
		_inventory[idx]->use(target);
	else if (!_inventory[idx])
		std::cout << "Character :: " << this->getName() << " item is not equiped in this slot" << std::endl;
	else
		std::cout << "Character :: Invalid index" << std::endl;
}

Character::~Character()
{
	std::cout << "Character :: Destructor called" << std::endl;
	_garbage	*tmp;

	tmp = _collector;
	int			i = -1;

	while (_collector)
	{
		tmp = _collector;
		_collector = _collector->next;
		delete tmp->aItem;
		delete tmp;
	}
	_collector = NULL;
	while (++i < 4)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const &Character::getName() const
{
	return (_name);
}

