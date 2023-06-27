/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:44:20 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/27 02:02:34 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>
# include <cstdlib>
# include <cstring>
# include <climits>

# define T_CHAR 0
# define T_INT 1
# define T_FLOAT 2
# define T_DOUBLE 3
# define T_NAN 4
# define T_INF 5
# define T_ERROR 6
# define SIZE_TAB 7

class ScalarConverter
{
	public:
		ScalarConverter ( void );
		ScalarConverter ( std::string const &str );
		ScalarConverter ( ScalarConverter const &src );
		~ScalarConverter ( void );
		ScalarConverter &operator= (ScalarConverter const &rhs);
		short determineType ( void );
		bool isChar ( void );
		bool isInt ( void );
		bool isDouble ( void );
		bool isFloat ( void );
		
	private:
		std::string _str;
		short		_originalType;
};

#endif
