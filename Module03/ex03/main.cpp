/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:02:59 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/25 00:49:53 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap Test("Maxou");

	std::cout << std::endl;
	Test.getAllInfo();
	std::cout << std::endl;
	Test.whoAmI();
	Test.attack("Jm");
	
	std::cout << std::endl << "***********************************************************" << std::endl;
	std::cout << "Test if DiamondTrap can use FragTrap and ScavTrap functions" << std::endl;
	std::cout << "***********************************************************" << std::endl << std::endl;
	Test.highFivesGuys();
	Test.guardGate();

	std::cout << std::endl << "***********************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "  Graphical representation of the DiamondTrap class :" << std::endl << std::endl;
	std::cout << "      ┌─────────────────────────┐" << std::endl;
	std::cout << "      │     CLAPTRAP CLASS      │" << std::endl;
	std::cout << "      └───────────┬─────────────┘" << std::endl;
	std::cout << "                  │" << std::endl;
	std::cout << "                  │" << std::endl;
	std::cout << "                  │" << std::endl;
	std::cout << "                  │" << std::endl;
	std::cout << "       ┌──────────┴──────────┐" << std::endl;
	std::cout << "       │                     │" << std::endl;
	std::cout << "┌──────┴──────────┐  ┌───────┴─────────┐" << std::endl;
	std::cout << "│ FlagTrap Class  │  │  ScavTrap Class │" << std::endl;
	std::cout << "└─────┬───────────┘  └─────────┬───────┘" << std::endl;
	std::cout << "      │                        │" << std::endl;
	std::cout << "      │  ┌───────────────────┐ │" << std::endl;
	std::cout << "      └─►│ DiamondTrap Class │◄┘" << std::endl;
	std::cout << "         └───────────────────┘" << std::endl << std::endl << std::endl;
	return (0);
}