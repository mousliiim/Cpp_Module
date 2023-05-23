/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:03:30 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/23 22:10:49 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"

class ClapTrap
{
	public:
		ClapTrap	( void );
		ClapTrap	( std::string name);
		~ClapTrap	( void );

		ClapTrap		&operator=(const ClapTrap& clap);
		std::string		getName ( void ) const;
		void			setName ( std::string &name );
		unsigned int	getHitPoints ( void ) const;
		void			setHitPoints ( unsigned int hitPoints );
		unsigned int	getEnergyPoints ( void ) const;
		void			setEnergyPoints( unsigned int energyPoints );
		unsigned int	getAttackDamage ( void ) const;
		void			setAttackDamage ( unsigned int attackDamage );
		void 			attack ( const std::string &target );
		void 			takeDamage ( unsigned int amount );
		void 			beRepaired ( unsigned int amount );
		bool 			ifPossible ( void );
		void			getAllInfo ( void );
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif