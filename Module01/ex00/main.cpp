/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:39:02 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/04 21:45:42 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *test = newZombie("Tas");
	test->announce();
	delete test;
	randomChump("Pile");
	Zombie foo("Constructeur");
	foo.announce();
}