/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:07:07 by mmourdal          #+#    #+#             */
/*   Updated: 2023/05/11 18:48:16 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>
# include <cctype>

# define RED "\033[1;31m"
# define RESET "\033[0m"

class Harl
{
	public:
		Harl ( void );
		void displayLevel ( void );
		void setLevel ( std::string level );
		std::string getLevel ( void );
		typedef void (Harl::*ptrHarl)( void );
	private:
		int _level;
		ptrHarl _tabFunc[4];
		std::string _name[4];
		void debug ( void );
		void info ( void );
		void warning ( void );
		void error ( void );
};

#endif