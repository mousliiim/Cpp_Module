/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:35:07 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/27 02:05:01 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal *first = new Dog();
	Animal *second = new Dog();
	Animal *third = new Cat();
	Animal *fourth = new Cat();
	Animal *animals[4] = {first, second, third, fourth};

	std::cout << std::endl;	
	std::cout << "Array of object animal : Dog Dog Cat Cat\n\n";
	
	first->getBrain()->setIdeas(0, "Its my first idea im the first dog");
	first->getBrain()->setIdeas(1, "Its my second idea im the first dog");
	fourth->getBrain()->setIdeas(0, "Its my first idea im the second cat");
	fourth->getBrain()->setIdeas(30, "Its my second idea im the second cat");
	third->getBrain()->setIdeas(45, "Its my first idea im the first cat");
	for (int i = 0; i < 4; i++)
		animals[i]->makeSound();

	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Animal " << i + 1 << " : ";
		for (int j = 0; j < 100; j++)
		{
			if (animals[i]->getBrain()->getIdeas(j) != "")
				std::cout << animals[i]->getBrain()->getIdeas(j) << " Index idea : " << j;
			if (animals[i]->getBrain()->getIdeas(j) == "")
				continue ;
			std::cout << ", ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	for (int i = 0; i < 4; i++)
		delete animals[i];
	return 0;
}
