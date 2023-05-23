/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:03:30 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/24 01:27:20 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>

class ClapTrap
{
	public:
		ClapTrap	( void );
		ClapTrap	( std::string name);
		~ClapTrap	( void );
		ClapTrap	&operator=(const ClapTrap& clap);
		
		std::string	getName ( void ) const;
		void		setName ( std::string &name );
		int			getHitPoints ( void ) const;
		void		setHitPoints ( int hitPoints );
		int			getEnergyPoints ( void ) const;
		void		setEnergyPoints( int energyPoints );
		int			getAttackDamage ( void ) const;
		void		setAttackDamage ( int attackDamage );
		void 		attack ( const std::string &target );
		void 		takeDamage ( int amount );
		void 		beRepaired ( int amount );
		bool 		ifPossible ( void );
		void		getAllInfo ( void );
	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

#endif