/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:21:27 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/28 01:50:04 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER
# define CHARACTER

#include "ICharacter.hpp"
#include "AMateria.hpp"

#include <iostream>
#include <string>

class Character : public ICharacter
{
	public:
		Character();
		Character (const std::string &name);
		Character& operator=(const Character& player);
		~Character();

		std::string const &getName() const;
		// void equip(AMateria *m);
		// void unequip(int idx);
		// void use(int idx, ICharacter &target);
	private:
		std::string _name;
};

#endif