/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:30:31 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/03 02:03:42 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::GetFirstName()
{
	return (this->_FirstName);
}

std::string Contact::GetLastName()
{
	return (this->_LastName);
}

std::string Contact::GetNickName()
{
	return (this->_NickName);
}

std::string Contact::GetPhoneNumber()
{
	return (this->_PhoneNumber);
}

std::string Contact::GetDarkestSecret()
{
	return (this->_DarkestSecret);
}

const int& Contact::GetIndex(void) const
{
	return(this->_ContactIndex);
}

Contact::Contact():_ContactIndex(0) {};

void Contact::MakeContact(std::string first_name, std::string last_name, std::string nick, std::string phone, std::string secret, int index)
{
	this->_FirstName = first_name;
	this->_LastName = last_name;
	this->_NickName = nick;
	this->_PhoneNumber = phone;
	this->_DarkestSecret = secret;
	this->_ContactIndex = index;
}