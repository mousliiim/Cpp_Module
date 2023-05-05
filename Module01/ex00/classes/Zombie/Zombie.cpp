/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:49:23 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/05 04:32:59 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie () : _name (ZOMBIE_NAME) {}

Zombie::Zombie( std::string NameOfZombie )
{
	this->_name = NameOfZombie;
}

void Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::setNameZombie(std::string NameOfZombie)
{
	return (this->_name = NameOfZombie);
}

Zombie::~Zombie() 
{
	std::cout << this->_name << " is DEAD ! 💀" << std::endl;
}