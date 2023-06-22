/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:44:20 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/22 19:45:57 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>

class ScalarConverter
{
	public:
		ScalarConverter ( void );
		ScalarConverter ( std::string const &str );
		ScalarConverter ( ScalarConverter const &src );
		~ScalarConverter ( void );
		ScalarConverter &operator= (ScalarConverter const &rhs);
		
	private:
		char 	_char;
		int 	_int;
		float 	_float;
		double 	_double;
};

#endif
