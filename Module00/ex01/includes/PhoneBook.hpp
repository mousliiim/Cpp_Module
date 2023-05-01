/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousspc <mousspc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:29:15 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/01 22:27:26 by mousspc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contact[MAX_CONTACTS];
		int		_nbContacts;
		int		_index;
	public:
		void PrintContact(void);
		void AddContact(void);
		void SearchContact(void);
};

bool IsEmpty(std::string);

#endif