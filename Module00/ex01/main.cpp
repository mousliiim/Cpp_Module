/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:28:33 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/01 01:35:15 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PhoneBook.hpp"

int main(void)
{
	PhoneBook phonebook;
	std::string command;
	while (true)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break;
		else if (command == "ADD")
		{
			std::cout << "ADD" << std::endl; // TODO: add contact
			phonebook.AddContact(); // For add a contact
		}
		else if (command == "SEARCH")
		{
			std::cout << "SEARCH" << std::endl; // TODO: search contact
			// phonebook.search_contact(); // For find a contact
		}
		else if (command == "PRINT")
		{
			std::cout << "PRINT" << std::endl; // TODO: print contact
			// phonebook.print_contact(); // For print a contact
			phonebook.PrintContact();
		}
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}