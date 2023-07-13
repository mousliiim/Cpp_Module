/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:15:51 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/13 02:11:05 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <vector>
# include <string>
# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <cstdlib>
# include <cstring>
# include <climits>
#include <algorithm>

# define WHITE_B "\033[1;37m"
# define RESET "\033[0m"

# define YEAR 0
# define MONTH 1
# define DAY 2
# define PRICE 3
# define WALLET 3

# define OK 0
# define ERROR_DATE 1
# define ERROR_PRICE 2
# define ERROR_NOT_FOUND 3
# define ERROR_FORMAT 4
# define ERROR_TOO_LARGE 5
# define ERROR_TOO_SMALL 6

class BitcoinExchange
{
	public:
		BitcoinExchange ( void );
		BitcoinExchange ( char *inputFile );
		BitcoinExchange ( BitcoinExchange const &src );
		BitcoinExchange &operator=( BitcoinExchange const &src );
		~BitcoinExchange ( void );

		void	parsingData ( void );
		short	processLine ( std::stringstream &ss, std::string const &line, std::string data[4], bool checkData );
		short	checkDataLine (std::string const &line, bool checkData );
		void	parsingInput ( void );
		void	printResult ( std::string const &line, short display );

	private:
		char *							_inputFile;
		std::map <std::string, double>	_mDatePrice;
		double							_wallet;
};

#endif