/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:30:09 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/01 02:11:49 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/PhoneBook.hpp"

bool IsEmpty(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isspace(str[i]))
			return (false);
	}
	return (true);
}

// TEST PRINT CONTACT
void PhoneBook::PrintContact(void)
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Print all contact of PhoneBook" << std::endl;
	std::cout << "Number of contact: " << _nbContacts << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < _nbContacts; i++)
	{
		std::cout << "First name: " << _contact[i].GetFirstName() << std::endl;
		std::cout << "Last name: " << _contact[i].GetLastName() << std::endl;
		std::cout << "Nickname: " << _contact[i].GetNickName() << std::endl;
		std::cout << "Phone number: " << _contact[i].GetPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << _contact[i].GetDarkestSecret() << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
}
void PhoneBook::AddContact(void)
{
	std::string first_name;
	std::string last_name;
	std::string nick;
	std::string phone;
	std::string secret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);
	while (IsEmpty(first_name))
	{
		std::cout << "First name can't be empty" << std::endl;
		std::cout << "Enter first name: ";
		std::getline(std::cin, first_name);
	}
	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);
	while (IsEmpty(last_name))
	{
		std::cout << "Last name can't be empty" << std::endl;
		std::cout << "Enter last name: ";
		std::getline(std::cin, last_name);
	}
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nick);
	while (IsEmpty(nick))
	{
		std::cout << "Nickname can't be empty" << std::endl;
		std::cout << "Enter nickname: ";
		std::getline(std::cin, nick);
	}
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone);
	while (IsEmpty(phone))
	{
		std::cout << "Phone number can't be empty" << std::endl;
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phone);
	}
	std::cout << "Enter a Darkest Secret: ";
	std::getline(std::cin, secret);
	while (IsEmpty(secret))
	{
		std::cout << "Darkest Secret can't be empty" << std::endl;
		std::cout << "Enter a secret: ";
		std::getline(std::cin, secret);
	}
	if (this->_nbContacts == MAX_CONTACTS)
		this->_nbContacts = 0;
	this->_contact[this->_nbContacts].MakeContact(first_name, last_name, nick, phone, secret);
	this->_nbContacts++;
}