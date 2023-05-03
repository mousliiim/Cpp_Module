/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:29:34 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/02 23:02:23 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

#define MAX_CONTACTS 8

class Contact
{
	private:
		std::string _FirstName;
		std::string _LastName;
		std::string _NickName;
		std::string	_PhoneNumber;
		std::string	_DarkestSecret;
		int			_ContactIndex;
	public:
		Contact();
		void MakeContact(std::string f_name, std::string l_name, std::string nick, std::string phone, std::string secret, int index);
		std::string	GetFirstName(void);
		std::string GetLastName(void);
		std::string GetNickName(void);
		std::string GetPhoneNumber(void);
		std::string GetDarkestSecret(void);
		const int& GetIndex(void) const;
};

#endif