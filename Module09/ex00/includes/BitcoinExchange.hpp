/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:15:51 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/11 18:30:22 by mmourdal         ###   ########.fr       */
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

# define WHITE_B "\033[1;37m"
# define RED_B "\033[1;31m"
# define YELLOW_B "\033[1;33m"
# define RESET "\033[0m"

# define YEAR 0
# define MONTH 1
# define DAY 2
# define PRICE 3

# define OK 0
# define ERROR_DATE 1
# define ERROR_PRICE 2
# define ERROR_NOT_FOUND 3

class BitcoinExchange
{
	public:
		BitcoinExchange ( void );
		BitcoinExchange ( char *inputFile );
		BitcoinExchange ( BitcoinExchange const &src);
		BitcoinExchange &operator=( BitcoinExchange const &src);
		~BitcoinExchange ( void );

		void	parsingData ( void );
		bool	checkDataLine (std::string const &line);
		short	checkDataInput (std::string const &line);
		void	parsingInput ( void );
		void	printResult ( std::string const &line, short display );

	private:
		char *_inputFile;
		std::map <std::string, double> _mDatePrice;
};

#endif

/*
day = 30;
if (mois % 2 && mois < 8) // 1, 3, 5, 7,
	day = 31;
else if (mois % 2 == 0 && mois > 8) // 9, 11
	day = 30;

day = 31;
if (mois < 8)
{
	day = (mois % 2 == 0 ? 30 : 31);
}

2012 = FEVRIER FINI PAR 29
2013 = FEVRIER FINI PAR 28
2014 = FEVRIER FINI PAR 28
2015 = FEVRIER FINI PAR 28
2016 = FEVRIER FINI PAR 29

1 jan 31
2 fev 28 29
3 mars 31
4 avril 30
5 mai 31
6 juin 30
7 jui 31
8 aout 31
9 sept 30
10 oct 31
11 nov 30
12 dec 31

les mois qui finissent par 31
1 3 5 7 8 10 12
*/