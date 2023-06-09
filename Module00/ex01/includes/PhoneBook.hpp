/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:29:15 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/03 02:09:01 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contact[MAX_CONTACTS];
		int		_nbContacts;
		int		_index;
	public:
		PhoneBook();
		void PrintContactIndex(int index);
		void AddContact(void);
		void SearchContact(void);
};

#endif