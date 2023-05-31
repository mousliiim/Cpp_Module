/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:47:56 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/31 20:28:46 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* moi = new Character("moi");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	moi->equip(tmp);
	tmp = src->createMateria("cure");
	moi->equip(tmp);

	ICharacter* bob = new Character("bob");
	
	std::cout << std::endl;
	moi->use(0, *bob);
	moi->use(1, *bob);

	moi->unequip(0);
	moi->use(0, *bob);
	moi->use(1, *bob);
	std::cout << std::endl;
	
	delete bob;
	delete moi;
	delete src;

	return 0;
}