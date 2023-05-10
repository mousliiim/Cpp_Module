/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:47:23 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/09 23:38:02 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon ( std::string type )
{
	this->_type = type;
}

const std::string &Weapon::getType ( void )
{
	return (this->_type);
}

void Weapon::setType ( std::string newType )
{
	this->_type = newType;
}
