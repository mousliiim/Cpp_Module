/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:47:48 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/05 04:34:11 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie () : _name (ZOMBIE_NAME) {}

Zombie::~Zombie() 
{
	std::cout << this->_name << " is DEAD ! 💀" << std::endl;
}

void randomChump( std::string name )
{
	Zombie zombie;
	zombie.setNameZombie(name);
	zombie.announce();
}

Zombie *newZombie( std::string name )
{
	Zombie *zombie = new Zombie;
	zombie->setNameZombie(name);
	return (zombie);
}

std::string Zombie::setNameZombie(std::string NameOfZombie)
{
	return (this->_name = NameOfZombie);
}

void Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}