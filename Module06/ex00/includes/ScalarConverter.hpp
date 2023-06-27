/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:44:20 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/27 20:47:59 by mmourdal         ###   ########.fr       */
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

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3
# define NAN 4
# define INF 5
# define IMPOSSIBLE 6
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
		void convert ( std::string const &literal );
		void convertChar ( void );
		void convertInt ( void );
		void convertFloat ( void );
		void convertDouble ( void );
		
	private:
		std::string _str;
		short		_originalType;
};

#endif
