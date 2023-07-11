/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 02:43:41 by mmourdal          #+#    #+#             */
/*   Updated: 2023/07/11 06:13:34 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange ( void ) { }

BitcoinExchange::BitcoinExchange ( char *inputFile )
{
	_inputFile = inputFile;
	parsingData();
}

BitcoinExchange::BitcoinExchange ( BitcoinExchange const &src )
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator= ( BitcoinExchange const &src)
{
	if (this != &src)
	{
		(void)src;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange ( void ) { }

void BitcoinExchange::parsingData ( void ) const
{
	std::ifstream data("files/data.csv");
	std::string line;

	if (!data.is_open())
		throw std::invalid_argument(WHITE_B "Error :: " RESET "Can't open file");
	std::getline(data, line);
	line == "date,exchange_rate" ? true : throw std::invalid_argument(WHITE_B "Error :: " RESET "Wrong file format of csv");
	while (std::getline(data, line))
	{
		checkDataLine(line) ? true : throw std::invalid_argument(WHITE_B "Error :: " RESET "Wrong file format of csv");
	}
}

bool  BitcoinExchange::checkDataLine (std::string const &line) const
{
	std::string data[4];
	std::stringstream ss(line);

	std::getline(ss, data[0], '-');
	std::getline(ss, data[1], '-');
	std::getline(ss, data[2], ',');
	if (data[0].size() != 4 || data[1].size() != 2 || data[2].size() != 2 || data[0].empty() || data[1].empty() || data[2].empty())
		return false;
	for (int i = 0; i < 3; i++)
	{
		if (data[i].find_first_not_of("0123456789") != std::string::npos)
			return false;
		if (i == 0 && (std::atol(data[i].c_str()) < 2009 || std::atol(data[i].c_str()) > 2023))
			return false;
		if (i == 1 && (std::atol(data[i].c_str()) < 1 || std::atol(data[i].c_str()) > 12))
			return false;
		if (i == 2 && (std::atol(data[i].c_str()) < 1 || std::atol(data[i].c_str()) > 31))
			return false;
	}
	ss >> data[3];
	if (ss.fail() || !ss.eof())
		return false;
	if (data[3].find_first_not_of("0123456789.") != std::string::npos || data[3].empty() || std::atof(data[3].c_str()) < 0)
		return false;
	return true;
}