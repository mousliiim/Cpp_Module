/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:39:27 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/05 04:32:43 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define RESET "\033[0m"

# define ZOMBIE_NAME "Zombie"

class Zombie 
{
	public:
		Zombie ( void );
		Zombie( std::string NameOfZombie );
		~Zombie();
		std::string setNameZombie(std::string NameOfZombie);
		void announce ( void );
	private:
		std::string _name;
};

Zombie *newZombie( std::string name );
void randomChump( std::string name );

#endif