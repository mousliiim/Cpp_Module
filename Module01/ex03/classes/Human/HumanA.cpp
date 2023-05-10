/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:24:23 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/09 23:44:16 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA ( std::string name, Weapon &weapon ) : _weapon(weapon), _name(name) {}

void HumanA::attack( void )
{
	std::cout << this->_name << " attacks with their " << _weapon.getType() << std::endl;
}