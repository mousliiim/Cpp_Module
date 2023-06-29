/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:37:29 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/29 22:21:47 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cstring>
# include <climits>
# include <stdint.h>

typedef struct Data
{
	std::string name;
	int			age;
} Data;

class Serializer
{
	public:
		Serializer ( void );
		~Serializer ( void );
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};

#endif