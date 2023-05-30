/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:27:22 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/30 09:32:21 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// • learnMateria(AMateria*)
// Copie la Materia passée en paramètre et la stocke en mémoire afin de la cloner
// plus tard. Tout comme le Character, la MateriaSource peut contenir 4 Materias
// maximum. Ces dernières ne sont pas forcément uniques.
// • createMateria(std::string const &)
// Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédemment par la MateriaSource et dont le type est le même que celui passé en paramètre. Retourne 0 si le type est inconnu.
// En bref, votre MateriaSource doit pouvoir apprendre des "modèles" de Materias
// afin de les recréer à volonté. Ainsi, vous serez capable de générer une nouvelle Materia à
// partir de son type sous forme de chaîne de caractères

MateriaSource::MateriaSource() : _nbMateria(0)
{
	for (int i = 0; i < MAX_MATERIA; i++)
		_inventory[i] = NULL;
}

// MateriaSource::MateriaSource(const MateriaSource& rhs)
// {
// 	*this = rhs;
// }

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

// MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
// {
// 	if (this != &rhs)
// 	{
// 		for (int i = 0; i < MAX_MATERIA; i++)
// 		{
// 			if (_inventory[i])
// 				delete _inventory[i];
// 			_inventory[i] = rhs._inventory[i]->clone();
// 		}
// 		_nbMateria = rhs._nbMateria;
// 	}
// 	return (*this);
// }

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