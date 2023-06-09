/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:35:07 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/27 21:27:37 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "\n↓ BASIC TEST ↓\n\n";
	Animal *first = new Dog();
	Animal *second = new Dog();
	Animal *third = new Cat();
	Animal *fourth = new Cat();
	Animal *animals[4] = {first, second, third, fourth};
	std::string idea[100] = {"Im the first dog", "Kibble", "I love my master"};
	std::string idea2[100] = {"Im the second cat", "Need to eat", "I Want to play with my master"};

	std::cout << "Array of object animals : Dog Dog Cat Cat\n\n";
	for (int i = 0; i < 4; i++)
		animals[i]->makeSound();
	std::cout << "\nBRAIN OF FIRST DOG : \n";
	first->getBrain()->setIdeas(idea);
	first->getBrain()->printIdeas();
	std::cout << "\nBRAIN OF SECOND CAT :\n";
	fourth->getBrain()->setIdeas(idea2);
	fourth->getBrain()->printIdeas();
	
	std::cout << std::endl;

	std::string ideacpytest[100] = {"Test cpy", "Test cpy", "Test cpy"};
	std::cout << "\n↓ TEST DEEP COPY CAT ↓\n\n";
	Dog testcpy;
	testcpy.getBrain()->setIdeas(ideacpytest);
	std::cout << "\nBRAIN OF TESTCPY CAT BEFORE CPY :\n";
	testcpy.getBrain()->printIdeas();
	std::cout << std::endl;
	Dog cpy = testcpy;
	std::cout << "\nBRAIN OF CPY CAT:\n";
	cpy.getBrain()->printIdeas();
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i];
	return 0;
}
