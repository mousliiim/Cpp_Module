/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:35:07 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/26 21:19:33 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* j = new Dog ();
	const Animal* i = new Cat ();
	// Animal* test = new Animal ("Mouss");
	// Animal* popo = new Animal ();
	
	// std::cout << test->getType() << std::endl;
	// popo = test;
	// std::cout << test->getType() << std::endl;
	delete j;
	delete i;

	return 0;
}
