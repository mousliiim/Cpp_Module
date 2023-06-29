/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:37:03 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/29 21:46:19 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer ( void ) { }

Serializer::~Serializer ( void ) { }

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t value = reinterpret_cast <uintptr_t>(ptr);
	return value;	
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *p = reinterpret_cast <Data *>(raw);
	return p;
}