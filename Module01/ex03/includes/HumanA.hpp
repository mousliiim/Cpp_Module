/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:33:09 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/09 23:41:18 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>

# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA ( std::string name, Weapon &weapon );
		void attack( void );
	private:
		Weapon& _weapon;
		std::string _name;
};

#endif