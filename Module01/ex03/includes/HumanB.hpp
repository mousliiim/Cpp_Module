/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:33:35 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/09 23:30:27 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>

# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB ( std::string name );
		void attack( void );
		void setWeapon(Weapon &weapon);
	private:
		Weapon *_weapon;
		std::string _name;
};

#endif