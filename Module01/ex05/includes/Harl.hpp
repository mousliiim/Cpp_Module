/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:07:07 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/11 00:23:11 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
	public:
		Harl ( void );
		void complain ( std::string level );
		typedef void (Harl::*ptrHarl)( void );
	private:
		ptrHarl _tabFunc[4];
		std::string _name[4];
		void debug ( void );
		void info ( void );
		void warning ( void );
		void error ( void );
};



#endif