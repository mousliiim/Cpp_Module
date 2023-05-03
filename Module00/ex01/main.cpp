/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:28:33 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/03 02:08:53 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Main.hpp"

void StringToUpper(std::string &str)
{
	for (int i = 0; str[i]; i++)
		str[i] = std::toupper(str[i]);
}

int main(void)
{
	PhoneBook phonebook;
	std::string command;
	PrintProgramStart();
	while (true)
	{
		std::cout << WHITE << "$PhoneBook ✗ " << RESET;
		std::getline(std::cin, command);
		StringToUpper(command);
		if (command == "EXIT" || std::cin.eof())
			return (std::cout << WHITE << "\nGoodbye ! 👋" << RESET << std::endl, 0);
		else if (command == "ADD")
			phonebook.AddContact();
		else if (command == "SEARCH")
			phonebook.SearchContact();
		else if (IsEmpty(command))
			continue;
		else
			 std::cout << "\"" << command << "\"" <<" is invalid command in PhoneBook programm" << std::endl;
	}
	return (0);
}