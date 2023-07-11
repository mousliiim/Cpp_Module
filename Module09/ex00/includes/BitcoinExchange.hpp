/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:15:51 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/11 05:24:07 by mmourdal         ###   ########.fr       */
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

class BitcoinExchange
{
	public:
		BitcoinExchange ( void );
		BitcoinExchange ( char *inputFile );
		BitcoinExchange ( BitcoinExchange const &src);
		BitcoinExchange &operator=( BitcoinExchange const &src);
		~BitcoinExchange ( void );

		void parsingData ( void ) const;
		bool checkDataLine (std::string const &line) const;
		void fillContainer (char *file);

	private:
		char *_inputFile;
		std::map <std::string, double> _mDatePrice;
};

#endif