/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:02:59 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/24 21:13:46 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << std::endl;
	ScavTrap Maxou("Maxou");
	ClapTrap Jm("Jean-Marc");
	Jm.setAttackDamage(25);
	std::cout << std::endl << "********* MAXOU SCAVTRAP *********" << std::endl << std::endl;
	Maxou.getAllInfo();
	std::cout << std::endl << "**********************************" << std::endl << std::endl;
	std::cout << "*********** JM CLAPTRAP **********" << std::endl << std::endl;
	Jm.getAllInfo();
	std::cout << std::endl << "**********************************" << std::endl << std::endl;
	std::cout << std::endl << "******** 🥊 FIGHT LOG 🥊 *********" << std::endl << std::endl;
	Jm.attack("Maxou");
	Maxou.attack("Jean-Marc");
	Maxou.guardGate();
	Jm.takeDamage(Maxou.getAttackDamage());
	Maxou.takeDamage(Jm.getAttackDamage());
	std::cout << "Jean-Marc is dead 💀" << std::endl;
	std::cout << "Maxou win the fight 🏆" << std::endl;
	std::cout << std::endl << "**********************************" << std::endl << std::endl;
	std::cout << "***** 🥊 LOG AFTER FIGHT 🥊 ******" << std::endl << std::endl;
	Maxou.getAllInfo();
	std::cout << std::endl;
	Jm.getAllInfo();
	std::cout << std::endl << "**********************************" << std::endl << std::endl;
	return (0);
}