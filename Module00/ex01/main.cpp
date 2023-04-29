/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:28:33 by mmourdal          #+#    #+#             */
/*   Updated: 2023/04/29 23:10:39 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/phonebook.hpp"
#include "includes/contact.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;
	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break;
		else if (command == "ADD")
		{
			std::cout << "ADD" << std::endl; // TODO: add contact
			phonebook.add_contact(); // For add a contact
		}
		else if (command == "SEARCH")
		{
			std::cout << "SEARCH" << std::endl; // TODO: search contact
			phonebook.search_contact(); // For find a contact
		}
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}