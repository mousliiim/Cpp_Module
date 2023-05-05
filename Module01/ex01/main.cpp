/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:47:54 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/05 04:23:47 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	int NbZombie[2] = {10, 5};
	int i;
	
	std::cout << std::endl << GREEN << "████████████████████████████████████████████████████████" << RESET << std::endl << std::endl;
	std::cout << WHITE << "      🧟 Welcome to the Zombie Horde 🧟" << RESET << std::endl;
	std::cout << WHITE << "🧟 Beware, a first horde of " << NbZombie[0] << " zombies is coming 🧟" << RESET << std::endl << std::endl;
	Zombie *zombie = zombieHorde(NbZombie[0], "mouss");
	for (i = 0; i < NbZombie[0]; i++)
	{
		std::cout << "Zombie Number [" << i << "] come -> ";
		zombie[i].announce();
	}
	std::cout << std::endl;
	delete [] zombie;
	std::cout << std::endl << WHITE << "      🧟 The Zombie Horde is dead 🧟" << RESET << std::endl << std::endl;
	std::cout << GREEN << "████████████████████████████████████████████████████████" << RESET << std::endl << std::endl << std::endl;
	
	std::cout << GREEN << "████████████████████████████████████████████████████████" << RESET << std::endl << std::endl;
	std::cout << WHITE << "🧟 Beware, a second horde of " << NbZombie[1] << " zombies is coming 🧟" << RESET << std::endl << std::endl;
	zombie = zombieHorde(NbZombie[1], "mouss");
	for (i = 0; i < NbZombie[1]; i++)
	{
		std::cout << "Zombie Number [" << i << "] come -> ";
		zombie[i].announce();
	}
	std::cout << std::endl;
	delete [] zombie;
	std::cout << std::endl << WHITE << "      🧟 The Zombie Horde is dead 🧟" << RESET << std::endl;
	std::cout << std::endl << GREEN << "████████████████████████████████████████████████████████" << RESET << std::endl << std::endl;
	return (0);
}