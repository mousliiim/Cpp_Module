/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:48:10 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/05 04:33:38 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

# define WHITE "\033[1;37m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

# define ZOMBIE_NAME "Zombie"

class Zombie 
{
	public:
		Zombie ( void );
		~Zombie ( void );
		Zombie ( std::string NameOfZombie );
		std::string setNameZombie(std::string NameOfZombie);
		void announce ( void );
	private:
		std::string _name;
};

Zombie *newZombie( std::string name );
void randomChump( std::string name );
Zombie* zombieHorde( int N, std::string name );

#endif