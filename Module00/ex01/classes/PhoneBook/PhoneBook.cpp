/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:30:09 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/03 18:22:35 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Main.hpp"
#include <cctype>

PhoneBook::PhoneBook() : _nbContacts(0), _index(0) {};

void PhoneBook::PrintContactIndex(int index)
{
	std::cout << WHITE << "\nFirst name: " << RESET << _contact[index].GetFirstName() << std::endl;
	std::cout << WHITE << "Last name: " << RESET << _contact[index].GetLastName() << std::endl;
	std::cout << WHITE << "Nickname: " << RESET << _contact[index].GetNickName() << std::endl;
	std::cout << WHITE << "Phone number: " << RESET << _contact[index].GetPhoneNumber() << std::endl;
	std::cout << WHITE << "Darkest secret: " << RESET << _contact[index].GetDarkestSecret() << std::endl << std::endl;
}

void PhoneBook::AddContact(void)
{
	std::string first_name;
	std::string last_name;
	std::string nick;
	std::string phone;
	std::string secret;
	static int	index = 0;

	first_name = TakeInfo("First Name", "ALPHA");
	last_name = TakeInfo("Last Name", "ALPHA");
	nick = TakeInfo("Nickname", "TWO");
	phone = TakeInfo("Phone Number", "DIGIT");
	secret = TakeInfo("Darkest Secret", "TWO");
	if (this->_nbContacts == MAX_CONTACTS)
	{
		this->_index = index;
		index++;
		this->_nbContacts--;
	}
	if (index == MAX_CONTACTS)
		index = 0;
	this->_contact[this->_index].MakeContact(first_name, last_name, nick, phone, secret, this->_index);
	this->_nbContacts++;
	this->_index++;
}

void PhoneBook::SearchContact(void)
{
	std::string input;

	if (!this->_nbContacts)
		return (std::cout << "PhoneBook is empty" << std::endl, void());
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < this->_nbContacts; i++)
	{
		std::cout << std::setw(10) << this->_contact[i].GetIndex() << "|";
		if (this->_contact[i].GetFirstName().length() > 10)
			std::cout << this->_contact[i].GetFirstName().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << this->_contact[i].GetFirstName() << "|";
		if (this->_contact[i].GetLastName().length() > 10)
			std::cout << this->_contact[i].GetLastName().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << this->_contact[i].GetLastName() << "|";
		if (this->_contact[i].GetNickName().length() > 10)
			std::cout << this->_contact[i].GetNickName().substr(0, 9) << ".|" << std::endl;
		else
			std::cout << std::setw(10) << this->_contact[i].GetNickName() << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Enter index of a contact: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << WHITE << "\nGoodbye ! 👋" << RESET << std::endl;
		exit (0);
	}
	while (IsEmpty(input) || !CheckIfDigit(input))
	{
		if (IsEmpty(input))
			std::cout << "Input can't be empty" << std::endl;
		else
			std::cout << "Input must be a postive integer" << std::endl;
		std::cout << "Enter index of a contact: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << WHITE << "\n\nGoodbye ! 👋" << RESET << std::endl;
			exit(0);
		}
	}
	if (CheckIfDigit(input))
	{
		if (atoi(input.c_str()) < this->_nbContacts)
			PrintContactIndex(atoi(input.c_str()));
		else
			std::cout << std::endl << "Contact [" << atoi(input.c_str()) << "] doesn't exist" << std::endl << std::endl;
	}
}