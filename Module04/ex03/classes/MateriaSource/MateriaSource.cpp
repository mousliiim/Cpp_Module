/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:27:22 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/30 21:06:27 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _nbMateria(0)
{
	for (int i = 0; i < MAX_MATERIA; i++)
		_inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	*this = src;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	if (this != &src)
	{
		for (int i = 0; i < MAX_MATERIA; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			_inventory[i] = src._inventory[i]->clone();
		}
		_nbMateria = src._nbMateria;
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
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
		std::cout << "MateriaSource :: Inventory is full" << std::endl;
		delete m;
		return ;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (_inventory[i] && _inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	return (NULL);
}