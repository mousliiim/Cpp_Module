/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:02:59 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/24 01:22:53 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::cout << std::endl << "████████████████████████████████████" << std::endl << std::endl;
	/* Start of fight */
	ClapTrap Luffy("Luffy 👒");
	ClapTrap Kaido("Kaido 🐉");
	
	std::cout << std::endl << "████████████████████████████████████" << std::endl << std::endl;

	/* Info before the fight */
	Luffy.setEnergyPoints(3);
	Luffy.setAttackDamage(5);
	Luffy.setHitPoints(10);
	Luffy.getAllInfo();
	std::cout << std::endl;
	Kaido.setEnergyPoints(5);
	Kaido.setAttackDamage(6);
	Kaido.setHitPoints(15);
	Kaido.getAllInfo();
	
	std::cout << std::endl;
	std::cout << "████████████████████████████████████" << std::endl << std::endl;
	
	/* Fight */
	Luffy.attack("Kaido 🐉");
	std::cout << std::endl;
	Kaido.takeDamage(Luffy.getAttackDamage());
	Luffy.getAllInfo();
	std::cout << std::endl;
	Kaido.getAllInfo();
	
	std::cout << std::endl;
	std::cout << "████████████████████████████████████" << std::endl << std::endl;

	/* Test if Kaido 🐉 can attack Luffy 👒 */
	Kaido.attack("Luffy 👒");
	std::cout << std::endl;
	Luffy.takeDamage(Kaido.getAttackDamage());
	Luffy.getAllInfo();
	std::cout << std::endl;
	Kaido.getAllInfo();
	
	std::cout << std::endl;
	std::cout << "████████████████████████████████████" << std::endl << std::endl;
	
	/* Test if Luffy 👒 can attack Kaido 🐉 */
	Luffy.attack("Kaido 🐉");
	Luffy.attack("Kaido 🐉");
	std::cout << std::endl;
	Kaido.takeDamage(Luffy.getAttackDamage() * 2);
	Luffy.getAllInfo();
	std::cout << std::endl;
	Kaido.getAllInfo();
	
	std::cout << std::endl;
	std::cout << "████████████████████████████████████" << std::endl << std::endl;
	
	/* Final test */
	std::cout << "Kaido 🐉 is dead" << std::endl;
	std::cout << std::endl;
	std::cout << "Test if Luffy 👒 can attack Kaido 🐉 :" << std::endl;
	Luffy.attack("Kaido 🐉");
	std::cout << std::endl;
	std::cout << "Test if Kaido 🐉 can repair himself :" << std::endl;
	Kaido.beRepaired(5);
	std::cout << std::endl;
	std::cout << "Test if Kaido 🐉 can attack Luffy 👒 :" << std::endl;
	Kaido.attack("Luffy 👒");
	std::cout << std::endl;
	std::cout << "Test if Luffy 👒 can repair himself :" << std::endl;
	Luffy.beRepaired(5);
	
	std::cout << std::endl;
	std::cout << "████████████████████████████████████" << std::endl << std::endl;

	/* Info after the fight */	
	std::cout << "Info final after the fight :" << std::endl;
	std::cout << std::endl;
	Luffy.getAllInfo();
	std::cout << std::endl;
	Kaido.getAllInfo();
	
	std::cout << std::endl;
	std::cout << "████████████████████████████████████" << std::endl << std::endl;
	return (0);
}