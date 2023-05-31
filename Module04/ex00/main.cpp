/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:35:07 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/31 20:29:25 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* Default = new ( std::nothrow ) Animal();
    const Animal* DogTest = new ( std::nothrow ) Dog();
    const WrongAnimal* DefaultW = new ( std::nothrow ) WrongAnimal();
    const WrongAnimal* WrongCatTest = new ( std::nothrow ) WrongCat();

	std::cout << std::endl << "*************** Real Animal ***************" << std::endl << std::endl;
	std::cout << "Method in Animal is virtual so it's polymorphic" << std::endl;
	std::cout << "Animal go to search in the Dog class if the method it's overriden or not" << std::endl << std::endl;
	std::cout << "Default Animal type: " << Default->getType() << std::endl;
	std::cout << "Dog Animal type: " << DogTest->getType() << std::endl;
	std::cout << "Default Animal sound: " << std::endl;
	Default->makeSound();
	std::cout << "Dog Animal sound: " << std::endl;
	DogTest->makeSound();
	std::cout << std::endl << "********************************************" << std::endl << std::endl;
	std::cout << "*************** Wrong Animal ***************" << std::endl << std::endl;
	std::cout << "Method in WrongAnimal is not virtual so it's not polymorphic" << std::endl;
	std::cout << "WrongAnimal don't go to search in the WrongCat class if the method is overriden or not" << std::endl << std::endl;
	std::cout << "Default Animal type: " << DefaultW->getType() << std::endl;
	std::cout << "WrongCat Animal type: " << WrongCatTest->getType() << std::endl;
	std::cout << "Default WrongAnimal sound: " << std::endl;
	DefaultW->makeSound();
	std::cout << "WrongCatTest Animal sound: " << std::endl;
	WrongCatTest->makeSound();
	std::cout << std::endl << "********************************************" << std::endl << std::endl;

	delete Default;
	delete DogTest;
	delete DefaultW;
	delete WrongCatTest;
}
